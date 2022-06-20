#include <stdio.h>
#include <stdlib.h>
#define size 101
int main()
{
    int m[size][size] = {
        0,
    };
    int n = 0;
    int num = 1;
    printf("ют╥б : ");
    scanf("%d", &n);
    m[0][0] = num++;
    int *p = &m[0][0];
    int x, y;
    for (x = 0; x < n - 1; x++)
    {
        p = p + 1;
        *p = num++;
    }
    for (x = 0; x < n - 1; x++)
    {
        p = p + size;
        *p = num++;
    }
    for (x = 0; x < n - 1; x++)
    {
        p = p - 1;
        *p = num++;
    }
    for (x = 0; x < n - 2; x++)
    {
        p = p - size;
        *p = num++;
    }
    while (*(p + 1) == 0)
    {
        while (*(p + 1) == 0)
        {
            p = p + 1;
            *p = num++;
        }
        while (*(p + size) == 0)
        {
            p = p + size;
            *p = num++;
        }
        while (*(p - 1) == 0)
        {
            p = p - 1;
            *p = num++;
        }
        while (*(p - size) == 0)
        {
            p = p - size;
            *p = num++;
        }
    }


    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            printf("%d ", m[x][y]);
        }
        printf("\n");
    }
}