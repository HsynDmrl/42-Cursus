int index_of(char *str, char c, int str_base)
{
    int i = 0;
    while (str[i] && i < str_base)
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (index_of("0123456789ABCDEF", str[i], str_base) >= 0 || index_of("0123456789abcdef", str[i], str_base) >= 0)
    {
        res *= str_base;
        if (str[i] >= 'A' && str[i] <= 'Z')
            res += index_of("0123456789ABCDEF", str[i], str_base);
        else
            res += index_of("0123456789abcdef", str[i], str_base);
        i++;
    }
    return res * sign;
}