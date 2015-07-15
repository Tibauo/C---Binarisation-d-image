// DI PRIMA Thibaut
#ifndef __STRUCTURE__
#define __STRUCTURE__
#include <inttypes.h>

enum typeimage {P1=1, P2=2, P3=3};
typedef struct DonneImage{
	enum typeimage p;
	uint32_t largeur, hauteur;
	uint32_t valmax;
	uint64_t **tab;
}DI;

DI CreationStructsansfichier();
void AfficheStruct(DI test);
DI CreationStructavecfichier(FILE* fichier);
void liberer(DI test);

#endif /*Structure*/
