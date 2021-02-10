#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

void	print_bin(char b)
{
	printf("%d%d%d%d%d%d%d%d", (b&128)!=0, (b&64)!=0, (b&32)!=0, (b&16)!=0, (b&8)!=0, (b&4)!=0, (b&2)!=0, (b&1)!=0);
}

void	print_double(char *b)
{
	b += 7;
	printf("[%d][%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d][%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
	b--;
	printf("%d%d%d%d%d%d%d%d]\n", (*b&128)!=0, (*b&64)!=0, (*b&32)!=0, (*b&16)!=0, (*b&8)!=0, (*b&4)!=0, (*b&2)!=0, (*b&1)!=0);
}

int main()
{

	char *format = "---%-10.5d---\n";
	int a = -216;
	printf(format, a);
	ft_printf(format, a);

	return 0;
}
