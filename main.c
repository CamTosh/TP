#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
    {
        int num_produit;
        char lib_produit[30];
        float prix_produit;
    }produit;
    produit unProduit;

void echange(produit *tabproduit, int i)
{
    int num;
    char lib[30];
    int prix;

    num = tabproduit[i].num_produit;
    strcpy(lib, tabproduit[i].lib_produit);
    prix = tabproduit[i].prix_produit;

    tabproduit[i].num_produit = tabproduit[i+1].num_produit;
    strcpy(tabproduit[i].lib_produit, tabproduit[i+1].lib_produit);
    tabproduit[i].prix_produit = tabproduit[i+1].prix_produit;

    tabproduit[i+1].num_produit = num;
    strcpy(tabproduit[i+1].lib_produit, lib);
    tabproduit[i+1].prix_produit = prix;
}

void triFichier(produit *tabProduit, int sens, int j)
{
    int permut;
    permut = 1;
    int i;

    while (permut ==1)
    {
        permut = 0;
        for(i =0; i<j-1;i++)
        {
            if(sens==1)
            {
                if(tabProduit[i].num_produit > tabProduit[i+1].num_produit)
                {

                    echange(tabProduit, i);
                    permut = 1;
                }
            }
            else if (sens == 2)
            {
                if(tabProduit[i].num_produit < tabProduit[i+1].num_produit)
                {
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

    FILE*fichProduit;
    produit tabProduit[100];
    int i;
    int sens = 1;
    int j;
    int type;

    fichProduit = fopen("propro","r");

    for (i = 0; i < 100; i++)
    {
        tabProduit[i].num_produit = 0;
        strcpy(tabProduit[i].lib_produit, "");
        tabProduit[i].prix_produit = 0;
    }

    printf("Tri Croissant(1) ou décroissant(2) ? : ");
    scanf("%d", &sens);
    fread(&unProduit,sizeof(produit),1,fichProduit);
    i = 0;

    while(!feof(fichProduit))
    {
        tabProduit[i].num_produit = unProduit.num_produit;
        strcpy(tabProduit[i].lib_produit, unProduit.lib_produit);
        tabProduit[i].prix_produit = unProduit.prix_produit;
        i++;

        fread(&unProduit,sizeof(produit),1,fichProduit);
    }
        j = i;
    fclose(fichProduit);

    triFichier(tabProduit, sens,j);
    remove("propro");
    fichProduit = fopen("propro","w");

    for (i=0;i<j;i++)
    {
        printf("num_produit : %d \n lib_produit : %s \n prix : %f\n\n",tabProduit[i].num_produit, tabProduit[i].lib_produit, tabProduit[i].prix_produit);
        unProduit.num_produit = tabProduit[i].num_produit;
        strcpy(unProduit.lib_produit , tabProduit[i].lib_produit);
        unProduit.prix_produit = tabProduit[i].prix_produit;
        fwrite(&unProduit,sizeof(unProduit),1, fichProduit);
    }
    fclose(fichProduit);
}
