//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
////"MatricePrajituri.txt"
//
//typedef struct
//{
//	char* sortiment;
//	float pret;
//	float rating;
//}cofetarie;
//
//struct Nod
//{
//	cofetarie c;
//	struct Nod* next;
//};
//
//
//////Task 5
//void citireTxt(const char* numeFis, struct Nod** nod, int* dim);
//void afisarePrajitura(cofetarie c);
//void afisareLista(struct Nod* nod);
//cofetarie* adaugaCofetarieInVector(cofetarie* vector, cofetarie c, int* dim);
//void citireTxtSiSortare(const char* numeFis, struct Nod** nod, int* dim);
//void stergereNodDinLista(struct Nod** nod, int poz);
//cofetarie* salvareInVectorDacaConditie(cofetarie* vector, struct Nod* cap, float rating, int* dim);
//void stergereLista(struct Nod** nod);
//void dezalocareVector(cofetarie** vector, int* dim);
//
//
//void main()
//{
//	struct Nod* cap = NULL;
//	int dim = 0;
//	citireTxt("MatricePrajituri.txt", &cap, &dim);
//	afisareLista(cap);
//	printf("Dim lista: %d\n\n", dim);
//
//	printf("Stergere nod din Lista:\n\n");
//	stergereNodDinLista(&cap, 1);
//	afisareLista(cap);
//
//	printf("Lista sortata:\n\n");
//	struct Nod* cap2 = NULL;
//	int dim2 = 0;
//	citireTxtSiSortare("MatricePrajituri.txt", &cap2, &dim2);
//	afisareLista(cap2);
//
//	printf("Vector conditionat:\n\n");
//	cofetarie* vector = NULL;
//	int dimV = 0;
//	vector = salvareInVectorDacaConditie(vector, cap, 9, &dimV);
//	for (int i = 0;i < dimV;i++)
//	{
//		afisarePrajitura(vector[i]);
//	}
//
//	dezalocareVector(&vector, &dimV);
//}
//
////functie de citire din fisier si populare a listei
//void citireTxt(const char* numeFis, struct Nod** nod, int* dim)
//{
//	FILE* f;
//	f = fopen(numeFis, "r");
//	if (f)
//	{
//		const char buffer[100];
//		while (fgets(buffer, 99, f) != NULL)
//		{
//			cofetarie c;
//			const char delimitatori[] = ",\n";
//			const char* token = strtok(buffer, delimitatori);
//			c.sortiment = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//			strcpy(c.sortiment, token);
//
//			token = strtok(NULL, delimitatori);
//			c.pret = atof(token);
//
//			token = strtok(NULL, delimitatori);
//			c.rating = atof(token);
//
//
//			struct Nod* nodNou = (struct Nod*)malloc(sizeof(struct Nod) + 1);
//			nodNou->c = c;
//			nodNou->next = *nod;
//
//			*nod = nodNou;
//			(*dim)++;
//		}
//		fclose(f);
//	}
//	else
//		printf("Eroare la deschiderea fisierului");
//}
//
//void afisarePrajitura(cofetarie c)
//{
//	printf("Sortiment: %s\n", c.sortiment);
//	printf("Pret: %.2f\n", c.pret);
//	printf("Rating: %.1f\n", c.rating);
//	printf("\n");
//}
//void afisareLista(struct Nod* nod)
//{
//	while (nod != NULL)
//	{
//		afisarePrajitura(nod->c);
//		nod = nod->next;
//	}
//}
//
////2. Implementati o functie care sa insereze elementele in cadrul listei simplu inlantuite
//// astfel incat acestea a fie sortate crescator dupa un camp la alegerea voastra.
//void citireTxtSiSortare(const char* numeFis, struct Nod** nod, int* dim)
//{
//	FILE* f;
//	f = fopen(numeFis, "r");
//	cofetarie* cVector = NULL;
//
//	if (f)
//	{
//		char buffer[100];
//		while (fgets(buffer, 99, f))
//		{
//			cofetarie c;
//			const char delimitatori[] = ",\n";
//			const char* token = strtok(buffer, delimitatori);
//
//			c.sortiment = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//			c.sortiment = strcpy(c.sortiment, token);
//
//			token = strtok(NULL, delimitatori);
//			c.pret = atof(token);
//
//			token = strtok(NULL, delimitatori);
//			c.rating = atof(token);
//
//			cVector = adaugaCofetarieInVector(cVector, c, dim);
//		}
//		fclose(f);
//		for (int i = 0;i < (*dim) - 1;i++)
//		{
//			for (int j = i + 1;j < (*dim);j++)
//			{
//				if (cVector[i].rating < cVector[j].rating)
//				{
//					cofetarie copie = cVector[i];
//					cVector[i] = cVector[j];
//					cVector[j] = copie;
//				}
//			}
//		}
//		for (int i = 0;i < (*dim);i++)
//		{
//			struct Nod* nodNou = (struct Nod*)malloc(sizeof(struct Nod*));
//			nodNou->c = cVector[i];
//			nodNou->next = *nod;
//
//			*nod = nodNou;
//		}
//		free(cVector);
//	}
//	else
//	{
//		printf("\nEroare la deschiderea fisierului!\n");
//	}
//}
//
//cofetarie* adaugaCofetarieInVector(cofetarie* vector, cofetarie c, int* dim)
//{
//	cofetarie* copie = (cofetarie*)malloc(sizeof(cofetarie) * ((*dim) + 1));
//
//	for (int i = 0;i < (*dim);i++)
//	{
//		copie[i] = vector[i];
//	}
//	copie[*dim] = c;
//
//	if (vector != NULL)
//		free(vector);
//
//	(*dim)++;
//	return copie;
//}
//
////1. Implementati o functie care sterge un nod de pe o pozitie data ca parametru. 
//// Daca lista are mai putine noduri decat index-ul dat, nu se realizeaza stergerea.
//void stergereNodDinLista(struct Nod** nod, int poz)//poz=pozitia stearsa
//{
//	int i = 0;//poz curenta
//
//	struct Nod* iPrim = (*nod);
//
//	struct Nod* iUltim = (*nod);
//
//	if ((*nod) == NULL)
//	{
//		printf("Lista este deja goala!\n");
//	}
//	else
//	{
//		while (iPrim->next != NULL && i != poz)
//		{
//			iUltim = iPrim;//pentru a fi nodul anterior celui curent
//			iPrim = iPrim->next;
//			i++;
//		}
//		if (i == poz)
//		{
//			iUltim->next = iPrim->next;
//			free(iPrim->c.sortiment);
//			free(iPrim);
//		}
//		else
//		{
//			printf("Nu am gasit nodul care trebuia sters!\n");
//		}
//	}
//}
//
////3.Implementati o functie care salveaza intr - un vector toate obiectele care
//// indeplinesc o conditie stabilita de voi. Realizati deep copy, astfel incat 
//// elementele din vector sa fie diferentiate de cele din lista.
//// Aveti grija la alocarea de spatiu, deoarece trebuie sa stabiliti pentru 
//// cate elemente veti aloca spatiu.
//cofetarie* salvareInVectorDacaConditie(cofetarie* vector, struct Nod* cap, float rating, int* dim)
//{
//	struct Nod* cap2 = cap;
//
//	while (cap2 != NULL)
//	{
//		if (cap2->c.rating > rating)
//		{
//			(*dim)++;
//		}
//		cap2 = cap2->next;
//	}
//
//	cofetarie* vectorCond = (cofetarie*)malloc(sizeof(cofetarie) * (*dim));
//
//	int poz = 0;
//	while (cap != NULL)
//	{
//		if (cap->c.rating > rating)
//		{
//			vectorCond[poz] = cap->c;
//			vectorCond[poz].sortiment = (char*)malloc(sizeof(char) * (strlen(cap->c.sortiment) + 1));
//			strcpy(vectorCond[poz].sortiment, cap->c.sortiment);
//			poz++;
//		}
//		cap = cap->next;
//	}
//	return vectorCond;
//}
//
//void dezalocareVector(cofetarie** vector, int* dim)
//{
//	for (int i = 0;i < (*dim);i++)
//	{
//		free((*vector)[i].sortiment);
//		(*vector)[i].sortiment = NULL;
//	}
//	free(*vector);
//	(*vector) = NULL;
//	(*dim) = 0;
//	printf("Vector dezalocat!");
//}
//void stergereLista(struct Nod** nod)
//{
//	while ((*nod) != NULL)
//	{
//		free((*nod)->c.sortiment);
//		struct Nod* copie = *nod;
//		*nod = (*nod)->next;
//
//		free(copie);
//	}
//}