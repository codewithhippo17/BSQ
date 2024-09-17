int	count_lines(char *input)
{
	int i;
	int nb;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

#include <stdio.h>

int main()
{
    printf("%d", count_lines("9.xo\n......\n.o..o.\n..oo..\n..o..o"));
}