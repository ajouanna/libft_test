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

void 	test_ft_atoi()
{
	char *str;
	int val;
	int ft_val;

	printf("%s\n", BANNER);
	ft_putstr("Testing ft_atoi\n");

	str = "+-1";
	val = atoi(str);
	ft_val = ft_atoi(str);
	printf("atoi(%s)=%d\n", str, val);
	printf("ft_atoi(%s)=%d\n", str, ft_val);

	str = "-1";
	val = atoi(str);
	ft_val = ft_atoi(str);
	printf("atoi(%s)=%d\n", str, val);
	printf("ft_atoi(%s)=%d\n", str, ft_val);

	str = "\200123";
	val = atoi(str);
	ft_val = ft_atoi(str);
	printf("atoi(%s)=%d\n", str, val);
	printf("ft_atoi(%s)=%d\n", str, ft_val);
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

void test_ft_strlcat()
{
/* ne marche pas sous Linux
	size_t max_size;

	printf("%s\n", BANNER);
	printf("Test de ft_strlcat\n");	
	max_size = 9;

	size_t size=0;
	while (size <= max_size)
	{
		char *src = "4567";
		char dest[100] = "";
		char ft_dest[100] = "";
		size_t res;
		size_t ft_res;
		res = strlcat(dest, src, size);
		ft_res = ft_strlcat(ft_dest, src, size);
		printf("strlcat pour src=%s, size = %zu : dest=%s et res=%zu\n",src, size, dest, res); 
		printf("ft_strlcat pour src=%s, size = %zu : dest=%s et res=%zu\n",src, size, ft_dest, ft_res); 
		size++;
	}
	*/
}

t_list *cp_elem_lst(t_list *elem)
{
	t_list *cp;
	void *content_cp;

	cp = NULL;
	if (elem)
	{
		content_cp = ft_memalloc(elem->content_size);
		content_cp = ft_memcpy(content_cp, elem->content, elem->content_size);

		cp = ft_lstnew(content_cp, elem->content_size);
	}
	return (cp);
}


// pour les besoins de mes tests, le contenu ser tjrs une chaine 
// de caracteres C
void	affiche_content(void *p, size_t size)
{
	printf("content=%s\n",(p) ? (char *)p : "(null)");
	printf("content_size=%zu\n",size);
}

// pour les besoins de mes tests, le contenu ser tjrs une chaine 
// de caracteres C
void affiche_elem_lst(t_list *lst)
{
	if (lst)
	{
		affiche_content(lst->content,lst->content_size);
		printf("next is %s\n\n",(lst->next)? "not null" : "null");
	}
	else
		printf("affiche_elem_lst : cannot display, lst parameter is null\n");
}

void affiche_lst(t_list *lst)
{
	t_list *pt;

	pt = lst;
	while (pt)
	{
		affiche_elem_lst(pt);
		pt = pt->next;
	}
}

void test_ft_lst()
{
	t_list *lst;
	t_list *lst1;
	t_list *lst2;
	t_list *map;
	char *contenu;

	printf("%s\n", BANNER);
	printf("Test de ft_lstnew\n");	
	contenu = "aaaaaaa";
	lst = ft_lstnew(contenu, 1 + ft_strlen(contenu));
	printf("%s\n", "Contenu de lst apres ft_lstnew");
	affiche_lst(lst);

	printf("%s\n", BANNER);
	printf("Test de ft_lstadd\n");	
	contenu = "bbbbbb";
	lst1 = ft_lstnew(contenu, 1 + ft_strlen(contenu));
	ft_lstadd(&lst, lst1);
	contenu = "ccccc";
	lst2 = ft_lstnew(contenu, 1 + ft_strlen(contenu));
	ft_lstadd(&lst1, lst2);
	printf("%s\n", "Contenu de lst2 apres ft_lstadd");
	affiche_lst(lst2);

	printf("%s\n", BANNER);
	printf("Test de ft_lstiter\n");	
	ft_lstiter(lst2, &affiche_elem_lst);

	printf("%s\n", BANNER);
	printf("Test de ft_lstmap\n");	
	map = ft_lstmap(lst2, cp_elem_lst);
	printf("%s\n", "Contenu de map apres ft_lstmap");
	affiche_lst(map);

	printf("%s\n", BANNER);
	printf("Test de ft_lstdelone\n");	
	ft_lstdelone(&map,affiche_content);
	printf("%s\n", "Contenu de map apres ft_lstdelone");
	affiche_lst(map);

	printf("%s\n", BANNER);
	printf("Test de ft_del\n");	
	printf("%s\n", "Contenu de lst1 avant ft_lstdel");
	affiche_lst(lst1);
	printf("%s\n", "Appel de ft_lstdel");
	ft_lstdel(&lst1,affiche_content);
	printf("%s\n", "Contenu de lst1 apres ft_lstdel");
	affiche_lst(lst1);
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
	test_ft_atoi();
	test_ft_itoa();
	test_ft_strsplit();
	test_ft_strlcat();
	test_ft_lst();
	return (0);
}
