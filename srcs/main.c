#include <string.h>
#include <stdio.h>
#include "libft.h"
#include "tests.h"


void print_binary_string(char *s, int n)
{
	int i;

	if (s == NULL)
	{
		printf("print_binary_string : chaine NULL\n");
		return;
	}
	i = 0;
	while (i < n)
	{
		printf("[%02d]", s[i]);
		i++;
	}
	printf("\n");
}

void test_ft_memcpy()
{
	char *s1 = "11111";
	char *s2;

	printf("%s\n", BANNER);
	printf("Test de ft_memcpy\n");	
	s2 = malloc(sizeof(char) * 10);
	ft_strcpy(s2, "222222");

	printf("s2 avant ft_memcpy : %s\n",s2);
	ft_memcpy(s2, s1, 3);
	printf("s2 apres ft_memcpy : %s\n",s2);
}

/*
 ** must test the return code
*/

void test_ft_memccpy()
{
	char *s1 = "111111";
	char *s2;
	char *res;

	printf("%s\n", BANNER);
	printf("Test de ft_memccpy\n");	
	s2 = malloc(sizeof(char) * 10);
	ft_strcpy(s2, "222222");

	printf("s2 avant ft_memccpy :\n");
	print_binary_string(s2, 10);
	res = ft_memccpy(s2, s1 ,'0', 5);
	printf("s2 apres ft_memccpy :\n");
	print_binary_string(s2, 10);
	printf("res apres ft_memccpy :\n");
	print_binary_string(res, 10);
}
	
void test_ft_strncpy()
{
	char *s1 = "11111";
	char *s2;

	printf("%s\n", BANNER);
	printf("Test de ft_strncpy\n");	
	s2 = malloc(sizeof(char) * 10);
	ft_strcpy(s2, "222222");

	printf("s2 avant ft_strncpy : %s\n",s2);
	ft_strncpy(s2, s1, 3);
	printf("s2 apres ft_strncpy : %s\n",s2);
}

void test_ft_bzero()
{
	char *s;
	int n;

	printf("%s\n", BANNER);
	printf("Test de ft_bzero\n");	

	s = malloc(sizeof(char) * 11);
	if (s)
	{
		strcpy(s, "0123456789");
		n = 5;
		printf("avant bzero : %s\n", s);	
		print_binary_string(s, 11);
		bzero(s, n);
		printf("apres bzero avec la longueur %d\n", n);	
		print_binary_string(s, 11);
		strcpy(s, "0123456789");
		n = 5;
		printf("avant ft_bzero : %s\n", s);	
		print_binary_string(s, 11);
		ft_bzero(s, n);
		printf("apres ft_bzero avec la longueur %d\n", n);	
		print_binary_string(s, 11);
	}
}

void print_result(int val, char *res)
{
	ft_putstr("Valeur saisie : ");
	ft_putnbr(val);
	ft_putchar('\n');
	ft_putstr("Resultat du ft_itoa : ");
	ft_putstr(res);
	ft_putchar('\n');
}

void	test_ft_itoa()
{
	int val;
	char *res;

	printf("%s\n", BANNER);
	ft_putstr("Testing ft_itoa\n");
	val = -0;
	res = ft_itoa(val);
	print_result(val, res);

	val = -156;
	res = ft_itoa(val);
	print_result(val, res);

	val = 5678;
	res = ft_itoa(val);
	print_result(val, res);
}

void test_ft_memset()
{
	char *s;
	char c;
	int n;

	printf("%s\n", BANNER);
	printf("Test de ft_memset\n");	

	s = malloc(sizeof(char) * 11);
	if (s)
	{
		strcpy(s, "0123456789");
		c = '*';
		n = 3;
		printf("avant memset : %s\n", s);	
		memset(s, c, n);
		printf("apres memset avec le carac %c et la longueur %d : %s\n", c, n, s);	
		strcpy(s, "0123456789");
		c = '$';
		n = 5;
		printf("avant ft_memset : %s\n", s);	
		ft_memset(s, c, n);
		printf("apres ft_memset avec le carac %c et la longueur %d : %s\n", c, n, s);	
	}
}

void test_ft_strsplit()
{
	char *str = "****les**etudiants***sont*****la*******";
	char **tab;
	int i;

	printf("%s\n", BANNER);
	printf("Test de ft_strsplit\n");	
	tab = ft_strsplit(str, '*');
	if (tab == NULL)
	{
		printf("echec allocation de memoire\n");
	}
	else
	{
		i = 0;
		while (tab[i])
		{
			printf("%s\n",tab[i]);
			i++;
		}
		
	}
}

int	main(int argc, char ** argv)
{
	if (argc != 1)
	{
		printf("Usage : %s\n", argv[0]);
		return (1);
	}
	test_ft_memset();
	test_ft_memcpy();
	test_ft_memccpy();
	test_ft_bzero();
	test_ft_strncpy();
	test_ft_itoa();
	test_ft_strsplit();
	return (0);
}
