#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 20

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Ouvrir le fichier en mode écriture (création ou troncature)
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    printf("Numb --> ");

    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytesRead] = '\0'; // Assurer la terminaison de la chaîne

        // Vérifier si l'entrée est un nombre valide
        char *endptr;
        strtol(buffer, &endptr, 10);
        if (*endptr != '\n' && *endptr != '\0') {
            fprintf(stderr, "Entrée invalide, veuillez entrer un nombre valide.\n");
            printf("Numb --> ");
            continue;
        }

        // Écriture du nombre dans le fichier
        if (write(fd, buffer, bytesRead) != bytesRead) {
            perror("Erreur d'écriture dans le fichier");
            close(fd);
            return EXIT_FAILURE;
        }

        printf("Numb --> ");
    }

    if (bytesRead == -1) {
        perror("Erreur de lecture");
    }

    printf("\nFin de saisie détectée.\n");
    close(fd);
    return EXIT_SUCCESS;
}
