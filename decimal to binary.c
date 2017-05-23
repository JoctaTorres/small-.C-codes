#include <stdio.h>

int binarydigits(int div, int dis)
{
    int numit;
    numit=0;

    do
    {
        ++numit;
        div /= dis;
    }
    while (div!=1);
    ++numit;
    return numit;
}

int main()
{
    int x, nb, i;

    printf("\n Input an decimal integer number to be converted: ");
    scanf("%d", &x);
    fflush(stdin);

    if (x==0 || x==1)
    {
        printf("\n\n %d in binary : %d", x, x);
    }

    else
    {
        printf("\n\n %d in binary : ", x);
        nb = binarydigits(x, 2);
        // the function 'binarydigits' returns how many binary digits are needed to represent 'x'
        int remind[nb];
        // an array of 'nb' elements is declared. Each element of this array will hold a binary digit
        for(i=(nb-1) ; i>=0 ; --i, x/=2)
        {
            remind[i] = x%2;
        }
        //this 'for' structure saves the remainder of 'x/2' (x%2) in an element of the 'remind[nb]' array

        for (i=nb ; i>0 ; --i)
        {
            printf("%d", remind[nb-i]);
        }
        //this 'for' structure prints the elements of the 'remind[nb]' array in increasing order

    }

    getch();
    return 0;


}
