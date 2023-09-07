#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return res;
}

void    ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    write(1, &"0123456789"[nbr % 10], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nbr = ft_atoi(av[1]);
        int i = 1;
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nbr);
            write(1, " = ", 3);
            ft_putnbr(nbr * i);
            write(1, "\n", 1);
            i++;
        }
    }
    else if (ac != 2)
        write(1, "\n", 1);
}