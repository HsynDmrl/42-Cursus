#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];

    if (ac == 2)
    {
        while (str[i])
        {
            if ((str[i] >= 'a' && str[i] <= 'y') ||(str[i] >= 'A' && str[i] <= 'Y'))
                str[i] += 1;
            else if (str[i] == 'z' || str[i] == 'Z')
                str[i] -= 25;
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}