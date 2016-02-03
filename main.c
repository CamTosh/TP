#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int num_produit;
	char lib_produit[30];
	float prix;

} produit;
produit unProduit;


void echange(produit *tabproduit, int i)
{
    int num;
    char lib[30];
    int prix;

    num = tabproduit[i].num_produit;
    strcpy(lib, tabproduit[i].lib_produit);
    prix = tabproduit[i].prix;

    tabproduit[i].num_produit = tabproduit[i+1].num_produit;
    strcpy(tabproduit[i].lib_produit, tabproduit[i+1].lib_produit);
    tabproduit[i].prix = tabproduit[i+1].prix;

    tabproduit[i+1].num_produit = num;
    strcpy(tabproduit[i+1].lib_produit, lib);
    tabproduit[i+1].prix = prix;
}


void triFichier(produit *tabProduit, int sens, int j) {

    int permut = 1;
    int i;

	while(permut == 1){
		permut = 0;
		for (i = 0; i <= j; i++)
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

    FILE*ficheProduit;
    produit tabProduit[100];
    int i;
    int sens = 0;
    int j;

    ficheProduit = fopen("Produit","r");
    fseek(ficheProduit, 0, SEEK_SET);

	printf("Ordre croissant (0) décroissant (1) : ");
	scanf("%d", &sens);

    fread(&unProduit, sizeof(produit), 1, ficheProduit);
    i = 0;
    while(!feof(ficheProduit))
    {
        tabProduit[i].num_produit = unProduit.num_produit;
        strcpy(tabProduit[i].lib_produit, unProduit.lib_produit);
        tabProduit[i].prix = unProduit.prix;
        i++;

        fread(&unProduit, sizeof(produit), 1, ficheProduit);
    }
    j = i;

    fclose(ficheProduit);

    triFichier(tabProduit, sens, j);

    remove(ficheProduit);
    ficheProduit = fopen("Produit","w");

    for (i = 0; i < j; i++)
    {
        printf("num produit %d\n", tabProduit[i].num_produit);
        printf("lib produit %s\n", tabProduit[i].lib_produit);
        printf("prix produit %f\n", tabProduit[i].prix);

        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.lib_produit , tabProduit[i].lib_produit);
        unProduit.prix = tabProduit[i].prix;

        fwrite(&unProduit, sizeof(unProduit), 1, ficheProduit);
    }
    fclose(ficheProduit);
}
