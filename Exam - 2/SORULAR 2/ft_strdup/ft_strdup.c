#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    char *res;

    while (src[i])
        i++;
    res = (char *)malloc(sizeof(char) * i + 1);
    if (!res)
        return 0;
    i = 0;
    while (src[i])
    {
        res[i] = src[i];
        i++;
    }
    res[i] = src[i];
    return res;
}