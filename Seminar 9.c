//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
////
////typedef struct Nod Nod;
////typedef struct Animal Animal;
////
////struct Animal
////{
////	char* specie;
////	int varsta;
////};
////
////struct Nod
////{
////	Animal data;
////	Nod* next;
////};
////
////Animal initializareAnimal(const char* specie, int varsta)
////{
////	Animal a;
////	a.specie = (char*)malloc(strlen(specie)+1);
////	strcpy(a.specie, specie);
////	a.varsta = varsta;
////	return a;
////}
////
////Nod* inserare(Nod* cap, Animal a)
////{
////	Nod* nod = (Nod*)malloc(sizeof(Nod));
////	nod->data = initializareAnimal(a.specie, a.varsta);
////	if (nod != NULL)
////	{
////		nod->next=cap;
////	}
////	else
////	{
////		nod->next = NULL;
////	}
////	return nod;
////}
////
////void display(Nod* cap)
////{
////	while (cap != NULL)
////	{
////		printf("%s , %d\n\n", cap->data.specie, cap->data.varsta);
////		cap = cap->next;
////	}
////}
////
////void stergere(Nod** cap)
////{
////	while ((*cap) != NULL)
////	{
////		free((*cap)->data.specie);
////		Nod* nod = *cap;
////		(*cap) = (*cap)->next;
////		free(nod);
////	}
////}
////
////void main()
////{
////	Animal a1 = initializareAnimal("a", 2);
////	Animal a2 = initializareAnimal("b", 3);
////	Animal a3 = initializareAnimal("s", 1);
////
////	Nod* cap = NULL;
////	cap = inserare(cap, a1);
////	cap = inserare(cap, a2);
////	cap = inserare(cap, a3);
////
////	display(cap);
////
////	stergere(&cap);
////}
//
//typedef struct ListaDubla ListaDubla;
//typedef struct Nod Nod;
//typedef struct Animal Animal;
//
//struct Animal
//{
//	char* specie;
//	int varsta;
//};
//
//struct Nod
//{
//	Animal data;
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
//Animal init(const char* specie, int varsta)
//{
//	Animal a;
//	a.specie = (char*)malloc(strlen(specie) + 1);
//	strcpy(a.specie, specie);
//	a.varsta = varsta;
//	return a;
//}
//
//
//ListaDubla inser(ListaDubla lista, Animal a)
//{
//	Nod* nod = (Nod*)malloc(sizeof(Nod));
//	nod->data = a;
//	nod->prev = NULL;
//	nod->next = lista.head;
//	if (lista.head != NULL)
//	{
//		lista.head->prev = nod;
//	}
//	else
//	{
//		lista.tail = nod;
//	}
//	lista.head = nod;
//	return lista;
//}
//
//void display(ListaDubla lista)
//{
//	while (lista.head != NULL)
//	{
//		printf("%s , %d\n\n", lista.head->data.specie, lista.head->data.varsta);
//		lista.head = lista.head->next;
//	}
//}
//
//void stergere(ListaDubla* lista)
//{
//	while (lista->head != NULL)
//	{
//		free(lista->head->data.specie);
//		Nod* nod = lista->head;
//		lista->head = lista->head->next;
//		free(nod);
//	}
//	lista->head = NULL;
//	lista->tail = NULL;
//}
//void main()
//{
//	Animal a1 = init("a", 2);
//	Animal a2 = init("b", 3);
//	Animal a3 = init("s", 1);
//
//	ListaDubla lista;
//	lista.head = NULL;
//	lista.tail = NULL;
//
//	lista=inser(lista, a1);
//	lista=inser(lista, a2);
//	lista=inser(lista, a3);
//	
//	display(lista);
//
//	stergere(&lista);
//	display(lista);
//}