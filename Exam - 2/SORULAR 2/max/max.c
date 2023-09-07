int		max(int* tab, unsigned int len)
{
    int i = -1;
    int tmp;

    if (len == 0)
        return 0;
    
    while (++i < (len - 1))
    {
        if (tab[i] < tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = -1;
        }
    }
    return tab[0];
}