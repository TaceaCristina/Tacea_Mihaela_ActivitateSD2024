//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct
//{
//	char* nume;
//	int anPublicare;
//	float pretMediu;
//	long int nrTotalExemplare;
//}Carte;
//
//Carte citire()
//{
//	Carte c;
//
//	c.nume = (char*)malloc(100 * sizeof(char));
//	printf("Numele cartii: ");
//	fgets(c.nume, 100, stdin);
//	c.nume[strcspn(c.nume, "\n")] = NULL;
//	
//	printf("Anul publicarii: ");
//	scanf("%d", &c.anPublicare);
//
//	printf("Pretul mediu al cartilor in librarii: ");
//	scanf("%f", &c.pretMediu);
//
//	printf("Numar total de exemplare: ");
//	scanf("%d", &c.nrTotalExemplare);
//
//	return c;
//}
//
////primeste un pointer catre o structura numita Carte si calculeaza pretul total al unui volum de carti
//double PretTotal(Carte* c)
//{
//	double val;
//	val = c->pretMediu * c->nrTotalExemplare;//declaram o variabila val care stocheaza pretul total
//	return val;
//}
//
//int getAnPublicare(Carte* c)
//{
//	return c->anPublicare;
//}
//
//void setAnPublicare(Carte* c, int AnNou)
//{
//	if (AnNou > 0)
//	{
//		c->anPublicare = AnNou;
//	}
//	else
//		printf("Anul nu este valid.");
//}
//
//void afisareCarteCitita(Carte* c)
//{
//	printf("Numele cartii: %s\n",c->nume);
//	printf("Anul publicarii: %d\n",c->anPublicare);
//	printf("Pretul mediu al cartilor in librarii: %5.2f\n",c->pretMediu);
//	printf("Numar total de exemplare: %d\n",c->nrTotalExemplare);
//}
//
//void main()
//{
//	Carte c1;
//	c1 = citire();
//
//	afisareCarteCitita(&c1);
//
//	printf("\nPretul tuturor cartilor \%s\: %5.2f\n", c1.nume, PretTotal(&c1));
//	
//	int val;
//	printf("Noul An: ");
//	scanf("%d", &val);
//	setAnPublicare(&c1, val);
//
//	afisareCarteCitita(&c1);
//
//	printf("\n\nGet an publicare: %d", getAnPublicare(&c1));
//	free(c1.nume);
//}