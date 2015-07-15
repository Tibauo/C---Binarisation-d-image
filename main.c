// DI PRIMA Thibaut

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionannexe.h"
#include "gestion.h"
#include <errno.h>

// Dans le main on ne fait que envoyer les vers le cas avec fichier ou dans le cas sans fichier

int main (int argc, char *argv[])
{
	char *nomfichier = NULL;
	int option=0;
	printf("-----------  Projet C  -----------\n");
	printf("-----------  Thibaut Augustin Radhoane-----------\n");
	switch(argc){
		case 2 :
			//l'utilisateur n'a entré que deux valeurs l'executable et l'option
			if ((strcmp(argv[1],"-b")!=0) && (strcmp(argv[1],"-g")!=0)){
				//option erronée
				fprintf(stderr,"Erreur, mauvais choix d'option. Seul -b et -g sont autorises\n");
				exit(EXIT_FAILURE);
			}			
			else{
				//si bonne option
				printf("bon il manque le nom du fichier\nVoulez-vous donner le nom du fichier ou entrer les valeurs?\n");
				printf("\t1 : le fichier\n");
				printf("\t2 : Creer le fichier manuellement\n");
				printf("Votre choix : ");
				scanf("%d", &option);
				getchar();
				printf("\n");
				switch (option)
				{
						// L'utilisateur n'a pas entré de fichier mais souhaite en entrer un maintenant
					case 1 :
						printf("Entrer le nom de votre fichier : \n");
						nomfichier=creationChaine();
						printf("vous avez ecrit : ");
						affiche(nomfichier);
						printf("\n");
						casoptionavecfichier(nomfichier, argv[1]);
					break;
						// L'utilisateur souhaite enregistrer les valeurs manuellement
					case 2 :
						printf("Entrer le nom de votre fichier pour la sortie: \n");
						nomfichier=creationChaine();
						printf("Vous allez entrer les valeurs\n");
						casoptionsansfichier(nomfichier, argv[1]);
					break;
						// Tous les autres cas sont des erreurs
					default :
						fprintf(stderr,"Erreur aucun choix ne correspond\n");
						exit(EXIT_FAILURE);
					break;
				}
			}
			break;	
		case 3 :
			//l'utilisateur a entré 3 valeurs l'executable l'option et le fichier
			if ((strcmp(argv[1],"-b")!=0) && (strcmp(argv[1],"-g")!=0)){
				// le cas ou le fichier n'est pas bon
				fprintf(stderr,"Erreur, mauvais choix d'option. Seul -b et -g sont autorises\n");
				exit(EXIT_FAILURE);
			}
			else{
				//l'option existe et le fichier est passé.
				nomfichier=argv[2];
				casoptionavecfichier(nomfichier, argv[1]);
			}
			break;
		default :
			// erreur on explique comment utiliser le programme
			printf("./project -b/-g nomfichier\n");
			break;
	
	
	}
	return 0;
}
