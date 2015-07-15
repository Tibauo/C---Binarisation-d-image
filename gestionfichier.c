// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include "gestionfichier.h"

/**
 Permet d'ouvrir un fichier en mode lecture
 */

FILE* ouvertureFichier(char *nomfichier, FILE* fichier){
	if ((fichier = fopen(nomfichier, "r"))==NULL){
		fprintf(stderr,"erreur ouverture fichier\nil est possible que le fichier n'existe pas\n");
		exit(EXIT_FAILURE);
	}
	printf("Le fichier a bien ete ouvert\n");
	return(fichier);

}

/**
 Permet d'ouvrir un fichier en mode écriture et de le créer si il n'existe pas
 */

FILE* creationFichier(char *nomfichier){
	FILE *fichier;
	if ((fichier = fopen(nomfichier, "w+"))==NULL){
		fprintf(stderr,"erreur creation fichier\n");
		exit(EXIT_FAILURE);
	}
	printf("Le fichier a bien ete cree\n");
	return(fichier);

}


/**
 Permet de fermer le fichier
 */

void fermeture(FILE* fichier){
	fclose(fichier);
	printf("Le fichier a bien ete ferme\n");
}



