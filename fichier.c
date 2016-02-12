#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num_produit;
    char lib_produit[30];
    float prix_produit;

} produit;

int main(){
produit unProduit;

/*
    int num_produit[] = {'5 ', '10 ', '12 ', '6 ', '7 ', '8 '};
    char *lib_produit[] = {"Arrosoir ", "Barbecue ", "Carotte ", "Double_décimètre ", "Equerre ", "Fouet "};
    int prix[] = {10, 50, 1, 3, 2, 2};
*/
    int r;
    int i = 0;
    FILE* ficheProduit = fopen( "Produit", "w" );

    produit tabProduit[100];

    int combien;
    printf("Combien de produit ? ");
    scanf("%d", &combien);

    for (i = 0; i < 100; i++)
    {
        tabProduit[i].num_produit = 0;
        strcpy(tabProduit[i].lib_produit, "\0");
        tabProduit[i].prix_produit = 0;
    }
    i = 0;
    while(i <= combien - 1){

        printf("\n \t Tour %d", i);
        printf("\nNum : ");
        scanf("%d", &unProduit.num_produit);

        printf("Lib : ");
        scanf("%s", unProduit.lib_produit);

        printf("Prix : ");
        scanf("%f", &unProduit.prix_produit);

        fwrite(&unProduit, sizeof(produit), 1, ficheProduit);
        i++;
    }

    if (ficheProduit != 0) {
        r = 1;
        printf("\n Le fichier est ecrit.\n");
    }

    i = 0;

    fclose(ficheProduit);
    ficheProduit = fopen("Produit", "r");


    while(i <= combien - 1){
        fread(&unProduit, sizeof(produit), 1, ficheProduit);

        printf("\n \t Affichage du tour %d \n", i + 1);
        printf("Num : %d\n", unProduit.num_produit);
        printf("Lib : %s\n", unProduit.lib_produit);
        printf("Prix : %f\n", unProduit.prix_produit);

        i++;
    }


    fclose(ficheProduit);
    /*
    int *numProduit[] = {5, 10, 12, 6, 7, 8};
    int *position[] = {1, 2, 3, 4, 5, 6};
    */

return r;
}
