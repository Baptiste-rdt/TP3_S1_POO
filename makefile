GCC = g++ 
FILESEXTENSION = cpp
COMPILATIONFLAGS = -g -o
OBJETS = Catalogue.o Collection.o Trajet.o TrajetSimple.o TrajetCompose.o Main.o # mettre ici les objets .o qui seront necessaire pour créer l'exécutable
EXE = exe # mettre ici l'executable qui sera créé

# Créé l'executable à partir des fichiers .o (dans OBJETS)
$(EXE) : $(OBJETS)
	@echo "Compilation des binaires translatables $(OBJETS)"
	$(GCC) $(COMPILATIONFLAGS) $(EXE) $(OBJETS) 

# permet de créé les fichiers .o énoncés dans OBJETS
%.o : %.$(FILESEXTENSION) %.h
	@echo "Création du binaire translatable $<"
	$(GCC) -c $<

# cible de nettoyage
clean : 
	@echo "Nettoyage"
	rm -f $(OBJETS) $(EXE) core

# cible pour valgrind
valgrind: $(EXE)
	@echo "Exécution de Valgrind pour vérifier les fuites de mémoire"
	valgrind --leak-check=full ./$(EXE)