#include "ft_printf.h"
#include <stdio.h>
/*int main()
{
	//print_params(4, 1, 34, 56);
	int *p = malloc (16 * sizeof(int));
	ft_printf("number: %i\nstring : %s\nchar: %c\npointer address: %p\n", 3, "hola", 'f', &p);
	printf("The original does :\nnumber: %i\nstring : %s\nchar: %c\npointer address: %p\n", 3, "hola", 'f', &p);
	printf("The original : Hexadecimal number : %X\n %%", 1234687);
	ft_printf("Hexadecimal number : %X\n %%", 1234687);
	system("Leaks");

}*/

int main()
{
	printf("%i \n",ft_printf("1 : %c\n", '0'));
	printf("%i\n",ft_printf(" %c \n", '0'));
	printf("%i\n",ft_printf(" %c\n", '0' - 256));
	printf("%i\n",ft_printf(" %c %c %c \n", '0', 0, '1'));
	printf("la original \n");
	printf("%i \n",printf("1 : %c\n", '0'));
	printf("%i\n",printf(" %c \n", '0'));
	printf("%i\n",printf(" %c\n", '0' - 256));
	printf("%i\n",ft_printf(" %c %c %c \n", '0', 0, '1'));
};

/*int main()
{

	printf("imprime %i\n",ft_printf("%s", ""));
	printf("imprime %i\n" ,ft_printf(" %s", ""));
	printf("imprime%i\n",ft_printf(" %s %s ", "", "-"));
	printf("imprime%i\n",ft_printf(" %s %s %s %s ", " - ", "", "4", ""));
	printf("imprime%i\n",ft_printf("%s %s %s %s %s ", " - ", "", "4", "", "2 "));
	printf("imprime%i\n",ft_printf(" NULL %s NULL ", NULL));
	printf("la original;\n");
	printf("imprime%i\n",printf("%s", ""));
	printf("imprime%i\n",printf(" %s", ""));
	printf("imprime%i\n",printf(" %s %s ", "", "-"));
	printf("imprime%i\n",printf(" %s %s %s %s ", " - ", "", "4", ""));
	printf("%i\n",printf("%s %s %s %s %s ", " - ", "", "4", "", "2 "));
	printf("imprime%i\n",printf(" NULL %s NULL ", NULL));
}*/
/*int main()
{
	//printf("imprime %i\n", ft_printf(" %i ", 0));
	printf("imprime %i\n", ft_printf(" %i ", -1));
	printf("imprime %i\n", ft_printf(" %i ", 10));
	printf("imprime %i\n", ft_printf(" %i ", 101));
	printf("imprime %i\n", ft_printf(" %i ", INT_MAX));
	printf("imprime %i\n", ft_printf(" %i ", LONG_MIN));
	printf("imprime %i\n", ft_printf(" %i ", LONG_MAX));
	//printf("imprime %i\n", ft_printf(" %i ", 9223372036854775807LL));
	printf("la orig \n");
	//printf("imprime %i\n", printf(" %i ", 0));
	printf("imprime %i\n", printf(" %i ", -1));
	printf("imprime %i\n", printf(" %i ", 10));
	printf("imprime %i\n", printf(" %i ", 101));
	printf("imprime %i\n", printf(" %i ", INT_MAX));
	printf("imprime %i\n", printf(" %i ", LONG_MIN));
	printf("imprime %i\n", printf(" %i ", LONG_MAX));
	//printf("imprime %i\n", printf(" %i ", 9223372036854775807LL));
	}*/
/*int main()
{
	ft_printf("hola %10s","mundo");}*/
/*int main()
{
	
	printf("imprime %i\n", ft_printf(" %x ", 0));
	printf("imprime %i\n", ft_printf(" %x ", -1));
	printf("imprime %i\n", ft_printf(" %x ", 9));
	printf("imprime %i\n", ft_printf(" %x ", 11));
	printf("imprime %i\n", ft_printf(" %x ", 15));
	printf("imprime %i\n", ft_printf(" %x ", 99));
	printf("imprime %i\n", ft_printf(" %x ", -9));
	printf("imprime %i\n", ft_printf(" %x ", -14));
	printf("imprime %i\n", ft_printf(" %x ", -100));
	printf("imprime %i\n", ft_printf(" %x ", INT_MAX));
	printf("imprime %i\n", ft_printf(" %x ", LONG_MAX));
	printf("imprime %i\n", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("La orig \n");
	printf("imprime %i\n", printf(" %x ", 0));
	printf("imprime %i\n", printf(" %x ", -1));
	printf("imprime %i\n", printf(" %x ", 9));
	printf("imprime %i\n", printf(" %x ", 11));
	printf("imprime %i\n", printf(" %x ", 15));
	printf("imprime %i\n", printf(" %x ", 99));
	printf("imprime %i\n", printf(" %x ", -9));
	printf("imprime %i\n", printf(" %x ", -14));
	printf("imprime %i\n", printf(" %x ", -100));
	printf("imprime %i\n", printf(" %x ", INT_MAX));
	printf("imprime %i\n", printf(" %x ", LONG_MAX));
	printf("imprime %i\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}*/
/*int main()
{
	printf("imprime %i\n", ft_printf(" %p ", -1));
	printf("imprime %i\n", ft_printf(" %p ", 1));
	printf("imprime %i\n", ft_printf(" %p ", 15));
	printf("imprime %i\n", ft_printf(" %p ", 16));
	printf("imprime %i\n", ft_printf(" %p ", 17));
	printf("imprime %i\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("imprime %i\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
	printf("imprime %i\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("imprime %i\n", ft_printf(" %p %p ", 0, 0));
	printf("la orginal \n");
	printf("imprime %i\n", printf(" %p ", -1));
	printf("imprime %i\n", printf(" %p ", 1));
	printf("imprime %i\n", printf(" %p ", 15));
	printf("imprime %i\n", printf(" %p ", 16));
	printf("imprime %i\n", printf(" %p ", 17));
	printf("imprime %i\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("imprime %i\n", printf(" %p %p ", INT_MIN, INT_MAX));
	
	printf("imprime %i\n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("imprime %i\n", printf(" %p %p ", 0, 0));
}*/
