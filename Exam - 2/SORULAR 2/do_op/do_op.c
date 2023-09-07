#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        int a = atoi(av[1]);
        int b = atoi(av[3]);
        char j = av[2][0];
        int res = 0;

        if (j == '*')
            res = a * b;
        if (j == '/')
            res = a / b;
        if (j == '+')
            res = a + b;
        if (j == '-')
            res = a - b;
        if (j == '%')
            res = a % b;
        printf("%d", res);
    }
    printf("\n");
}