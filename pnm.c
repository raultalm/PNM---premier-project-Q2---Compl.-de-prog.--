/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {

   /* Insérez ici les champs de la structure PNM */
	char extension[4];
	char nb_magique[3]; // P1, P2, P3
	int nb_colognes, nb_lignes;
	short nb_elements;
	short val_max; // PGM : 255 ; PPM : < 65.536
	int *contenu;


};
void get_lignes_colognes(char nom_fichier[80], char type_fichier[4], int **lignes, int **colognes){
	// ---------------------------- Initialisation
	int taille = 0, my_colognes = 0, my_lignes = 0,
	char type_f[3], caract;

	// ---------------------------- Verification des préconditions 
	if(nom_fichier == NULL){
		printf("Il faut mettre le nom du fichier.\n");
		return 0;
	}
	if(type_fichier == NULL ){
		printf("Vous n'avez pas retre le bon type du fichier.\n");
		printf("%s\n", type_fichier);
		return -2;
	}

	// ---------------------------- Travail dans le fichier
	FILE* fichier_open = fopen(nom_fichier, "r");
	if(fichier_open == NULL){
		printf("Le fichier n'a pas pu etre ouvert.\n");
		return -1;
	}

	// type_fichier == "pgm"
	if(!strcmp(type_fichier,"pbm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){

			if( i == 1){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}

		}

		printf("\nmy_Colognes : %d\n", my_colognes);
		printf("my_Lignes : %d\n", my_lignes);
		colognes = my_colognes;
		lignes = my_lignes
	}

	// type_fichier == "ppm"
	if( !strcmp(type_fichier,"ppm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){

			if( i == 1){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}

		}

		printf("\nmy_Colognes : %d\n", my_colognes);
		printf("my_Lignes : %d\n", my_lignes);
		colognes = my_colognes;
		lignes = my_lignes
	}

	// type_fichier == "pbm"
	if( !strcmp(type_fichier,"pgm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){

			if( i == 1){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}

		}

		printf("\nmy_Colognes : %d\n", my_colognes);
		printf("my_Lignes : %d\n", my_lignes);
		colognes = my_colognes;
		lignes = my_lignes
	}


	fclose(fichier_open);

}


int get_size_img(char nom_fichier[80], char type_fichier[4]){
	// ---------------------------- Initialisation
	int taille = 0, colognes = 0, lignes = 0, fin_colognes = 0;
	char type_f[3], caract;

	// ---------------------------- Verification des préconditions 
	if(nom_fichier == NULL){
		printf("Il faut mettre le nom du fichier.\n");
		return 0;
	}
	if(type_fichier == NULL ){
		printf("Vous n'avez pas retre le bon type du fichier.\n");
		printf("%s\n", type_fichier);
		return -2;
	}

	// ---------------------------- Travail dans le fichier
	FILE* fichier_open = fopen(nom_fichier, "r");
	if(fichier_open == NULL){
		printf("Le fichier n'a pas pu etre ouvert.\n");
		return -1;
	}

	// type_fichier == "pgm"
	if(!strcmp(type_fichier,"pbm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '\n')
				i++;
			if(i>= 2){
				// printf("%c", caract);
				taille++;
			}

			if( i == 1){
				fscanf(fichier_open,"%d %d", &lignes, &colognes);
			}

		}
		printf("\nColognes : %d\n", colognes);
		printf("Lignes : %d\n", lignes);
	}

	// type_fichier == "ppm"
	if( !strcmp(type_fichier,"ppm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '\n')
				i++;
			if(i>= 3){
				// printf("%c", caract);
				taille++;
			}

			if( i == 1){
				fscanf(fichier_open,"%d %d", &lignes, &colognes);
			}

		}
		printf("\nColognes : %d\n", colognes);
		printf("Lignes : %d\n", lignes);

	}

	// type_fichier == "pbm"
	if( !strcmp(type_fichier,"pgm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '\n')
				i++;
			if(i>= 3){
				// printf("%c", caract);
				taille++;
			}

			if( i == 1){
				fscanf(fichier_open,"%d %d", &lignes, &colognes);
			}

		}
		printf("\nColognes : %d\n", colognes);
		printf("Lignes : %d\n", lignes);
	}


	fclose(fichier_open);

	return taille;
}

int load_pnm(PNM **image, char* filename) {

   assert(image != NULL && filename!= NULL);

   return 0;
}

int write_pnm(PNM *image, char* filename) {

   assert(image != NULL && filename!= NULL);

   return 0;
}

