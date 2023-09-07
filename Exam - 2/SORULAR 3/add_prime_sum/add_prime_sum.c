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

void ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    write(1, &"0123456789"[nbr % 10], 1);
}

int is_prime(int nbr)
{
    int i = 2;

    while (i < nbr)
    {
        if (nbr % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    int i = 2;
    int k = 0;
    int nbr;
    
    if (ac == 2)
    {
        nbr = ft_atoi(av[1]);
        while (i <= nbr)
        {
            if (is_prime(i))
                k += i;
            i++;
        }
        ft_putnbr(k);
    }
    if (ac != 2)
        write(1, "0", 1);
    write(1, "\n", 1);
}