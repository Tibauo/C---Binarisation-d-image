// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "struct.h"

//On gère tout ce qu'y est lié à la structure


/**
 Affiche la structure
 */


void AfficheStruct(DI test)
{
	int i = 0;
	int j = 0;

	//Let's print data:
	printf("Type : %u\n",test.p);
	printf("largeur : %u\n",test.largeur);
	printf("hauteur : %u\n",test.hauteur);
	printf("Maxval : %u\n", test.valmax);
	for(i = 0; i <  test.hauteur; i++){
		for(j = 0; j < test.largeur; j++)
			printf("%lli ", test.tab[i][j]);
		printf("\n");
	}
}

/**
 On crée la structure à partir des informations que l'utilisateur tape dans le terminal
 */

DI CreationStructsansfichier(){
	struct DonneImage test;
	int i = 0;
	int j = 0;
	int k = 0;
	uint64_t tmp = 0;

	//Read type
	//TODO: check value ..
	printf("Nous allons creer une structure pour enregistrer les valeurs\n");
	test.p=3;
	//Larg & long
	printf("Largeur : ");	
	scanf("%u",&test.largeur);
	printf("\nhauteur : ");
	scanf("%u",&test.hauteur);

	//Max value
	printf("\n Valeur max : ");	
	scanf("%u", &test.valmax);
	
	
	//Allocating data..
	test.tab = malloc(sizeof(uint64_t*) * test.hauteur);
	for(i = 0; i < test.hauteur; i++)
		test.tab[i] = malloc(sizeof(uint64_t) * test.largeur);
	
	//Let's read & write things
	for(i = 0; i < test.hauteur; i++){
		printf("les 3 valeurs sont : \n");
		for(j = 0; j < test.largeur; j++){
			for (k = 0 ; k < 3;  k++) {
				scanf("%llu", &tmp);
				if (tmp>test.valmax) {
					fprintf(stderr,"Erreur il existe une valeur superieure a la valeur max\n");
					exit(EXIT_FAILURE);
				}
				
				switch (k) {
					case 0:
						test.tab[i][j]=(tmp<<32);
						break;
					case 1:
						test.tab[i][j]=	(test.tab[i][j])|(tmp<<16);
						break;
					default:
						test.tab[i][j]=	(test.tab[i][j])|tmp;
						break;
				}
				
			}
		}
	}
	
	return test;
}

/**
 Ce programme lis le fichier donné par l'utilisateur, vérifie que c'est le bon type. Et enregistre les informations dans la structure
 */

DI CreationStructavecfichier(FILE* fichier)
{
	struct DonneImage test;
	char type[3];
	uint64_t tmp;
	int i = 0;
	int j = 0;
	int k = 0;

	//Read type
	//TODO: check value ..
	fread(type, 3 * sizeof(char), 1, fichier);
	type[2] = '\0';
	if(strcmp(type,"P3")==0)
	{
		test.p=3;	
	}
	else
	{
		if(strcmp(type,"P2")==0)
		{
			fprintf(stderr,"En effet le format du fichier ne convient pas\nIl doit forcement etre de type P3\n");
			exit(EXIT_FAILURE);
		}	
	}
	
	//Larg & long
	
	fscanf(fichier,"%u",&test.largeur);
	fscanf(fichier,"%u",&test.hauteur);

	//Max value
	fscanf(fichier, "%u", &test.valmax);
	
	
	//Allocating data..
	test.tab = malloc(sizeof(uint64_t*) * test.hauteur);
	for(i = 0; i < test.hauteur; i++)
		test.tab[i] = malloc(sizeof(uint64_t) * test.largeur);

	//Let's write things
	for(i = 0; i < test.hauteur; i++)
	{
		for(j = 0; j < test.largeur; j++)
		{
			for (k = 0 ; k < 3;  k++) {
				fscanf(fichier, "%llu", &tmp);
				if (tmp>test.valmax) {
					fprintf(stderr,"Erreur il existe une valeur superieure a la valeur max\n");
					exit(EXIT_FAILURE);
				}
				switch (k) {
					case 0:
						test.tab[i][j]=(tmp<<32);
						break;
					case 1:
						test.tab[i][j]=	(test.tab[i][j])|(tmp<<16);
						break;
					default:
						test.tab[i][j]=	(test.tab[i][j])|tmp;
						break;
				}
				
			}
		}
	}
	
	return test;
}


/**
 Libère le tableau utiliser
 */

void liberer(DI test){
	int i = 0;
	for(i = 0; i < test.hauteur; i++)
			free(test.tab[i]);
		free(test.tab);
}
 



