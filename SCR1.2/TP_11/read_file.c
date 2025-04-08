#include<stdio.h>
#include<stdlib.h>
#define TRANCHE 256

int main(int argc, char **argv) {
    FILE* flux = NULL;
    printf("%s", argv[argc - 1]);
    flux = fopen(argv[argc - 1], "r");
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
        printf("%s", buffer);
    }
    return EXIT_SUCCESS;
}