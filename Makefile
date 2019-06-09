OBJS_DIR	= build/
OBJS	= main.o Anfibio.o AnfibioExotico.o AnfibioNativo.o Animal.o AnimalExotico.o AnimalNativo.o AnimalSilvestre.o Ave.o AveExotico.o AveNativo.o CSVparser.o Date.o Funcionario.o Mamifero.o MamiferoExotico.o MamiferoNativo.o ModelDAO.o Reptil.o ReptilExotico.o ReptilNativo.o Tratador.o Veterinario.o utils.o Interacao.o table_printer.o
ANIMALS_OBJS = main.o Anfibio.o AnfibioExotico.o AnfibioNativo.o Animal.o AnimalExotico.o AnimalNativo.o AnimalSilvestre.o Ave.o AveExotico.o AveNativo.o CSVparser.o Mamifero.o MamiferoExotico.o MamiferoNativo.o ModelDAO.o Reptil.o ReptilExotico.o ReptilNativo.o 
SOURCE	= src/main.cpp src/classes/Anfibio.cpp src/classes/AnfibioExotico.cpp src/classes/AnfibioNativo.cpp src/classes/Animal.cpp src/classes/AnimalExotico.cpp src/classes/AnimalNativo.cpp src/classes/AnimalSilvestre.cpp src/classes/Ave.cpp src/classes/AveExotico.cpp src/classes/AveNativo.cpp src/classes/CSVparser.cpp src/classes/Date.cpp src/classes/Funcionario.cpp src/classes/Mamifero.cpp src/classes/MamiferoExotico.cpp src/classes/MamiferoNativo.cpp src/classes/ModelDAO.cpp src/classes/Reptil.cpp src/classes/ReptilExotico.cpp src/classes/ReptilNativo.cpp src/classes/Tratador.cpp src/classes/Veterinario.cpp src/utils/utils.cpp src/utils/table_printer.cpp src/utils/Interacao.cpp
HEADER	= include/Anfibio.h include/AnfibioExotico.h include/AnfibioNativo.h include/Animal.h include/AnimalExotico.h include/AnimalNativo.h include/AnimalSilvestre.h include/Ave.h include/AveExotico.h include/AveNativo.h include/CRUD.h include/CSVparser.hpp include/Date.h include/Funcionario.h include/Interacao.h include/Mamifero.h include/MamiferoExotico.h include/MamiferoNativo.h include/ModelDAO.h include/Reptil.h include/ReptilExotico.h include/ReptilNativo.h include/Tratador.h include/utils.h include/Veterinario.h include/bprinter/table_printer.h include/bprinter/impl/table_printer.tpp.h
OUT	= exec
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = -I include/ -O0

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	make clean

animals: $(ANIMALS_OBJS)
	$(CC) -g $(ANIMALS_OBJS) -o $(OUT) $(LFLAGS)
	make clean

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++11

utils.o: src/utils/utils.cpp
	$(CC) $(FLAGS) src/utils/utils.cpp -std=c++11

table_printer.o: src/utils/table_printer.cpp
	$(CC) $(FLAGS) src/utils/table_printer.cpp -std=c++11	

Interacao.o: src/utils/Interacao.cpp
	$(CC) $(FLAGS) src/utils/Interacao.cpp -std=c++11

Anfibio.o: src/classes/Anfibio.cpp
	$(CC) $(FLAGS) src/classes/Anfibio.cpp -std=c++11

AnfibioExotico.o: src/classes/AnfibioExotico.cpp
	$(CC) $(FLAGS) src/classes/AnfibioExotico.cpp -std=c++11

AnfibioNativo.o: src/classes/AnfibioNativo.cpp
	$(CC) $(FLAGS) src/classes/AnfibioNativo.cpp -std=c++11

Animal.o: src/classes/Animal.cpp
	$(CC) $(FLAGS) src/classes/Animal.cpp -std=c++11

AnimalExotico.o: src/classes/AnimalExotico.cpp
	$(CC) $(FLAGS) src/classes/AnimalExotico.cpp -std=c++11

AnimalNativo.o: src/classes/AnimalNativo.cpp
	$(CC) $(FLAGS) src/classes/AnimalNativo.cpp -std=c++11

AnimalSilvestre.o: src/classes/AnimalSilvestre.cpp
	$(CC) $(FLAGS) src/classes/AnimalSilvestre.cpp -std=c++11

Ave.o: src/classes/Ave.cpp
	$(CC) $(FLAGS) src/classes/Ave.cpp -std=c++11

AveExotico.o: src/classes/AveExotico.cpp
	$(CC) $(FLAGS) src/classes/AveExotico.cpp -std=c++11

AveNativo.o: src/classes/AveNativo.cpp
	$(CC) $(FLAGS) src/classes/AveNativo.cpp -std=c++11

CSVparser.o: src/classes/CSVparser.cpp
	$(CC) $(FLAGS) src/classes/CSVparser.cpp -std=c++11

Date.o: src/classes/Date.cpp
	$(CC) $(FLAGS) src/classes/Date.cpp -std=c++11

Funcionario.o: src/classes/Funcionario.cpp
	$(CC) $(FLAGS) src/classes/Funcionario.cpp -std=c++11

Mamifero.o: src/classes/Mamifero.cpp
	$(CC) $(FLAGS) src/classes/Mamifero.cpp -std=c++11

MamiferoExotico.o: src/classes/MamiferoExotico.cpp
	$(CC) $(FLAGS) src/classes/MamiferoExotico.cpp -std=c++11

MamiferoNativo.o: src/classes/MamiferoNativo.cpp
	$(CC) $(FLAGS) src/classes/MamiferoNativo.cpp -std=c++11

ModelDAO.o: src/classes/ModelDAO.cpp
	$(CC) $(FLAGS) src/classes/ModelDAO.cpp -std=c++11

Reptil.o: src/classes/Reptil.cpp
	$(CC) $(FLAGS) src/classes/Reptil.cpp -std=c++11

ReptilExotico.o: src/classes/ReptilExotico.cpp
	$(CC) $(FLAGS) src/classes/ReptilExotico.cpp -std=c++11

ReptilNativo.o: src/classes/ReptilNativo.cpp
	$(CC) $(FLAGS) src/classes/ReptilNativo.cpp -std=c++11

Tratador.o: src/classes/Tratador.cpp
	$(CC) $(FLAGS) src/classes/Tratador.cpp -std=c++11

Veterinario.o: src/classes/Veterinario.cpp
	$(CC) $(FLAGS) src/classes/Veterinario.cpp -std=c++11


clean:
	rm -f $(OBJS)
run:
	./exec.o
debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)