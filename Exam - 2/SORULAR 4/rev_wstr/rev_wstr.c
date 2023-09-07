#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **split = (char **)malloc(100);

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

int main(int ac, char **av)
{
    int i = 0;
    char **words;

    if (ac == 2)
    {
        words = ft_split(av[1]);
        while (words[i])
            i++;
        i--;
        while (i >= 0)
        {
            ft_putstr(words[i]);
            if (i > 0)
                write(1, " ", 1);
            i--;
        }
    }
    write(1, "\n", 1);
}