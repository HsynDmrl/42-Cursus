#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        char *str = av[1];
        int k = 0;
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z') 
                k += 'm' + 'n' - str[i];
            else if (str[i] >= 'A' && str[i] <= 'Z')
                k += 'M' + 'N' - str[i];
            else
                write(1, &str[i], 1);
            if (k >= 1)
                    write(1, &k, 1);
            k = 0;
            i++;
        }
    }
    write(1, "\n", 1);
}