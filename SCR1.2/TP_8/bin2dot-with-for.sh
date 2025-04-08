#!/bin/bash

# Vérification du nombre d'arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <SRC_FILE> <DEST_FILE>"
    exit 1
fi

SRC_FILE=$1
DEST_FILE=$2

# Vérifier si le fichier source existe
if [ ! -f "$SRC_FILE" ]; then
    echo "Error: Source file '$SRC_FILE' not found!"
    exit 1
fi

# Si le fichier destination existe, demander confirmation avant d'écraser
if [ -f "$DEST_FILE" ]; then
    read -p "$DEST_FILE exists. Overwrite? Yes/No --> " CONFIRM
    if [[ "$CONFIRM" != "Yes" ]]; then
        echo "Operation cancelled."
        exit 1
    fi
fi

# Vider le fichier de destination avant d'écrire
> "$DEST_FILE"

# Lire chaque ligne du fichier source avec une boucle `for`
for addr in $(cat "$SRC_FILE"); do
    # Convertir l'adresse binaire en notation décimale pointée
    decimal_ip=$((2#${addr:0:8})).$((2#${addr:8:8})).$((2#${addr:16:8})).$((2#${addr:24:8}))

    # Écrire dans le fichier de destination
    echo "$decimal_ip" >> "$DEST_FILE"
done

echo "Conversion completed. Results saved in $DEST_FILE."
exit 0
