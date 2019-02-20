#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "evalexpr.h"

int	parse_number(char **expr)
{
	int nbr;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		nbr = parse_sum(expr);
		if (**expr == ')')
			(*expr)++;
		return (nbr);
	}
	return (atoi(*expr));
}

int	parse_factors(char **expr)
{
	int	nbr;
	int	nbr2;
	char op;

	nbr = parse_number(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '/' && op != '*' && op != '%')
			return (nbr);
		(*expr)++;
		nbr2 = parse_number(expr);
		if (op == '/')
			nbr /= nbr2;
		else if (op == '*')
			nbr *= nbr2;
		else
			nbr %= nbr2;
	}
	return (nbr);
}

int	parse_sum(char **expr)
{
	int	nbr;
	int	nbr2;
	char op;

	nbr = parse_factors(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op != '-')
			return (nbr);
		(*expr)++;
		nbr2 = parse_factors(expr);
		if (op == '+')
			nbr += nbr2;
		else
			nbr -= nbr2;
	}
	return (nbr);
}

int	eval_expr(char *expr)
{
	return (parse_sum(&expr));
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		putchar('-');
		ft_putnbr(-nb);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		putchar(nb + '0');
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putnbr(eval_expr(argv[1]));
		putchar('\n');
	}
	return (0);
}
