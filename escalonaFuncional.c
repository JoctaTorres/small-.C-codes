#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int li, co; // linha e coluna
    int il, ic; // ind.Linha e ind.Coluna
    //float matriz[3][4]={{1,3,2,2},{3,5,4,4},{5,3,4,-10}};
S:
    system("cls");
    printf("\n DIGITE A DIMENSAO DA MATRIZ. \n LINHAS :: ");
    scanf(" %d", &li);
    printf(" COLUNA :: ");
    scanf(" %d", &co);
    if(li<co-1)
    {
        printf("\n NUMERO DE EQUACOES INSUFICIENTE. TENTE DE NOVO : ");
        goto S;
    }

    system("cls");
    float matriz[li][co];
    for(il=0 ; il<li ; il++ ) // lendo a matriz
    {
        for(ic=0; ic<co; ic++ )
        {
            printf("\n VALOR DO ELEMENTO [%d][%d] = ",il+1, ic+1);
            scanf(" %f", &matriz[il][ic]);

        }
    }

    system("cls");
    printf("\n A MATRIZ AMPLIADA DO SISTEMA :: \n");

    for(il=0 ; il<li ; il++ ) // imprimindo a matriz
    {
        printf("\n");
        for(ic=0; ic<co; ic++ )
        {
            //matriz[il][ic]=0;
            printf(" \t%.2f", matriz[il][ic]);
        }

    }

    int lo, ld, oc, n;
    float laux[co];
    float aux, k;
    int zero=1;

    for(ic= 0, il=0; il<li; ic++, ++il) //**
    {

        if (matriz[il][ic]==0) // caso permuta
        {
            //printf("\n teste 1 lo=%d e li=%d", lo,li);

            for(lo=il; lo<li; lo++) //acha na coluna um n�mero n�o nulo
            {
                if(matriz[lo][ic]!=0)
                    ld=lo;
            }
            //printf("\n teste 2 lo=%d e li=%d", lo,li);
            if(lo!=li){
            for(oc=0; oc<co; oc++) //realiza a permuta
            {
                laux[oc] = matriz[il][oc];
                matriz[il][oc] = matriz[ld][oc];
                matriz[ld][oc] = laux[oc];
            }}
            else {
                 zero=0;
                 printf("\n impossivel");
                 
                 }
            //printf("\n teste 3 lo=%d e li=%d", lo,li);
            

        }
        if(zero){
        //coloca o um
        aux=matriz[il][ic];
        for(oc=ic; oc<co; oc++)
        {
            matriz[il][oc]/=aux;
        }

        //zera os demais elementos da coluna
        for (lo=il+1; lo<li; lo++)
        {
            k=-matriz[lo][ic];
            for(oc=ic; oc<co; oc++) //numa linha aux. copia e opera a linha sendo trabalhada
            {
                laux[oc] = matriz[il][oc];
                laux[oc]*=k;
                matriz[lo][oc]+=laux[oc];
            }

        }
        }
    }

    printf("\n\n A MATRIZ ESCALONADA DO SISTEMA :: \n");

    for(il=0 ; il<li ; il++ ) // imprimindo a matriz
    {
        printf("\n");
        for(ic=0; ic<co; ic++ )
        {
            //matriz[il][ic]=0;
            printf(" \t%.2f", matriz[il][ic]);
        }

    }
    char r;
    printf("\n\n DESEJA REPETIR? [S/N] : ");
    scanf(" %c", &r); r=toupper(r);
    if(r=='S')
        goto S;
    return 0;

}
