#include <stdlib.h>

int ft_negative(int nbr)
{
    if (nbr < 0)
        return -nbr;
    return nbr;
}

int ft_len(int nbr)
{
    int len = 0;

    if (nbr <= 0)
        ++len;

    while (nbr != 0)
    {
        ++len;
        nbr = nbr / 10;
    }
    return len;
}

char *ft_itoa(int nbr)
{
    int len = ft_len(nbr);
    char *tab = (char *)malloc(sizeof(char) * len + 1);
    tab[len] = '\0';


    if (nbr == 0)
        tab[0] = '0';
    else if (nbr < 0)
        tab[0] = '-';
    
    while (nbr != 0)
    {
        if (len >= 0)
        {
            --len;
            tab[len] = ft_negative(nbr % 10) + '0';
            nbr /= 10;
        }
    }
    return tab;
}