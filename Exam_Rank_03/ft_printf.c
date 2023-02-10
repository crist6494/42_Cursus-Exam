#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int i = 0;

	if(!str)
		str = "(null)";
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putbase(unsigned int n, int base)
{
	int tc = 0;
	char *num = "0123456789abcdef";

	if(n / base > 0)
		tc += ft_putbase(n / base, base);
	tc += ft_putchar(num[n % base]);
	return (tc);
}

int ft_putnbr(int n)
{
	int tc = 0;

	if(n < 0)
	{
		tc += ft_putchar('-');
		if(n == -2147483648)
		{
			tc+= ft_putstr("2147483648");
			return (tc);
		}
		n = -n;
	}
	tc += ft_putbase(n, 10);
	return (tc);
}

int ft_printf(char *str, ...)
{
	int i = 0;
	int tc = 0;
	va_list a_list;

	va_start(a_list, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			if(str[i + 1] == 's')
				tc += ft_putstr(va_arg(a_list,char *));
			if(str[i + 1] == 'd')
				tc += ft_putnbr(va_arg(a_list, int));
			if(str[i + 1] == 'x')
				tc += ft_putbase(va_arg(a_list, unsigned int), 16);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			tc++;
		}
		i++;
	}
	va_end(a_list);
	return (tc);
}

int main(void)
{
    int size;
    size = 0;
    size = ft_printf("%s\n", "toto");
    printf("%d\n", size);
    size = printf("%s\n", "toto");
    printf("%d\n", size);
    ft_printf("\n");
    size = ft_printf("Magic %s is %d\n", "number", 42);
    printf("%d\n", size);
    size = printf("Magic %s is %d\n", "number", 42);
    printf("%d\n", size);
    ft_printf("\n");
    size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("%d\n", size);
    size = printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("%d\n", size);
    ft_printf("\n");
    size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
    printf("%d\n", size);
    size = printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
    printf("%d\n", size);
    ft_printf("\n");
    size = ft_printf("%d, %d\n", 0, -24);
    printf("%d\n", size);
    size = printf("%d, %d\n", 0, -24);
    printf("%d\n", size);
    ft_printf("\n");
    ft_printf("Hello world %\n");
    return (0);
}