#include <stdio.h>


int main()
{
    int num, fat;
    printf("\n Digite o numero a ser calculado o fatorial :: ");
    scanf(" %d", &num);
    if (num==0)
        printf("\n RESULTADO DO FATORIAL :: %d! = %d", 0, 1);
    else
    {
        int termos[num];
        int *ptr=termos;
        *ptr=num;

        while ( ptr!=&termos[num-1] )
        {
            *(ptr+1)= *ptr -1;
            ptr++;
        }
        for ( ptr=termos, fat=*ptr; ptr<=&termos[num-2]; ptr++ )
        {
            fat=fat**(ptr+1);
        }
        printf("\n RESULTADO DO FATORIAL :: %d! = %d", num, fat);
    }

    return 0;
}
