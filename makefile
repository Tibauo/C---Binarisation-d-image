CC=gcc
CFLAGS=-Wall -g
LDFLAGS=
EXEC=projetc

OBJ = gestionfichier.o main.o fonctionannexe.o struct.o gestion.o grise.o binarise.o


all : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(EXEC)
	@echo ""		
	@echo "Le fichier est compile pour l'executer : ./projetc -b/-g fichier"
	@echo ""

%.o : %.c
	$(CC) $^ -c $<

clean : 
	@echo ""	
	@rm -rf *.o
	@echo "Tous les fichiers .o ont etes supprime"
	@echo ""
mrproper : 
	@echo ""	
	@rm -rf *.o $(EXEC) *.pbm *.pgm	
	@echo "Tous les fichiers .o, ./pbm, ./pgm, et l'executable ont etes supprime"
	@echo ""
