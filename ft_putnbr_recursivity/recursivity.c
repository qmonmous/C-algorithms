#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putnbr(int nb)
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
	if (argc > 0)
	{
		ft_putnbr(argv[1]);
		putchar('\n');
	}
	return (0);
}