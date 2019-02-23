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
int get_en_tete(char nom_fichier[80], char type_fichier[4], PNM *pnm){
	// ---------------------------- Initialisation
	int taille = 0, my_colognes = 0, my_lignes = 0, commentaire = 0;
	short my_val_max;
	char type_f[3], caract, my_nb_magique[3];

	// ---------------------------- Verification des préconditions 
	if(nom_fichier == NULL){
		printf("Il faut mettre le nom du fichier.\n");
		return 0;
	}
	if(type_fichier == NULL ){
		printf("Vous n'avez pas entré le bon type du fichier.\n");
		printf("%s\n", type_fichier);
		return -2;
	}

	// ---------------------------- Travail dans le fichier
	FILE* fichier_open = fopen(nom_fichier, "r");
	if(fichier_open == NULL){
		printf("Le fichier n'a pas pu etre ouvert.\n");
		return -1;
	}

	// type_fichier == "pbm"
	if(!strcmp(type_fichier,"pbm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '#'){
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					i--;
				}
			}
			if(caract == '\n')
				i++;
			if( i == 0 && commentaire == 0){
				fscanf(fichier_open,"%s", &my_nb_magique);
			}
			if( i == 1 && commentaire == 0){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}
			if( i == 2 && commentaire == 0){
				my_val_max = 1;
			}

		}

		for(int i = 0; i < 3; i++){
			pnm->nb_magique[i] = my_nb_magique[i];	
		}
		printf("in\n");
		printf("colognes : \n", my_colognes);
		printf("lignes : \n", my_lignes);
		pnm->nb_colognes = my_colognes;
		pnm->nb_lignes = my_lignes;
		pnm->val_max = my_val_max;
	}

	// type_fichier == "ppm"
	if( !strcmp(type_fichier,"ppm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '#'){
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					i--;
				}
			}
			if(caract == '\n')
				i++;
			if( i == 0 && commentaire == 0){
				fscanf(fichier_open,"%s", &my_nb_magique);
			}
			if( i == 1 && commentaire == 0){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}
			if( i == 2 && commentaire == 0){
				fscanf(fichier_open,"%d", &my_val_max);
			}

		}

		for(int i = 0; i < 3; i++){
			pnm->nb_magique[i] = my_nb_magique[i];	
		}
		pnm->nb_colognes = my_colognes;
		pnm->nb_lignes = my_lignes;
		pnm->val_max = my_val_max;
	}

	// type_fichier == "pgm"
	if( !strcmp(type_fichier,"pgm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '#'){
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					i--;
				}
			}
			if(caract == '\n')
				i++;
			if( i == 0 && commentaire == 0){
				fscanf(fichier_open,"%s", &my_nb_magique);
			}
			if( i == 1 && commentaire == 0){
				fscanf(fichier_open,"%d %d", &my_lignes, &my_colognes);
			}
			if( i == 2 && commentaire == 0){
				fscanf(fichier_open,"%d", &my_val_max);
			}

		}

		for(int i = 0; i < 3; i++){
			pnm->nb_magique[i] = my_nb_magique[i];	
		}
		
		pnm->nb_colognes = my_colognes;
		pnm->nb_lignes = my_lignes;
		pnm->val_max = my_val_max;
	}


	fclose(fichier_open);
	return 1;
}


int get_size_img(char nom_fichier[80], char type_fichier[4]){
	// ---------------------------- Initialisation
	int taille = 0, colognes = 0, lignes = 0, fin_colognes = 0, commentaire = 0;
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

	// type_fichier == "pbm"
	if(!strcmp(type_fichier,"pbm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '#'){
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					i--;
				}
			}
			if(caract == '\n')
				i++;
			if(i>= 2 && commentaire == 0){
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
			if(caract == '#'){
				printf("IN1\n");
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					printf("IN2\n");
					i--;
				}
			}
			if(caract == '\n')
				i++;
			if(i>= 3 && commentaire == 0){
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

	// type_fichier == "pgm"
	if( !strcmp(type_fichier,"pgm")){
		for(int i = 0; fscanf(fichier_open,"%c", &caract) != EOF; ){
			if(caract == '#'){
				commentaire = 1;
				if(caract == '\n'){
					commentaire = 0;
					i--;
				}
			}

			if(caract == '\n')
				i++;
			if(i>= 3 && commentaire == 0){
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

int test_me(){
	PNM my_pnm;
	int taille = 0;
	taille = get_size_img("antilope.ppm", "ppm");
	printf("Taille = %d\n", taille );
	get_en_tete("antilope.ppm", "ppm", &my_pnm);
	printf("nb_magique : %s\n", my_pnm.nb_magique);
	printf("lignes : %s\n", my_pnm.nb_lignes);
	printf("colognes : %s\n", my_pnm.nb_colognes);
	printf("val_max : %s\n", my_pnm.val_max);
	return 0;
}

int load_pnm(PNM **image, char* filename) {

   assert(image != NULL && filename!= NULL);

   return 0;
}

int write_pnm(PNM *image, char* filename) {

   assert(image != NULL && filename!= NULL);

   return 0;
}

