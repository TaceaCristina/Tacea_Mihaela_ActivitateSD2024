//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Biblioteca Biblioteca;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//
//struct Biblioteca
//{
//	char* nume;
//	int nrCarti;
//	int nrCititori;
//};
//
//struct Nod
//{
//	Biblioteca info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla
//{
//	Nod* head;
//	Nod* tail;
//};
//
//Biblioteca initializare(const char* nume, int nrCarti, int nrCititori)
//{
//	Biblioteca b;
//	b.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(b.nume, nume);
//	b.nrCarti = nrCarti;
//	b.nrCititori = nrCititori;
//
//	return b;
//}
//
////fct care insereaza o biblioteca la inceputul listei dublu inlantuite
//void inserareInceput(ListaDubla* listaDubla, Biblioteca b) 
//{
//	Nod* nod = (Nod*)malloc(sizeof(Nod));
//	//shallow copy
//	nod->info = b;
//	//deep copy
//	//nod->info = initializare(b.nume,b.nrCarti,b.nrCititori);
//	nod->next = listaDubla->head;
//	nod->prev = NULL;
//	if (listaDubla->head)
//	{
//		listaDubla->head->prev = nod;
//	}
//	else
//	{
//		listaDubla->tail = nod;
//	}
//	listaDubla->head = nod;
//}
//
//
//void stergereLista(ListaDubla* listaDubla)
//{
//	while (listaDubla->head)
//	{
//		free(listaDubla->head->info.nume);
//		Nod* aux = listaDubla->head;
//		listaDubla->head = listaDubla->head->next;
//		free(aux);
//	}
//	listaDubla->head = NULL;
//	listaDubla->tail = NULL;
//}
//
////stergem biblioteca cu numele pe care l va primi in lista
//void stergeNodNume(ListaDubla* listaDubla, const char* nume)
//{
//	Nod* aux = listaDubla->head;
//	while (aux&&strcmp(nume,aux->info.nume)!=0)
//	{
//		aux = aux->next;
//	}
//	if (aux)
//	{
//		if (aux == listaDubla->head)//stergerea nodului de la inceputul listei
//		{
//			if (aux == listaDubla->tail)//daca aux e si capul si coada listei
//			{//actualizam head si tail la NULL
//				listaDubla->head = NULL;
//				listaDubla->tail = NULL;
//			}
//			else//daca aux este doar capul listei
//			{//actualizam head la urm nod
//				listaDubla->head = listaDubla->head->next;
//			//actualizam prev ul noului cap la NULL
//				listaDubla->head->prev = NULL;
//			}
//		}
//		else//stergerea nodului din interiorul sau de la sfarsitul listei
//		{
//			if (aux == listaDubla->tail)
//			{//stergerea nodului de la starsitul listei
//				aux->prev->next = NULL;
//				listaDubla->tail = aux->prev;
//			}
//			else
//			{//stergerea nodului din interiorul listei
//				aux->next->prev = aux->prev;
//				aux->prev->next = aux->next;
//			}
//		}
//		free(aux->info.nume);
//		free(aux);
//	}
//}
//
//void afisareListaInceput(ListaDubla listaDubla)
//{
//	while (listaDubla.head)
//	{
//		printf("Biblioteca: %s; \n Numar cititori: %d; \n Numar carti: %d. \n\n", listaDubla.head->info.nume, listaDubla.head->info.nrCititori, listaDubla.head->info.nrCarti);
//		listaDubla.head = listaDubla.head->next;
//	}
//}
//
////fct care calc nr de carti din toate bibliotecile, dar parcurgerea sa fie de la final
//int nrCartiTotal(ListaDubla listaDubla)
//{
//	int rezultat = 0;
//	while (listaDubla.tail)
//	{
//		rezultat += listaDubla.tail->info.nrCarti;
//		listaDubla.tail = listaDubla.tail->next;
//	}
//	return rezultat;
//}
//
//void main()
//{
//	Biblioteca b1 = initializare("Mihai Eminescu", 150, 30);
//	Biblioteca b2 = initializare("Ioan Slavici", 200, 30);
//	Biblioteca b3 = initializare("Tudor Arghezi", 100, 15);
//
//	ListaDubla listaDubla;
//	listaDubla.head = NULL;
//	listaDubla.tail = NULL;
//
//	inserareInceput(&listaDubla, b1);
//	inserareInceput(&listaDubla, b2);
//	inserareInceput(&listaDubla, b3);
//
//	afisareListaInceput(listaDubla);
//
//	stergeNodNume(&listaDubla, "Ioan Slavici");
//	afisareListaInceput(listaDubla);
//	stergeNodNume(&listaDubla, "Mihai Eminescu");
//	afisareListaInceput(listaDubla);
//	stergeNodNume(&listaDubla, "Tudor Arghezi");
//	afisareListaInceput(listaDubla);
//
//	int rezultat = nrCartiTotal(listaDubla);
//	printf("Numarul total de carti -> %d", rezultat);
//
//	stergereLista(&listaDubla);
//	afisareListaInceput(listaDubla);
//}