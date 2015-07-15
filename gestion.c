// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "fonctionannexe.h"
#include "gestionfichier.h"
#include "grise.h"
#include "binarise.h"

//Le fichier à juste pour but de structurer le programme

//Gère la suite du code des fonction dessous
void suite(char *nomfichier, char *option, DI t, FILE* fichier)
{
	char* newfile = NULL;
	int i = 0;
	printf("Lecture de la structure : \n");
	AfficheStruct(t);
	fermeture(fichier);	
	while(nomfichier[i]!='.')
	{
		i++;
	}

	newfile = malloc(sizeof(char) * (i+5));//i correspond a tous les carac avant le point
					       // 5 correspond au point plus pgm ou pbm plus \0
	i = 0;
	while(nomfichier[i]!='.')
	{
		newfile[i]=nomfichier[i];
		i++;
	}
	if(strcmp(option,"-b")==0){
		newfile=strcat(newfile, ".pbm");
		newfile[strlen(newfile) + 4] = '\0';
	}
	else{
		newfile=strcat(newfile, ".pgm");
		newfile[strlen(newfile) + 4] = '\0';
	}
			
	printf("creation du fichier : ");
	affiche(newfile);
	fichier=creationFichier(newfile);
	
	if(strcmp(option,"-b")==0)
		ppmToPbm(t, 0.15, fichier);
	else
		ppmToPgm(t,0.299,0.587,0.114, fichier);
	liberer(t);
	fermeture(fichier);
}

/**
 C'est le cas ou le fichier est donné par l'utilisateur
 Cette fonction ouvre le fichier en lecture
 */
void casoptionavecfichier(char *nomfichier, char *option)
{
	DI t;
	printf("%s\n", option);
	FILE *fichier = NULL;
	fichier=ouvertureFichier(nomfichier, fichier);	
	t=CreationStructavecfichier(fichier);
	suite(nomfichier, option , t, fichier);	
}

/**
 C'est le cas ou le fichier n'est pas donné en paramètre
 */
void casoptionsansfichier(char *nomfichier, char *option)
{
	DI t;
	FILE *fichier = NULL;
	printf("%s\n", option);
	t=CreationStructsansfichier();
	suite(nomfichier,option, t, fichier);
}




