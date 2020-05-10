#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int ret;
    char *line;
    int fd = open("txt.txt");

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);

    fd = open("nobackslash.txt");

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);

    while ((ret = get_next_line(42, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);

    return (0);
}