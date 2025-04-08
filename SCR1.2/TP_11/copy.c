#include<stdio.h>
#include<stdlib.h>
#define TRANCHE 256

int main(int argc, char **argv) {
    FILE *flux = NULL, *flux2 = NULL;
    flux = fopen(argv[argc - 2], "r");
    if (flux == NULL) {
        perror("erreur d'ouverture de fichier.");
        exit(EXIT_FAILURE);
    }
    flux2 = fopen(argv[argc - 1], "w");
    if (flux == NULL) {
        perror("erreur d'ouverture de fichier.");
        exit(EXIT_FAILURE);
    }
    while(!feof(flux)) {
        char buffer[TRANCHE];
        fread(buffer, sizeof(char), TRANCHE, flux);
        if (ferror(flux)) {
            perror("erreur de lecture du fichier.");
            exit(EXIT_FAILURE);
        }
        fwrite(buffer, sizeof(char), TRANCHE, flux2);
    }
    return EXIT_SUCCESS;
}