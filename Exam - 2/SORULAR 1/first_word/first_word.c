#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] != ' ' && str[i] != '\t' && str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}