#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num_produit[5];
    char lib_produit[5];
    int prix[5];

} produit;

int main(int argc, char const *argv[]){
produit unProduit;

/*
    int num_produit[] = {'5 ', '10 ', '12 ', '6 ', '7 ', '8 '};
    char *lib_produit[] = {"Arrosoir ", "Barbecue ", "Carotte ", "Double_décimètre ", "Equerre ", "Fouet "};
    int prix[] = {10, 50, 1, 3, 2, 2};
*/
    int r;
    int i = 1;
    FILE* ficheProduit = fopen( "Produit", "w+" );

    int combien;
    printf("Combien de produit ? ");
    scanf("%d", &combien);

    while(i <= combien){
        printf("\n \t Tour %d", i);
        printf("\nNum produit : ");
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
        printf("Le fichier est ecrit.\n");
    }

    fread(&unProduit, sizeof(produit), 1, ficheProduit);
    printf("Num : %d \n", unProduit.num_produit);
    printf("Lib %s\n", unProduit.lib_produit);
    printf("Prix %d\n", unProduit.num_produit);

    fclose(ficheProduit);
    /*
    int *numProduit[] = {5, 10, 12, 6, 7, 8};
    int *position[] = {1, 2, 3, 4, 5, 6};
    */
return r;
}
