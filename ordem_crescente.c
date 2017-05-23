#include <stdio.h>

int main(void)
{

    float x, y, z, MXY, MXYZ, mxy, mxyz;
    printf("\n Digite um numero: ");
    scanf("%f", &x); fflush(stdin);
    printf("\n Digite outro numero: ");
    scanf("%f", &y); fflush(stdin);
    printf("\n Digite o ultimo numero: ");
    scanf("%f", &z); fflush(stdin);

    printf("\n  %f | %f | %f\n\n Em ordem crescente: ", x, y, z);
    /* MXY = Maior valor entre x e y
       mxy = Menor valor entre x e y */
    if (x >= y)
    {   MXY = x; mxy = y;   }
    else
    {   MXY = y; mxy = x;   }

    if (MXY >= z)
    {   MXYZ = MXY; mxyz = z;   }
    else
    {   MXYZ = z; mxyz = MXY;   }

    if ( mxyz >= mxy )
    {  printf("\n\n %f < %f <  %f", mxy, mxyz, MXYZ);   }
    else
    {  printf("\n\n %f < %f <  %f", mxyz, mxy, MXYZ);   }


    getch(); return 0;

}
