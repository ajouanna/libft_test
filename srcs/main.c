#include "libft.h"

void print_result(int val, char *res)
{
	ft_putstr("Valeur saisie : ");
	ft_putnbr(val);
	ft_putchar('\n');
	ft_putstr("Resultat du ft_itoa : ");
	ft_putstr(res);
	ft_putchar('\n');
}

int	main(int argc, char ** argv)
{
	int val;
	char *res;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : test nombre\n", 2);
		return (1);
	}
	ft_putstr("Testing ft_itoa\n");
	val = atoi(argv[1]);
	res = ft_itoa(val);
	print_result(val, res);

	val = -0;
	res = ft_itoa(val);
	print_result(val, res);

	val = -156;
	res = ft_itoa(val);
	print_result(val, res);

	return (0);
}
