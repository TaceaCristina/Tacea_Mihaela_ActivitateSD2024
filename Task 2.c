#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char* nume;
	int anPublicare;
	float pretMediu;
	long int nrTotalExemplare;
}Carte;

Carte citire()
{
	Carte c;

	c.nume = (char*)malloc(100 * sizeof(char));
	printf("Numele cartii: ");
	fgets(c.nume, 100, stdin);
	c.nume[strcspn(c.nume, "\n")] = NULL;

	printf("Anul publicarii: ");
	scanf("%d", &c.anPublicare);

	printf("Pretul mediu al cartilor in librarii: ");
	scanf("%f", &c.pretMediu);

	printf("Numar total de exemplare: ");
	scanf("%d", &c.nrTotalExemplare);

	return c;
}

//primeste un pointer catre o structura numita Carte si calculeaza pretul total al unui volum de carti
double PretTotal(Carte* c)
{
	double val;
	val = c->pretMediu * c->nrTotalExemplare;//declaram o variabila val care stocheaza pretul total
	return val;
}

int getAnPublicare(Carte* c)
{
	return c->anPublicare;
}

void setAnPublicare(Carte* c, int AnNou)
{
	if (AnNou > 0)
	{
		c->anPublicare = AnNou;
	}
	else
		printf("Anul nu este valid.");
}

void afisare(Carte* c)
{
	printf("Numele cartii: %s\n", c->nume);
	printf("Anul publicarii: %d\n", c->anPublicare);
	printf("Pretul mediu al cartilor in librarii: %5.2f\n", c->pretMediu);
	printf("Numar total de exemplare: %d\n", c->nrTotalExemplare);
}

Carte initializareCarte(const char* nume, int anPublicare, float pretMediu, long int nrTotalExemplare)
{
	Carte c;
	if (nume != NULL)
	{
		c.nume = malloc(strlen(nume) + 1);
		strcpy(c.nume, nume);
	}
	else
	{
		c.nume = malloc(strlen("N/A") + 1);
		strcpy(c.nume, "N/A");
	}
	c.anPublicare = anPublicare;
	c.pretMediu = pretMediu;
	c.nrTotalExemplare = nrTotalExemplare;

	return c;
}

void dezalocare(Carte* c)
{
	free(c->nume);
	c->nume = NULL;
}


//functie care va creea un nou vector în care va copia dintr-un vector primit 
//ca parametru obiectele care indeplinesc o anumita conditie

void adaugareCarteVector(Carte** vector, int* dimensiune, Carte* c)
{
	*dimensiune = *dimensiune + 1; //1. maresc dimens cu 1 ca sa adaug in vector

	*vector = (Carte*)realloc(*vector, (*dimensiune) * sizeof(Carte)); //2. realizez realocarea memoriei pt vectorul de carti
	//fct realloc creste dim vectorului la dimensiunea noua specificata, prin asignarea rezultatului sau la pointerul la care *vector face referire

	(*vector)[(*dimensiune - 1)] = *c; //3. adaug cartea data *c la sfarsitul vectorului
	//accesez poz noua si copiez structura Carte referita de pointerul ca in acea pozitie a vectorului
}

void afisareCarteVector(Carte* vector, int dimensiune)
{
	printf("\n");
	for (int i = 0;i < dimensiune;i++)
	{
		printf("Carte %d: \n", i + 1);
		afisare(&vector[i]);
	}
}

Carte* copiereVector(Carte* c, int dimensiune, int limitaAnPublicare, int* size)
{
	Carte* ve = (Carte*)malloc(*size * sizeof(Carte));//aloc memorie

	for (int i = 0;i < dimensiune;i++)//parcurg noul vector
	{
		if (c[i].anPublicare < limitaAnPublicare)//verific daca anul cartii de pe pozitia i depaseste limita
		{
			(*size) += 1;
			ve = (Carte*)realloc(ve, (*size) * sizeof(Carte));//aloc memorie pe noua dimensiune a noului vectorului de carti
			ve[(*size) - 1] = c[i];//pun cartea curenta daca anul nu depaseste limita
		}
	}
	return ve;
}

Carte* concatenareVector(Carte* c1, Carte* c2, int dimens1, int dimens2, int* dimensVC)
{
	*dimensVC = dimens1 + dimens2;//creez o dim noua care sa contina dim ambelor str
	Carte* conc = (Carte*)malloc((*dimensVC) * sizeof(Carte));//aloc memorie pe noua dim

	for (int i = 0;i < dimens1;i++)//copiez elem din prima str
	{
		conc[i] = c1[i];
	}
	for (int i = 0;i < dimens2;i++)//copiez elem din a doua str
	{
		conc[dimens1 + i] = c2[i];
	}

	return conc;
}


void main()
{
	Carte c1;
	c1.nume = (char*)malloc(strlen("Ion") + 1);
	strcpy(c1.nume, "Ion");
	c1.anPublicare = 1920;
	c1.pretMediu = 35;
	c1.nrTotalExemplare = 600;
	afisare(&c1);

	Carte c2 = initializareCarte("Ultima noapte", 1800, 59, 1000);
	afisare(&c2);
	Carte c3 = initializareCarte("Floare albastra", 1740, 44, 1200);
	afisare(&c3);
	Carte c4 = initializareCarte("Mara", 1890, 39, 120);
	afisare(&c4);
	Carte c5 = initializareCarte("Eu nu strivesc corola de minuni", 2002, 80, 280);
	afisare(&c5);

	printf("////////////////VECTOR////////////////");

	int dimensV = 0;
	Carte* vector = (Carte*)malloc(dimensV * sizeof(Carte));

	adaugareCarteVector(&vector, &dimensV, &c1);
	adaugareCarteVector(&vector, &dimensV, &c2);
	adaugareCarteVector(&vector, &dimensV, &c3);
	adaugareCarteVector(&vector, dimensV, &c4);
	adaugareCarteVector(&vector, &dimensV, &c5);

	afisareCarteVector(vector, dimensV);
}