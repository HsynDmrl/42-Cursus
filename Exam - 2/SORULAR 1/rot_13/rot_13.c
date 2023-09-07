#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];

    if (ac == 2)
    {
        while (str[i])
        {
            if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
                str[i] += 13;
            else if ((str[i] >= 'n' && str[i] <= 'z')  || (str[i] >= 'N' && str[i] <= 'Z'))
                str[i] -= 13;
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}