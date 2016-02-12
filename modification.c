#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int num_produit;
        char lib_produit[30];
        float prix_produit;
}produit;

int main()
{
    // compatibilité des accents
    system("mode con codepage select=1252");
    system("cls");

    produit unProduit;

    FILE*ficheProduit;
    produit tabProduit[100];
    int i;
    int choix;

    // initialisation du tableau à 0
    for (i = 0; i < 100; i++)
    {
        tabProduit[i].num_produit = 0;
        strcpy(tabProduit[i].lib_produit, "\0");
        tabProduit[i].prix_produit = 0;
    }

    printf("Quel numéro voulez vous modifier ? ");
    scanf("%d", &choix);

    ficheProduit = fopen("Produit", "r");
    fread(&unProduit, sizeof(produit), 1, ficheProduit);

    i = 0;

    while(!feof(ficheProduit))
    {
        tabProduit[i].num_produit = unProduit.num_produit;
        printf("%d\n", tabProduit[i].num_produit);

        strcpy(tabProduit[i].lib_produit, unProduit.lib_produit);
        printf("%s\n", tabProduit[i].lib_produit);

        tabProduit[i].prix_produit = unProduit.prix_produit;
        printf("%f\n\n", tabProduit[i].prix_produit);

        i++;
    }
    printf("ok");

    fclose(ficheProduit);
return 0;
}
