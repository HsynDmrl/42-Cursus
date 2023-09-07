#include <stdlib.h>

int ft_len(int nbr)
{
    if (nbr < 0)
        return -nbr;
    return nbr;
}

int     *ft_range(int start, int end)
{
    int i = 0;
    int len = ft_len(start - end) + 1;
    int *tab = (int *)malloc(sizeof(int) * len);

    while (start < end)
    {
        tab[i] = start;
        start++;
        i++;
    }
    tab[i] = start;
    while (start > end)
    {
        tab[i] = start;
        start--;
        i++;
    }
    tab[i] = start;
    return tab;
}