int check_char(char c, char *input)
{
    if (c == input[1] || c == input[2] || c == input[3] || c == '\n')
        return (1);
    return (0);
}

int check_str(char *input)
{
    int i;

    i = 5;
    while (input[i])
    {
        if (check_char(input[i], input) == 0)
            return (0);
        i++;
    }
    return (1);
}


#include <stdio.h>
int main()
{
    printf("%d\n", check_str("9.ox\n...........o................\n....o......................\n............o.............."));
}