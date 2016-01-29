#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i;
	int *numProduit[] = {"5", "10", "12", "6", "7", "8 "};
	char *lib[] = {"Arrosoir", "Barbecue", "Carotte", "Double décimètre", "Equerre", "Fouet"};
	int *prix[] = {"10", "50", "1", "3", "2", "2 "};
	//int prix = i * 1.5;
	int r;

    FILE* ficheProduit =  fopen( "produits.myd", "w+" );

    if(ferror(ficheProduit)){
    	printf("Erreur de lecture du fichier\n");
    	fclose(ficheProduit);
    }
    if(!ficheProduit){
        remove(ficheProduit);
        printf("Supression du fichier. \n");
        ficheProduit =  fopen( "produits.myd", "w+" );
    }

    fseek(ficheProduit, 0, SEEK_SET);

	for(i = 1; i < 9; i++){
        /*
		fwrite(&i, sizeof(i), i, ficheProduit);
		fwrite(&lib[i], sizeof(lib[i]), i, ficheProduit);
		fwrite(&prix, sizeof(prix), i, ficheProduit);
		*/
		fprintf(ficheProduit, "%d %d %d\n", &numProduit[i], &lib[i], &prix[i]);
	}

        if (ficheProduit == 0) {
                r = 0;
                printf("Le fichier est vide \n");
            }
        if (ficheProduit != 0) {
                r = 1;
                printf("Le fichier est ecrit.\n");
            }
    fclose(ficheProduit);
return r;
}

