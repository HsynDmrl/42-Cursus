#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];

    if (ac == 2)
    {
        while (str[i])
            i++;
        i--;
        while ((str[i] == ' ' || str[i] == '\t') && i != 0)
            i--;
        while ((str[i] != ' ' && str[i] != '\t') && i != 0)
            i--;
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != ' ' && str[i] != '\t' && str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}