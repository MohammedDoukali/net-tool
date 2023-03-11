#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

char *convert_bits(unsigned char octet)
{
	int				idx;
	unsigned char	mask;
	unsigned char	bit;
    char *str;
    int i;

    i = 0;
	idx = 7;
	mask = 1;
    str = malloc (9 * sizeof(char));
    str[8] = '\0';
	while (idx >= 0)
	{
		bit = (((octet >> idx) & mask) + '0');
		str[i] = bit;
        i++;
		idx--;
	}
    return(str);
}
char *rev_mask(char *p)
{
    int i = 0;
    char *p2;
    p2 = malloc (9);
    p2[8]  = '\0';
        while (p[i])
        {
            if (p[i] == '1')
                p2[i] = '0';
            else
                p2[i] = '1';
        i++;
        }
    return(p2);
}
char    *ft_and(char *str, char *str2)
{
    char    *p;
    int     i;


    p = malloc (9*sizeof(char));
    i = 0;
    while (str[i])
    {
        if (str[i] == '0' || str2[i] == '0')
            p[i] = '0';
            else
            p[i] = '1';
        i++;
    }
    p[i]= '\0';
    return(p);
}
char *ft_or(char *str, char *str2)
{
    char    *p;
    int     i;


    p = malloc (9*sizeof(char));
    i = 0;
    while (str[i])
    {
        if (str[i] == '1' || str2[i] == '1')
            p[i] = '1';
            else
            p[i] = '0';
        i++;
    }
    p[i]= '\0';
    return(p);
}
char *ft_and_or(char *s1, char *s2,int indice)
{
    char *str;
    char *str2;
    char *p;
    int a;
    int b;
    a = atoi(s1);
    b = atoi(s2);
    str = convert_bits(a);
    str2 = convert_bits(b);
    if (indice == 1)
    {
        str2 = rev_mask(str2) ;
    }
    if (indice == 0)
        p = ft_and(str,str2);
    else
        p = ft_or(str,str2);
    return(p);
}
 
int puissance(int x, int y)
{
    int compteur, resultat;
 
    compteur = 0;
    resultat = 1;
 
    while (compteur < y){
        resultat = resultat * x;
        compteur ++;
    }
 
    return resultat;
}
int bits_dec(char *str)
{
    int i = 7;
    int dec = 0;
    while (i >= 0)
    {
        if (str[i] == '1')
            dec += puissance(2,7-i); 
        i--;
    }
    return(dec);
}

int main()
{
    int i = 0;
    char ip[50];
    char mask[50];
    char **p;
    char **p2;
    printf("what is youre adresse Ip    ->: ");
    scanf("%s",ip);
    printf("what is youre adresse mask  ->: ");
    scanf("%s",mask);   
    printf("\n       .................................\n");
    printf("\n       .................................\n\n");

   p = ft_split(ip,'.');
   p2 = ft_split(mask,'.');

   printf("Network   --> : ");
   while (i < 4)
   {
   printf("%d",bits_dec(ft_and_or(p[i],p2[i],0)));
   if (i < 3)
      printf(".");
   i++;
   }

    i = 0;
   printf("\n       Host Range --> : ");
   while (i < 4)
   {
    if (i != 3)
        printf("%d",bits_dec(ft_and_or(p[i],p2[i],0)));
   else
        printf("%d",bits_dec(ft_and_or(p[i],p2[i],0)) + 1);
   if (i < 3)
      printf(".");
   i++;
   }
    printf(" ------> ");  
        i = 0;
        while (i < 4)
        {
            if (i != 3)
             printf("%d",bits_dec(ft_and_or(p[i],p2[i],1)));
            else
            printf("%d",bits_dec(ft_and_or(p[i],p2[i],1)) - 1);
         if (i < 3)
             printf(".");
        i++;
        }
    i = 0;
        printf("\nBrodcats  --> : ");  
        i = 0;
        while (i < 4)
        {
         printf("%d",bits_dec(ft_and_or(p[i],p2[i],1)));
         if (i < 3)
             printf(".");
        i++;
        }
        printf("\n");
}