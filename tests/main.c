#include <stdio.h>
#include <fctnl.h>
#include "get_next_line.h"

int main(void)
{
    int ret;
    char *line;
    int fd = open("txt.txt", O_RDONLY);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);

    fd = open("nobackslash.txt", O_RDONLY);

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
    
    while ((ret = get_next_line(fd, NULL)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);    
   
    while ((ret = get_next_line(0, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
    }
    printf("%s\n", line);
    printf("%i\n", ret);
    return (0);
}
