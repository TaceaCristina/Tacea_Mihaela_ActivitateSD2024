#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct Biblioteca Biblioteca;
typedef struct Nod Nod;

struct Biblioteca 
{
	char* nume;
	int nrCarti;
	int nrCititori;
};

struct Nod
{
	Biblioteca info;
	Nod* next;
};

Biblioteca initializare(const char* nume, int nrCarti, int nrCititori) 
{
	Biblioteca b;
	b.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy(b.nume, nume);
	b.nrCarti = nrCarti;
	b.nrCititori = nrCititori;

	return b;
}

//o initializam la inceputul listei
Nod* inserareInceput(Nod* cap, Biblioteca b) 
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	//nou->info = b;
	nou->info = initializare(b.nume, b.nrCarti, b.nrCititori);//facem deep copy
	nou->next = cap;//a pus o in capul listei
	return nou;//returnez noul cap
}

//fct de afisare a listei
void afisareLista(Nod* cap) //orice parcurgere pe liste va fi asa:
{
	while (cap != NULL) //parcurgem pe cap pana cand e NULL
	{
		//procesare:       (ii zic lui cap sa se foloseasca de adresa urmatorului nod)
		printf("Biblioteca %s are %d carti si %d cititori.\n", cap->info.nume, cap->info.nrCarti, cap->info.nrCititori);

		//deplasare:
		cap = cap->next;
	}
}

//fct care va det numele bibliotecii cu cele mai multe carti per cititor ca medie
char* getBibliotecaNrCartiPerCititor(Nod* cap) 
{
	float max = 0;
	char* nume_aux = NULL;

	//parcurgem si calc media pt biblioteca curenta si modificam daca e mai mare decat max
	while (cap != NULL)
	{
		if (cap->info.nrCarti / cap->info.nrCititori > max) //procesare
		{
			max = cap->info.nrCarti / cap->info.nrCititori;
			nume_aux = cap->info.nume;
		}
		//deplasare
		cap = cap->next;
	}

	//obligatoriu deep copy pt ca va fi salvat in alt pointer
	char* nume = (char*)malloc(sizeof(char) * (strlen(nume_aux) + 1));
	strcpy(nume, nume_aux);

	return nume;
}

//fct de stergere a listei
void stergeLista(Nod** cap) 
{
	while ((*cap) != NULL) //il dereferentiem pt ca e transmis prin pointer
	{
		//dezalocam info
		free((*cap)->info.nume);
		Nod* copie = *cap;
		*cap = (*cap)->next;

		free(copie);
	}
}

//fct de inserare la sfarsitul listei
void inserareSfarsit(Nod** cap, Biblioteca b) 
{
	Nod* sfarsit = (Nod*)malloc(sizeof(Nod)); //creez nodul

	//initializez atributele(next si info)
	sfarsit->info = initializare(b.nume, b.nrCarti, b.nrCititori);
	sfarsit->next = NULL;

	if ((*cap) != NULL) 
	{
		Nod* aux = (*cap);
		while (aux->next != NULL) 
		{
			aux = aux->next;
		}
		aux->next = sfarsit;
	}
	else 
	{
		(*cap) = sfarsit;
	}
}

void main() 
{
	Nod* cap = NULL; //creeam o lista vida
	/*cap = inserareInceput(cap, initializare("Mihai Eminescu", 150, 20));
	cap = inserareInceput(cap, initializare("Ioan Slavici", 200, 30));
	cap = inserareInceput(cap, initializare("Tudor Arghezi", 100, 15));*/
	Biblioteca b1 = initializare("Mihai Eminescu", 150, 30);
	Biblioteca b2 = initializare("Ioan Slavici", 200, 30);
	Biblioteca b3 = initializare("Tudor Arghezi", 100, 15);
	cap = inserareInceput(cap, b1);
	cap = inserareInceput(cap, b2);
	cap = inserareInceput(cap, b3);

	afisareLista(cap);
	char* numeDeAfisat = getBibliotecaNrCartiPerCititor(cap);
	printf("\nBiblioteca cu media maxima: %s\n\n", numeDeAfisat);
	free(numeDeAfisat);

	Biblioteca b4 = initializare("Radu Tudoran", 660, 65);
	inserareSfarsit(&cap, b4);
	afisareLista(cap);

	stergeLista(&cap);
	afisareLista(cap);

	free(b1.nume);
	free(b2.nume);
	free(b3.nume);
	free(b4.nume);
}
