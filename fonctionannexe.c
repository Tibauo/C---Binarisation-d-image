// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*
 * copi la chaine s2 dans s1 et ajoute en fin de chaine le caractere c
 */
void remplir (char* s1, char* s2,char c){
    int i=0;
    if(s2==NULL){
        *s1=c;
        *(s1+1)='\0';
    }
    else{
        while(*(s2+i)!='\0'){
            *(s1+i)=*(s2+i);
            i++;
        }
        *(s1+i)=c;
        *(s1+i+1)='\0';
    }
    
}
/*
 * creer une chaine de caractere de maniere dynamique
 */

char* creationChaine(){
    char* s1= NULL;
    char* s2= NULL;
    char c;
    int i=1;
    while((c=getchar())!='\n'){
        if((i&1)==1){
            s1=(char *)malloc((i+1)*sizeof(char));
            remplir(s1,s2,c);
            free(s2);
        }
        else{
            s2=(char *)malloc((i+1)*sizeof(char));
            remplir(s2,s1,c);
            free(s1);
        }
        i++;
    }
    if(i==1){
        s1=(char *)malloc(sizeof(char));
        *s1='\0';
        return s1;
    }        
    i++;
    if((i&1)==1)
        return s1;
    else return s2;
}

void affiche(char* c){
    int i=0;
    if(c==NULL)
        printf("NULL");
    else{
        while(*(c+i)!='\0'){
            printf("%c",*(c+i));
            i++;
        }
        if(i==0)
            printf("la chaine est vide");
    }
    printf("\n");
}


/*
 * @param n : nbre de bit
 * @bitMin : bit de depart du masque
 * fait un masque de n bit à partir de bitmin
 */
uint64_t masqueNBit(int bitMin, int n, uint64_t tmp){
    int i = bitMin;
    int j=0;
    uint64_t k=1;
    uint64_t octet=0;
    int taille=bitMin+n;
    while(i<taille){
        k=((uint64_t)1)<<i;
        octet=octet|((k&tmp)>>(i-j));
        i++;
        j++;
    }
    return octet;
}
/*
 * affiche un entier sous sa forme binaire
 */

void afficherBit(int bitMin, int n, uint64_t tmp){
    int i=bitMin+n-1;
    uint64_t k;
    int bit=0;
    while(i>=bitMin){
        k=((uint64_t)1)<<i;
        bit = (tmp&k)>>i;
        printf("%d",bit);
        i--;
    }
    printf("\n");
}
