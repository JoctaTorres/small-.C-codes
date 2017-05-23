#include <stdio.h>


int main()
{
    int seg=0, min=0, hr=0;
    int n;

    printf("\n Digite um numero em segundos: ");
    scanf("%d", &n);

    if (n<=60)
    {
        seg = n;
    }
    if (n>60 && n<=3600)
    {
        seg = n%60;
        min = n/60;
        if (min==60)
        {
            min=0;
            hr=1;
        }
    }
    else
    {
        seg = n%60;
        min = n/60;
        while (min >= 60)
        {
            ++hr;
            min -=60;
        }
    }
    printf("\n => %.2d : %.2d : %.2d ", hr, min, seg);
    return 0;

}
