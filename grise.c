// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "grise.h"
#include "struct.h"
#include "fonctionannexe.h"


/*
 * @param : tmp : sera la valeur contenu dans une case de la matrice de la structure
 * @param : a,b,c : valeurs entrées par l'utilisateur
 * retourne le résultat du calcul : a*R(p)+b*R(p)+c*R(c)
 */

uint64_t griseRGB(uint64_t tmp, float a, float b, float c){
    uint64_t newPixel=(((uint64_t)(a*masqueNBit(32,16,tmp))))+(((uint64_t)(b*masqueNBit(16,16,tmp))))+((uint64_t)(c*masqueNBit(0,16,tmp)));
    
    return newPixel;
}

/*
 * @param test : est la structure
 * la procédure parcours la structure et va inscrire dans chanque case de la matrice une valeur donné par la procedure precedente
 */

void modificationStructureGrise(DI test,float a, float b, float c){
    int i=0,j;
    while(i<test.hauteur){
        j=0;
        while(j<test.largeur){
            test.tab[i][j]=griseRGB(test.tab[i][j],a,b,c);
            j++;
        }
        i++;
    }
}
/*
 * va écrire dans le fichier mis en parametre suivant ce que contient la structure
 * le fichier résultant étant un fichier P2
 */

void ecritureFichierP2(DI test, FILE* fichierec){
	int i = 0,j;	
	//FAIRE LA VERIF DE L OPTION POUR P1 ou P2
        fprintf(fichierec,"%s\n","P2");
	fprintf(fichierec,"%u ",test.largeur);
	//Hauteur
	fprintf(fichierec,"%u\n",test.hauteur);
	//Max value
	fprintf(fichierec, "%u\n", test.valmax);

	// IL FAUT SEPARER LE UINT64_t EN TROIS POUR ECRIRE RGB 
        while(i<test.hauteur){
            j=0;
            while(j<test.largeur){
                fprintf(fichierec,"%llu ",test.tab[i][j]);
                j++;
            }  
            i++;
            fprintf(fichierec,"%s","\n");
        }
	
}

/*
 * procedure final qui finialise le fichier et permet de binariser une image
 */

void ppmToPgm(DI test,float a,float b, float c, FILE* fichier){
	modificationStructureGrise(test,a,b,c);
	ecritureFichierP2(test,fichier);
	//~ fclose(fichier); //On le fait après
}
