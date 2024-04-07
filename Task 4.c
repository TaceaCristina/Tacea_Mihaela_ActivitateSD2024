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
////Task 4
//cofetarie* adaugaCofetarieInVector(cofetarie* vector, cofetarie c, int* dim);
//cofetarie* citireTxt(const char* numeFis, int* dimV);
//cofetarie** adaugaElementeInMatrice(cofetarie* vector, int dim);
//void printCofetarie(cofetarie c);
//void displayMatrice(cofetarie** matrice, int dim);
//void displayMatriceCuConditie(cofetarie** matrice, int dim);
//void dezalocareMatrice(cofetarie*** matrice, int dim);
//void dezalocareVector(cofetarie** vector, int* dim);
//
//void main()
//{
//	cofetarie* vectorPrajituri = NULL;
//	int dimV = 0;
//	vectorPrajituri = citireTxt("MatricePrajituri.txt", &dimV);
//	printf("Dim vector: %d\n", dimV);
//
//	cofetarie** matricePrajituri = (cofetarie**)malloc(dimV * sizeof(cofetarie*));
//
//	matricePrajituri = adaugaElementeInMatrice(vectorPrajituri, dimV);
//	displayMatrice(matricePrajituri, dimV);
//
//	printf("\n\n");
//	displayMatriceCuConditie(matricePrajituri, dimV);
//
//	dezalocareMatrice(&matricePrajituri, dimV);
//	dezalocareVector(&vectorPrajituri, &dimV);
//}
//
//////////////////////MATRICE//////////////////////
//
////Functie care sa citeasca obiectele din fisier si sa le salveze intr-un vector.
//
//cofetarie* adaugaCofetarieInVector(cofetarie* vector, cofetarie c, int* dim)
//{
//	//facem o copie pt a ne asigura ca vectorul original ramane "intact"
//	cofetarie* copie = (cofetarie*)malloc(((*dim) + 1) * sizeof(cofetarie)); //aloc spatiu vectorului de obiecte
//
//	for (int i = 0;i < *dim;i++)//parcurg vectorul de obiecte
//	{
//		copie[i] = vector[i]; //actualizez ce e in copie cu ce e in vector
//	}
//	copie[*dim] = c;//pun obiectul in copie
//
//	if (vector != NULL)
//		free(vector);
//
//	return copie;
//}
//
//cofetarie* citireTxt(const char* numeFis, int* dimV)
//{
//	cofetarie* vector = NULL;
//	FILE* f;
//	f = fopen(numeFis, "r");//deschid fisierul in modul citire
//	if (!f)
//		printf("Eroare la deschiderea fisierului!");
//	else
//	{
//		(*dimV) = 0;
//		char buffer[100];//imi creez un buffer ca sa am unde sa stochez elem din fisier
//		const char delimitatori[] = ",\n";
//		while (fgets(buffer, 99, f) != NULL)//cat timp am ce citi din fisier
//		{
//			cofetarie c; //creez obiectul
//			char* token = strtok(buffer, delimitatori);
//			c.sortiment = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//			strcpy(c.sortiment, token);//stocam delimitatoorii intr un buffer separat pt a nu fi suprascrisi
//
//			token = strtok(NULL, delimitatori);
//			c.pret = atof(token);
//
//			token = strtok(NULL, delimitatori);
//			c.rating = atof(token);
//
//			vector = adaugaCofetarieInVector(vector, c, dimV);
//			(*dimV)++;
//		}
//	}
//
//	return vector;
//}
//
//// Creati o functie care sa copieze (deep copy) elementele din vector
//// intr-o matrice alocată dinamic.
//
//cofetarie** adaugaElementeInMatrice(cofetarie* vector, int dim)
//{
//	cofetarie** copie = (cofetarie**)malloc(dim * sizeof(cofetarie*)); // Alocă memorie pentru fiecare linie a matricei
//
//	for (int i = 0; i < dim; i++)
//	{
//		copie[i] = (cofetarie*)malloc(4 * sizeof(cofetarie)); // Alocă memorie pentru fiecare element din linie
//
//		for (int j = 0; j < 4; j++) {
//			copie[i][j].sortiment = (char*)malloc(strlen(vector[i].sortiment) + 1); // Alocă memorie pentru sortiment
//			strcpy(copie[i][j].sortiment, vector[i].sortiment); // Copiază sortimentul
//
//			copie[i][j].pret = vector[i].pret; // Copiază prețul
//			copie[i][j].rating = vector[i].rating; // Copiază ratingul
//		}
//	}
//
//	return copie;
//}
////Asezarea in matrice pe linii a obiectelor o faceti dupa un criteriu aplicat unui atribut.
////Astfel veti obține mai multe clustere reprezentate de liniile matricei.
//void printCofetarie(cofetarie c)
//{
//	printf("%s\t%f\t%f\n", c.sortiment, c.pret, c.rating);
//}
//void printVector(cofetarie* vector, int dim)
//{
//	for (int i = 0;i < dim;i++)
//	{
//		printCofetarie(vector[i]);
//	}
//}
//void displayMatrice(cofetarie** matrice, int dim)
//{
//	for (int i = 0;i < dim;i++)
//	{
//		printCofetarie(*matrice[i]);
//	}
//}
////afisare cu conditie:
//void displayMatriceCuConditie(cofetarie** matrice, int dim)
//{
//	for (int i = 0;i < dim;i++)
//	{
//		if (matrice[i]->rating > 0)
//			printCofetarie(*(matrice)[i]);
//		else
//			printf("Rating negativ!");
//	}
//}
//
//void dezalocareMatrice(cofetarie*** matrice, int dim)
//{
//	for (int i = 0;i < dim;i++)
//	{
//		for (int j = 0;j < 4;j++)
//		{
//			free((*matrice)[i][j].sortiment);//pt fiec elem
//		}
//		free((*matrice)[i]);//pt linia curenta
//	}
//	free(*matrice);//pt toata matricea
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
//}