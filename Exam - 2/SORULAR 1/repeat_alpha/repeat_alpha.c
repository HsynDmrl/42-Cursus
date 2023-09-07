#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];
    int k = 0;

    if (ac == 2)
    {
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                k = str[i] - 96;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                k = str[i] - 64;
            else
                write(1, &str[i], 1);
            while (k != 0)
            {
                if (k >= 0)
                    write(1, &str[i], 1);
                k--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}