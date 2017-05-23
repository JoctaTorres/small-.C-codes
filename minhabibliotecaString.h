#include <stdio.h>
#include <ctype.h>

int strlen(char *s) /* String Length */
{
    //retorna o número de carateres do vetor da string sem contar com o delimitador
    int comprimento;
    for ( comprimento=1 ; *s != '\0' ; s++)
    {
        ++comprimento;
    }
    return comprimento;
}

int strlen2(char *s) /* String Length2 */
{
    //retorna o número de carateres do vetor da string contando com o delimitador
    int comprimento;
    for ( comprimento=0 ; *s != '\0' ; ++comprimento, s++) ;
    return comprimento;
}

int strcpy(char *s, char *c) /* String Copy */
{
    /*  pq o tipo de retorno tem que ser int??
        retorno dessa função em  com os tipos void ou char apresentam o seguing erro(aviso):

        22|warning: conflicting types for built-in function 'strcpy'|
    */

    while(*s!='\0')
    {
        *c = *s;
        s++ ; c++ ;
    }*c='\0';
}

/* int strcpy(char *s, char *c)
{
    int lens=strlen2(s);
    int lenc=strlen2(c);
    if (lens<=lenc);
    {
        while(*s!='\0')
    {
        *c = *s;
        s++ ;
        c++ ;
    }*c='\0';
    }
}
*/

void memcopy(char *s, char *c, int n) /*Copia os 'n' primeiros caracteres da string 's' e coloca nas primeiros 'n' caracteres da string 'c'. */
{
    int i;
    for(i=0; i<n; i++)
    {
        *c = *s;
        s++ ; c++ ;
    }
}

int strcountc(char *s, char c) /* String Count Char */
{
    int n=0; // nº de ocorrências do char c
    while (*s != '\0')
    {
        if(*s==c) { n++; }
        s++;
    } return n;
}

int strcountd(char *s) /* String Count Digits */
{
    int n;
    for (n=0 ; *s!='\0'; ++s)
    {
        if ( isdigit(*s) ) {n++;}
    } return n ;

}

void strupr(char *s) /* String Uppercase */
{
    while (*s != '\0')
    {
        *s=toupper(*s);
        ++s;
    }
}

void strchdel (char *s, char c) /* Coloca um blank nas ocorrências do char c na string s*/
{
    while (*s != '\0')
    {
        if (*s == c) {*s = ' ';}
        ++s;
    }
}


