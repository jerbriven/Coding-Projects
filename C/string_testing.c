#include <string.h>
#include <stdio.h>

int main()
{
    char src[6] = "hello";
    char dest[6];

    strlcpy(dest, src, 6);

    printf("%s", dest);
}