#include <stdlib.h>

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **split= (char **)malloc(100);

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i])
    {
        if (str[i] > 32)
        {
            split[k] = (char *)malloc(100);
            while (str[i] != ' ' && str[i] != '\t' && str[i])
            {
                split[k][j] = str[i];
                i++;
                j++;
            }
            split[k][j] = '\0';
            k++;
            j = 0;
        }
        else
            i++;
    }
    split[k] = 0;
    return split;
}