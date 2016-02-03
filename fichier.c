int f1(){

    int i;
    int *numProduit[] = {5, 10, 12, 6, 7, 8};
    char *lib[] = {"Arrosoir", "Barbecue", "Carotte", "Double_décimètre", "Equerre", "Fouet"};
    int *prix[] = {10, 50, 1, 3, 2, 2};
    int r;

    FILE* ficheProduit = fopen( "produits.myd", "w+" );

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

    for(i = 1; i < 6; i++){
        /*
        fwrite(&i, sizeof(i), i, ficheProduit);
        fwrite(&lib[i], sizeof(lib[i]), i, ficheProduit);
        fwrite(&prix, sizeof(prix), i, ficheProduit);
        */
        fprintf(ficheProduit, "%d %s %d\n", numProduit[i], lib[i], prix[i]);
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

int f2(){

    int i;
    int *numProduit[] = {5, 10, 12, 6, 7, 8};
    int *position[] = {1, 2, 3, 4, 5, 6};
    int h;

    FILE* ficheProduit = fopen( "produits.myi", "w+" );

    if(ferror(ficheProduit)){
        printf("Erreur de lecture du fichier\n");
        fclose(ficheProduit);
    }
    if(!ficheProduit){
        remove(ficheProduit);
        printf("Supression du fichier. \n");
        ficheProduit =  fopen( "produits.myi", "w+" );
    }

    fseek(ficheProduit, 0, SEEK_SET);

    for(i = 1; i < 6; i++){
        fprintf(ficheProduit, "%d %d\n", numProduit[i], position[i]);
    }

        if (ficheProduit == 0) {
                h = 0;
                printf("Le fichier .myd est vide \n");
            }
        if (ficheProduit != 0) {
                h = 1;
                printf("Le fichier .myi est ecrit.\n");
            }
    fclose(ficheProduit);
return h;
}
