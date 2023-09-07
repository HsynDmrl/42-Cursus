#include <unistd.h>

void ft_capital(char *str)
{
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    write(1, &str[i], 1);

    while (str[++i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n'))
            str[i] -= 32;
        write(1, &str[i], 1);
    }
}

int main(int ac, char **av)
{
    int i = 1;
    if (ac > 1)
    {
        while (av[i])
        {
            ft_capital(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    if (ac < 2)
        write(1, "\n", 1);

}