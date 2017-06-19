#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define P 3 // Nº DE ESCALAS
#define N 4 // Nº DE CANDIDATOS POR ESCALAS

typedef struct Escala
{
    char *escalas;
    int A;
    int B;
    int C;
    int D;

} Escala;



Escala candidatos[P];


void inicializar()
{
    int i;
    for (i=0; i<P ; i++)
    {

        candidatos[i].A=0;
        candidatos[i].B=0;
        candidatos[i].C=0;
        candidatos[i].D=0;

    }
    candidatos[0].escalas="PRESIDENTE";
    candidatos[1].escalas="GOVERNADOR";
    candidatos[2].escalas="PREFEITO";
}

int menu()
{
    int menuSelect=0;
    do
    {
        printf(" \n [01] - VOTAR ");
        printf(" \n [02] - RESULTADOS ");
        printf(" \n [03] - ENCERRAR ");
        printf(" \n\n SELECIONE UMA OPCAO :: ");
        scanf(" %d", &menuSelect);
        if(menuSelect<1||menuSelect>3)
        {
            system("cls");
            printf("\n Opcao inexistente, tente mais uma vez:\n");
        }
    }
    while(menuSelect<1 || menuSelect>3);

    return menuSelect;
}

void votar()
{
#define saida 5
    int voto=0;
    char escala;
    system("cls");
    do
    {
    printf("\n VOTAR NA ESCALA :");
    printf("\n [F] - FEDERAL \n [E] - ESTADUAL \n [M] - MUNICIPAL");
    printf(" \n\n SELECIONE UMA OPCAO :: ");
    scanf(" %c", &escala);
    escala=toupper(escala);
    if(escala!='F' && escala!='E' && escala!='M')
        {
            system("cls");
            printf("\n Opcao inexistente, tente mais uma vez:\n");
        }
    }while(escala!='F' && escala!='E' && escala!='M');

    int escAux;
    char urna;

    switch(escala)
    {
    case 'F':
        escAux=0;
        urna='f';
        break;
    case 'E':
        escAux=1;
        urna='e';
        break;
    case 'M':
        escAux=2;
        urna='m';
        break;
    }
    int count;
    for(count=0 ; voto!=saida ; count++)
    {
        system("cls");
        printf(" \n VOTACAO PARA %s : ", candidatos[escAux].escalas);
        printf(" \n [01] - VOTAR EM CANDIDATO A ");
        printf(" \n [02] - VOTAR EM CANDIDATO B ");
        printf(" \n [03] - VOTAR EM CANDIDATO C ");
        printf(" \n [04] - VOTAR EM CANDIDATO D ");
        printf(" \n [05] - ENCERRAR VOTACAO PARA %s ", candidatos[escAux].escalas);
        printf(" \n\n SELECIONE UMA OPCAO :: ");
        scanf(" %d", &voto);


        if (urna=='f')
        {
            // votos dos candidatos para presid�ncia
            switch(voto)
            {
            case 1:
                candidatos[0].A++;
                break;
            case 2:
                candidatos[0].B++;
                break;
            case 3:
                candidatos[0].C++;
                break;
            case 4:
                candidatos[0].D++;
                break;
            default: printf("\n Opcao invalida. Tente mais ma vez.\n"); system("pause"); break;
            }
        }
        else
        {
            if (urna=='e')
            {
                //votos dos candidatos para governador
                switch(voto)
                {
                case 1:
                    candidatos[1].A++;
                    break;
                case 2:
                    candidatos[1].B++;
                    break;
                case 3:
                    candidatos[1].C++;
                    break;
                case 4:
                    candidatos[1].D++;
                    break;
                default: printf("\n Opcao invalida. Tente mais ma vez.\n"); system("pause"); break;
                }
            }
            else
            {
                //votos dos candidatos para prefeito
                switch(voto)
                {
                case 1:
                    candidatos[2].A++;
                    break;
                case 2:
                    candidatos[2].B++;
                    break;
                case 3:
                    candidatos[2].C++;
                    break;
                case 4:
                    candidatos[2].D++;
                    break;
                default: printf("\n Opcao invalida. Tente mais ma vez.\n"); system("pause"); break;
                }
            }
        }
    }

    printf(" \n TOTAL DE VOTOS APURADOS : %d \n", count-1);

/*
    printf(" candidatos[0].A = %d \n", candidatos[0].A);
    printf(" candidatos[0].B = %d \n", candidatos[0].B);
    printf(" candidatos[0].C = %d \n", candidatos[0].C);
    printf(" candidatos[0].D = %d \n\n", candidatos[0].D);

    printf(" candidatos[1].A = %d \n", candidatos[1].A);
    printf(" candidatos[1].B = %d \n", candidatos[1].B);
    printf(" candidatos[1].C = %d \n", candidatos[1].C);
    printf(" candidatos[1].D = %d \n\n", candidatos[1].D);

    printf(" candidatos[2].A = %d \n", candidatos[2].A);
    printf(" candidatos[2].B = %d \n", candidatos[2].B);
    printf(" candidatos[2].C = %d \n", candidatos[2].C);
    printf(" candidatos[2].D = %d \n\n", candidatos[2].D);*/
    system("pause");
}

