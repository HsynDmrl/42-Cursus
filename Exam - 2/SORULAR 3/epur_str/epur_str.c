#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        int k = 0;
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i])
        {
            if (str[i] == ' ' || str[i] == '\t')
                k = 1;
            if (str[i] != ' ' && str[i] != '\t' && str[i])
            {
                if (k)
                    write(1, " ", 1);
                k = 0;
                write(1, &str[i], 1);
            }
            i++;
        }
    }
        write(1, "\n", 1);

}