#include <stdio.h> //suppr
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int ret;

    fd = open("text.txt", O_RDONLY);
    //if (!(line = (char **)malloc(sizeof(char*) * 10000)))
        //return (0);
    
    /*ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%i\n", ret);*/

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        printf("%i\n", ret);
        free(line);
    }
    printf("%s\n", line);
    printf("%i\n", ret);
    free(line);

    while (1)
    ;

    return(0);
}
