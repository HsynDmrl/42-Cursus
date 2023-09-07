#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *str = av[1];

    if(ac == 2)
    {
        while (str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            else if(str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}