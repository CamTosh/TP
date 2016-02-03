#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fichier.c"

typedef struct
{

	int num_produit;
	char lib_produit;
	int prix_produit;

} produit;
produit unProduit;


void echange(unProduit tabProduit[], int i){

	int num;
	char lib;
	int prix;

	num = tabProduit[i].num_produit;
	lib = tabProduit[i].lib_produit;
	prix = tabProduit[i].prix_produit;

	tabProduit[i + 1].num_produit;
	tabProduit[i + 1].lib_produit;
	tabProduit[i + 1].prix_produit;

	tabProduit[i].num_produit = num;
	tabProduit[i].lib_produit = lib;
	tabProduit[i].prix_produit = prix;
}

int triFichier(unProduit *tabProduit[], int sens) {

    int permut = 1;
    int i;

	echange(tabProduit, i);

	while(permut == 1){
		permut = 0;
		for (i = 1; i <= 99; i++)
		{
			if(sens == 0){
				if (tabProduit[i].num_produit > tabProduit[i + 1].num_produit){
					echange(tabProduit[i], i);
					permut = 1;
				}
			}
			if(sens == 1){
				if (tabProduit[i].num_produit < tabProduit[i + 1].num_produit){
					echange(tabProduit[i], i);
					permut = 1;
				}
			}
		}
	}
return tabProduit;
}

int main() {

	f1(); // produits.myd
	f2(); // produits.myi

	int sens;
    int i;
    unProduit tabProduit[100];

	FILE* ficheProduit;
	ficheProduit = fopen("fichier", "w+");

	if(ficheProduit == 0){
		fclose(ficheProduit);
	}

	fseek(ficheProduit, 0, SEEK_SET);

	printf("Ordre croissant : 0 \n");
	printf("Ordre decroissant : 1 \n");
	scanf("%d", &sens);

	triFichier(tabProduit, sens);
	/*
	while(getc(ficheProduit) != EOF){
		tabProduit[i].num_produit = unProduit.num_produit;
		tabProduit[i].lib_produit = unProduit.lib_produit;
		tabProduit[i].prix_produit = unProduit.prix_produit;
		i++;
	}
	fclose(ficheProduit);

	tabProduit = triFichier(tabProduit, sens);
	remove(ficheProduit);

	ficheProduit = fopen("fichier", "w+");

	for (i = 0; i < 100; ++i)
	{
		printf("num produit %d \n", tabProduit[i].num_produit);
		printf("lib produit %s\n", tabProduit[i].lib_produit);
		printf("prix produit %s\n", tabProduit[i].prix_produit);

		unProduit.num_produit = tabProduit[i].num_produit;
		*unProduit.lib_produit = tabProduit[i].lib_produit;
		unProduit.prix_produit = tabProduit[i].prix_produit;
	}
	*/
}