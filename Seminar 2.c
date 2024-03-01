#include<stdio.h>
#include<malloc.h>

//Vector: structura de date liniara, omogena, care ocupa o zona de memorie constinua
//int v[10]; //alocat static pe stack, ocupa 4*10=40 de octeti 
//int* v1;   //declaram un pointer catre adresa primului element

struct Calculator
{
	char* serie;
	float pret;
	int nrPorturi;
};

struct Calculator Initializare(const char* serie, float pret, int nrPorturi)//asem constr param
{
	struct Calculator c;
	c.serie = (char*)malloc(sizeof(char) * (strlen(serie) + 1));//prioritizam adunarea inaintea inmultirii
	strcpy(c.serie, serie);
	c.nrPorturi = nrPorturi;
	c.pret = pret;
	return c;
}

void afisareCalculator(struct Calculator c)
{
	printf("Calculatorul cu seria %s, costa %5.2f si are %d porturi\n", c.serie, c.pret, c.nrPorturi);
}

void afisareVectorCalculatoare(struct Calculator* vector, int nrcalculatoare)
{
	if (nrcalculatoare > 0 && vector != NULL)
	{
		for (int i = 0; i < nrcalculatoare; i++)
		{
			afisareCalculator(vector[i]);
		}
	}
}

//fct care sa ne copieze primele n elemente
struct Calculator* copiazaNCalculatoare(struct Calculator* calculatoare, int nrcalculatoare, int nrcalculatoareCopiate)
{
	//initializ un vector de calculatoare
	struct Calculator* copiate = (struct Calculator*)malloc(sizeof(struct Calculator) * nrcalculatoareCopiate);
	//SHALLOW COPY=atribuire de adrese                     deep copy
	for (int i = 0; i < nrcalculatoareCopiate; i++)
	{
		copiate[i] = calculatoare[i];
		copiate[i].serie = (char*)malloc(sizeof(char) * (1 + strlen(calculatoare[i].serie)));
		strcpy(copiate[i].serie, calculatoare[i].serie);
	}
	return copiate;
}

//fct care ne returneaza calculatoarele cu un nr minim de porturi
struct Calculator* copiazaCalculatoareCuMultePorturi(struct Calculator* calculatoare, int nrcalculatoare, int pragNrPorturi, int* nrCalculatoarePorturi) //punem pointer pt ca nu stiu cate calculatoare indeplinesc acea conditie
{
	*nrCalculatoarePorturi = 0;
	for (int i = 0; i < nrcalculatoare; i++)
	{
		if (calculatoare[i].nrPorturi > pragNrPorturi)
		{
			(*nrCalculatoarePorturi)++;
		}
	}
	struct Calculator* v = (struct Calculator*)malloc(sizeof(struct Calculator) * (*nrCalculatoarePorturi));
	int k = 0;//trb sa iau un index care sa mearga in spatele lui
	for (int i = 0; i < nrcalculatoare; i++)
	{
		if (calculatoare[i].nrPorturi > pragNrPorturi)
		{
			v[k++] = Initializare(calculatoare[i].serie, calculatoare[i].pret, calculatoare[i].nrPorturi);//DEEP COPY
			//k creste doar daca intra in if, i creste la fiecare iteratie
		}
	}
	return v;
}

void dezalocare(struct Calculator** vector, int* dim)//la final trb sa facem si vectorul sa fie null si dimensiunea
{
	for (int i = 0; i < (*dim); i++)
	{
		free((*vector)[i].serie);
	}
	free(*vector);//trb sa l dereferentiem
	*vector = NULL;
	*dim = 0;
}

void main()
{
	int nrcalculatoare = 5;
	struct Calculator* calculatoare = (struct Calculator*)malloc(sizeof(struct Calculator) * nrcalculatoare);

	for (int i = 0; i < nrcalculatoare; i++)
	{
		calculatoare[i] = Initializare("1234567890", i * 20 + 10, i + 1);
	}

	afisareVectorCalculatoare(calculatoare, nrcalculatoare);

	int nrcalculatoareCopiate = 3;//lungimea

	struct Calculator* calculatoareCopiate = copiazaNCalculatoare(calculatoare, nrcalculatoare, nrcalculatoareCopiate);

	printf("\n\n");
	afisareVectorCalculatoare(calculatoareCopiate, nrcalculatoareCopiate);

	int nrCalculatoarePorturi = 0;
	struct Calculator* calculatoarePorturi = copiazaCalculatoareCuMultePorturi(calculatoare, nrcalculatoare, 3, &nrCalculatoarePorturi);

	printf("\n\n");
	afisareVectorCalculatoare(calculatoarePorturi, nrCalculatoarePorturi);

	dezalocare(&calculatoare,&nrcalculatoare);
}