#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{

	int num_produit;
	char lib_produit;
	float prix_produit;

} produit;
produit unProduit;


void echange(produit *tabProduit, int i){

	int num;
	char lib;
	int prix;

	num = tabProduit[i].num_produit;
	strcpy(lib, tabProduit[i].lib_produit);
	prix = tabProduit[i].prix_produit;

	tabProduit[i + 1].num_produit = num;
	strcpy(tabProduit[i].lib_produit, tabProduit[i+1].lib_produit);
	tabProduit[i].prix_produit = tabProduit[i + 1].prix_produit;

	tabProduit[i+1].num_produit = num;
	strcpy(tabProduit[i+1].lib_produit, lib);
	tabProduit[i+1].prix_produit = prix;
}

void triFichier(produit *tabProduit, int sens, int j) {

    int permut = 1;
    int i;

	echange(tabProduit, i);

	while(permut == 1){
		permut = 0;
		for (i = 1; i <= j; i++)
		{
			if(sens == 0){
				if (tabProduit[i].num_produit > tabProduit[i + 1].num_produit){
					echange(tabProduit, i);
					permut = 1;
				}
			}
			if(sens == 1){
				if (tabProduit[i].num_produit < tabProduit[i + 1].num_produit){
					echange(tabProduit, i);
					permut = 1;
				}
			}
		}
	}
}

int main()
{
    system("mode con codepage select=1252"); // acceptation des accents
    system("cls"); // vidage de la console

    FILE*ficheProduit;
    produit tabProduit[100];
    int i;
    int sens = 1;
    int j;
    int type;

    ficheProduit = fopen("Produit","r");
    fseek(ficheProduit, 0, SEEK_SET);

	printf("Ordre croissant : 0 \t");
	printf("Ordre decroissant : 1 ");
	scanf("%d", &sens);

    fread(&unProduit,sizeof(produit),1,ficheProduit);
    i = 0;
    while(!feof(ficheProduit))
    {
        tabProduit[i].num_produit = unProduit.num_produit;
        strcpy(tabProduit[i].lib_produit, unProduit.lib_produit);
        tabProduit[i].prix_produit = unProduit.prix_produit;
        i++;

        fread(&unProduit,sizeof(produit),1,ficheProduit);
    }
    j = i;

    fclose(ficheProduit);

    triFichier(tabProduit, sens,j);

    remove(ficheProduit);
    ficheProduit = fopen("Produit","w");

    for (i = 0; i < j; i++)
    {
        printf("num produit %d \n", tabProduit[i].num_produit);
        printf("lib produit %s\n", tabProduit[i].lib_produit);
        printf("prix produit %s\n", tabProduit[i].prix_produit);

        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.lib_produit , tabProduit[i].lib_produit);
        unProduit.prix_produit = tabProduit[i].prix_produit;

        fwrite(&unProduit,sizeof(unProduit),1, ficheProduit);
    }
    fclose(ficheProduit);
}