void resultado()
{
    typedef struct Vencedor
    {
        char candidatoV; // recebe o candidato do maior
        int qntV; //quantidade de votos

    } Vencedor;

    Vencedor win[N];


    int i=0, j;
    for (i=0, j=0 ; i<P ; i++ )
    {
        system("cls");
        printf("\n RESULTADO DA ELEICAO PARA %s : \n",candidatos[i].escalas );
        printf("\n CANDIDATO A RECEBEU : %d ", candidatos[i].A);
        printf("\n CANDIDATO B RECEBEU : %d ", candidatos[i].B);
        printf("\n CANDIDATO C RECEBEU : %d ", candidatos[i].C);
        printf("\n CANDIDATO D RECEBEU : %d ", candidatos[i].D);


        for (j=0 ; j<N; j++)
        {
            win[j].candidatoV=' ';
            win[j].qntV=0;
        }

        int maior=0;
        j=0;

        if (candidatos[i].A >= maior)
        {
            maior = candidatos[i].A;
            win[j].candidatoV = 'A';
            win[j].qntV = candidatos[i].A;
            j++;
        }

        if (candidatos[i].B >= maior)
        {
            maior = candidatos[i].B;
            win[j].candidatoV = 'B';
            win[j].qntV = candidatos[i].B;
            j++;
        }

        if (candidatos[i].C >= maior)
        {
            maior = candidatos[i].C;
            win[j].candidatoV = 'C';
            win[j].qntV = candidatos[i].C;
            j++;
        }

        if (candidatos[i].D >= maior)
        {
            maior = candidatos[i].D;
            win[j].candidatoV = 'D';
            win[j].qntV = candidatos[i].D;
        }


        for (j=N-1; j>0; j--)
        {
            if (win[j].qntV > win[j-1].qntV)
            {
                printf("\n\n O VENCEDOR DA ELEICAO FOI CANDIDATO %c !\n", win[j].candidatoV);
                break;
            }
             if (win[j].qntV == win[j-1].qntV)
            {
                if(win[j].qntV ==0 && win[j].candidatoV == ' ' && win[j-1].candidatoV == ' ')
                    continue;

                printf("\n EMPATE ENTRE CANDIDATO %c E CANDIDATO %c\n",win[j].candidatoV, win[j-1].candidatoV);
                j--;
                if (win[j].qntV == win[j-1].qntV && j!=0)
                    printf("\n EMPATE ENTRE CANDIDATO %c E CANDIDATO %c\n",win[j].candidatoV, win[j-1].candidatoV);

            }
        }

     system("pause");
    }

    /*for (i=0; i<N; i++ )
    {
        printf(" Candidato %d\n letra : %c\n votos : %d\n\n",i, win[i].candidatoV, win[i].qntV);
    }*/
    system("pause");

}

void main()
{
#define encerra 3
    int menuSelect;
    inicializar();
    do
    {
        system("cls");
        menuSelect=menu();

        switch(menuSelect)
        {
        case 1:
            votar();
            break;
        case 2:
            resultado();
            break;
        }
    }
    while(menuSelect!=encerra);
}

