# Makefile pour les programmes écrits durant le cours Informatique I

# Tous les fichiers source
SRC=$(wildcard *.c)
# Tous les exécutables ont le même nom que la source sans le suffixe
EXECUTABLES=$(SRC:.c=)

all: $(EXECUTABLES)

# Tous les exécutables sont compilés depuis la source avec les
# warnings activés (-Wall). Permet de détecter d'éventuelles erreurs.
% :: %.c
	gcc -g -Wall $< -o $@

clean:
	rm -f *.o *~ # efface les éventuels .o et les fichiers backup
	find . -executable -type f -exec rm -f '{}' \; # efface tous les fichiers exécutables.
