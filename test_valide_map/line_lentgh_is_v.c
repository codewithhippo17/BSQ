int line_lentgh_is_v(char *input)
{
    int i;
    int len;
    int line;

    i = 5;
    len = 0;
    line = 0;
    while (input[i] != '\n' && input[i])
    {
        line++;
        i++;
    }
    while (input[i])
    {
        i++;
        len = 0;
        while (input[i] != '\n' && input[i])
        {
            len++;
            i++;
        }
        if (len != line)
            return (0);
    }
    return (1);
}

#include <stdio.h>

int main()
{
    printf("%d\n", line_lentgh_is_v("9.ox\n...........................\n....o......................\n............o..............\n...........................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................"));
}