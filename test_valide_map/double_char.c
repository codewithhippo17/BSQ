int check_dups(char *input)
{
    int i;
    int j;

    i = 1;
    while (i < 3)
    {
        j = i + 1;
        while (j <= 3)
        {
            if (input[i] == input[j])
                return (0);
            j++;
        }
        i++;
    }
    if (input[4] != '\n')
        return (0);
    return (1);
}

#include <stdio.h>

int main()
{
    printf("%d", check_dups("9.ox\n"));
}