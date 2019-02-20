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

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("%d", eval_expr(argv[1]));
		putchar('\n');
	}
	return (0);
}
