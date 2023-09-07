#include <unistd.h>

void str_capital(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (av[i])
        {
            str_capital(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    if (ac < 2)
        write(1, "\n", 1);
}