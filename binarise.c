// DI PRIMA Thibaut


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binarise.h"
#include "struct.h"
#include "fonctionannexe.h"

/*
 * @param : tmp : sera la valeur contenu dans une case de la matrice de la structure
 * @param : valmax : est la valeur max du fichier image
 * retourne le résultat du calcule : R(p)*G(p)*B(p)/(valmax^3)
 */

double binariseRGB(uint64_t tmp,uint32_t valmax){
   double newPixel= (masqueNBit(32,16,tmp)*masqueNBit(16,16,tmp)*masqueNBit(0,16,tmp))/((double)(valmax*valmax*valmax));
   return newPixel;
}

/*
 * @param test : est la structure
 * @alpha : valeur entrée par l'utilisateur
 * la procédure parcours la structure et va inscrire dans chanque case de la matrice un 1 ou un 0 suivant l'algo de l'énoncé
 */

void modificationStructureBinarise(DI test,float alpha){
    int i=0,j;
    double val;
    while(i<test.hauteur){
        j=0;
        while(j<test.largeur){
            val = binariseRGB(test.tab[i][j],test.valmax);
            if(val<alpha)
                test.tab[i][j]=1;
            else test.tab[i][j]=0;
            j++;
        }
        i++;
    }
}
/*
 * va écrire dans le fichier mis en parametre suivant ce que contient la structure
 * le fichier résultant étant un fichier P1
 */

void ecritureFichierP1(DI test, FILE* fichierec){
	int i = 0,j;	
	//FAIRE LA VERIF DE L OPTION POUR P1 ou P2
	fprintf(fichierec,"%s\n","P1");
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

void ppmToPbm(DI test,float alpha, FILE* fichier){
	modificationStructureBinarise(test,alpha);
	ecritureFichierP1(test,fichier);
}
