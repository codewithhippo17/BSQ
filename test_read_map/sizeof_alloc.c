int sizeof_alloc(char *input)
{
	int i;
	int len;

	i = 5;
	len = 0;
	while (input[i])
	{
		if (input[i] != '\n')
		{
			i++;
			len++;
		}
		else
        {
		    i++;
        }
	}
	return (len);
}

#include <stdio.h>

int main()
{
    printf("%d", sizeof_alloc("9.xo\n......\n.o..o.\n..oo..\n..o..o"));
}