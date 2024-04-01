#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct Aeroport
{
	int id;
	char* nume;
	int nrTerminale;
};

struct Aeroport* adaugaAeroport(struct Aeroport* vector, struct Aeroport aeroport, int* dimensiune)//fara pointer ca sa nu mai fie nevoie sa l dereferentiem, dim prin pointer pt ca vrem sa o modificam
{
	//alocam spatiu
	struct Aeroport* copie = (struct Aeroport*)malloc(sizeof(struct Aeroport) * ((*dimensiune) + 1));//prioritizam dereferentierea

	//adaugam aeroportul nou in copie
	copie[(*dimensiune)] = aeroport;//shallow copy, ca sa nu facem stergerea, daca faceam deep copy trebuia sa stergem

	//parcurgem vectorul initial si adaugam aeroporturile existente in copie
	for (int i = 0; i < (*dimensiune); i++)
	{
		copie[i] = vector[i];
	}

	//dupa ce copiem elem intr un alt vector din vectorul primit, le stergem, 
	//stergem vectorul daca e diferit de NULL
	if (vector);
	free(vector);

	//crestem dimensiunea
	(*dimensiune)++;

	//returnez copie
	return copie;
}


struct Aeroport* citireFisier(const char* numeFisier, int* nrAeroporturi)
{
	struct Aeroport* vectorAeroporturi;
	vectorAeroporturi = NULL;
	FILE* f = fopen(numeFisier, "r");

	if (f != NULL)
	{
		char buffer[100];
		while (fgets(buffer, 99, f) != NULL)//returneaza un pointer la char, adresa la care a citit
		{
			struct Aeroport aeroport;//creeaza obiectul
			
			const char delimitator[] = ",\n";//determinam caracterele delimitatoare
			char* token = strtok(buffer, delimitator);//va cauta virgula sau new line
			aeroport.id = atoi(token); //ascii to integer
			token = strtok(NULL, delimitator);//opreste cautarea cand gaseste caracterul NULL(terminator)
			
			aeroport.nume = malloc(sizeof(char) * (strlen(token) + 1));//aloc memorie pt a citi string ul
			strcpy(aeroport.nume, token);

			token = strtok(NULL, delimitator);
			aeroport.nrTerminale = atoi(token);

			vectorAeroporturi = adaugaAeroport(vectorAeroporturi, aeroport, nrAeroporturi);

		}
		fclose(f);
	}
	return vectorAeroporturi;
}

//void dezalocareVector(struct Aeroport** aeroporturi, int *dim)
//{
//	for (int i = 0; i < (*dim); i++)
//	{
//		free((*aeroporturi)[i].nume);
//		free(aeroporturi[i]);
//	}
//	free(*aeroporturi);
//	(*aeroporturi) = NULL;
//	(*dim) = 0;
//}

void afisareAeroport(struct Aeroport* aeroport)
{
	printf("Aeroportul cu ID %d cu numele%s are %d terminale\n", aeroport->id, aeroport->nume, aeroport->nrTerminale);

}
void afisareVectorAeroporturi(struct Aeroport* aeroporturi, int dim)
{
	printf("Afisare vector: \n");

	for (int i = 0; i < dim; i++)
	{
		afisareAeroport(&aeroporturi[i]);
	}
}


void main()
{
	int dimensiune = 0;

	struct Aeroport* aeroporturi = NULL;//initializam cu NULL pt ca nu avem niciun aeroport
	aeroporturi = citireFisier("aeroporturi.txt", &dimensiune);//ca eu sa l folosesc ca pointer, extrag adresa
	afisareVectorAeroporturi(aeroporturi, dimensiune);
	//dezalocareVector(&aeroporturi, &dimensiune);
}
