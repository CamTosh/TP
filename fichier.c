#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num_produit[10];
    char lib_produit[40];
    int prix[10];

} produit;

int main(int argc, char const *argv[]){
produit unProduit;

/*
    int num_produit[] = {'5 ', '10 ', '12 ', '6 ', '7 ', '8 '};
    char *lib_produit[] = {"Arrosoir ", "Barbecue ", "Carotte ", "Double_décimètre ", "Equerre ", "Fouet "};
    int prix[] = {10, 50, 1, 3, 2, 2};
*/
    int r;
    int i = 0;
    FILE* ficheProduit = fopen( "Produit", "w+" );

    int combien;
    printf("Combien de produit ? ");
    scanf("%d", &combien);

    while(i <= combien - 1){
        printf("\n \t Tour %d", i);
        printf("\nNum : ");
        scanf("%d", unProduit.num_produit);

        printf("Lib : ");
        scanf("%s", unProduit.lib_produit);

        printf("Prix : ");
        scanf("%d", unProduit.prix);

        fwrite(&unProduit, sizeof(produit), 1, ficheProduit);
        i++;
    }

    if (ficheProduit != 0) {
        r = 1;
        printf("\n Le fichier est ecrit.\n");
    }
    /*
    i = 0;

    while(i <= combien - 1){
        printf("\n \t Affichage du tour %d \n", i);
        printf("Num : %d\n", *unProduit.num_produit);
        printf("Lib : %s\n", unProduit.lib_produit);
        printf("Prix : %d\n", *unProduit.prix);
        i++;
    }
    */

    fclose(ficheProduit);
    /*
    int *numProduit[] = {5, 10, 12, 6, 7, 8};
    int *position[] = {1, 2, 3, 4, 5, 6};
    */

return r;
}
