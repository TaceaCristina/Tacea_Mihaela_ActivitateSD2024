//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
////STRUCTURA: tip de date pt articole pe care le cream(in interiorul structurii avem caracteristici)
////in C nu avem metode in interiorul structurilor 
//
//struct Masina
//{
//	char* marca;
//	float capacitateCilindrica;
//	int an;//anul fabricatiei
//
//};
//
////functie de afisare
//void afisareMasina(const struct Masina* m) //fct de afisare=>nu modifica=>punem const
//{
//	if (m->marca != NULL)
//	{
//		printf("Marca: %s\n", m->marca);
//	}
//		printf("Capacitate cilindrica: %5.2f\n", m->capacitateCilindrica);
//		printf("An: %d\n\n", m->an);
//}
//
////functie care va initializa o masina
//struct Masina initializareMasina(const char* marca, int an, float cc)
//{
//	struct Masina m;
//	m.an = an;
//	m.capacitateCilindrica = cc;
//	if (marca != NULL)
//	{
//		m.marca = malloc(strlen(marca) + 1);
//		strcpy(m.marca, marca);//copiem pe marca in marca
//	}
//	else
//	{
//		m.marca = (char*)malloc(strlen("N/A") + 1);
//		strcpy(m.marca, "N/A");
//	}
//	return m;
//}
//
////functie care dezaloca memoria
//void dezalocareMasina(struct Masina* masina)
//{
//	free(masina->marca);
//	masina->marca = NULL;//am alocat cu malloc, nu trb delete
//}
//
//int main()
//{
//	struct Masina masina1;
//	masina1.marca = (char*)malloc(sizeof(char) *   //malloc=manual alocation    //avem nev de cast explicit (transf malloc in char*)
//		(strlen("Dacia") + 1));                    //primeste o dimensiune exprimata in biti, tipul returnat e de tip pointer la void(pointer generic)
//	strcpy(masina1.marca, "Dacia");
//	masina1.capacitateCilindrica = 1.9;
//	masina1.an = 2023;
//
//	afisareMasina(&masina1);
//
//	dezalocareMasina(&masina1);
//
//
//	struct Masina masina2 = initializareMasina("Ford", 2022, 2.49);
//	afisareMasina(&masina2);
//
//	dezalocareMasina(&masina2);
//
//	afisareMasina(&masina2);
//	//DANGLILG POINTER: inca are adresa zonei de memorie unde a fost sters ce e la adresa
//	return 0;
//}