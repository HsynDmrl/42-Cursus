#include "get_next_line.h"

char    *ft_strchr(char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    return NULL;
}

size_t  ft_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t srcsize = ft_strlen(src);
    size_t i = 0;
    
    if (dstsize > 0)
    {
        while (i < srcsize && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return srcsize;
}
#include <stdio.h>

char    *ft_strdup(const char *str)
{
    size_t len = ft_strlen(str) + 1;
    char *new = malloc(len);

    if (!new)
        return NULL;

    ft_strlcpy(new, str, len);
    return new;
}

char    *ft_strjoin(char *str1, char *str2, size_t len)
{
    size_t str1_len = ft_strlen(str1);
    size_t str2_len = len;
    char    *join;

    if (!str1 || !str2)
        return NULL;

    join = (char *)malloc((str1_len + str2_len + 1) * sizeof(char));
    if (!join)
        return NULL;

    ft_strlcpy(join, str1, str1_len + 1);
    ft_strlcpy((join + str1_len), str2, str2_len + 1);
    free(str1);
    return join;
}

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char        *line;
    char        *newline;
    int         countread;
    int         to_copy;

    line = ft_strdup(buf);

    while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[countread] = '\0';
        line = ft_strjoin(line, buf, countread);
    }
    if (ft_strlen(line) == 0)
        return (free(line), NULL);
    newline = ft_strchr(line, '\n');
    if (newline != NULL)
    {
        to_copy = newline - line + 1;
        ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
    }
    else
    {
        to_copy = ft_strlen(line);
        ft_strlcpy(buf, "", BUFFER_SIZE + 1);
    }
    line[to_copy] = '\0';
    return line;
}
#include <fcntl.h>

int main()
{
    int fd;
    char *line = NULL;

    fd = open("get_next_line1.h", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
}