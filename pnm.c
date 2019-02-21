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

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {

   /* Insérez ici les champs de la structure PNM */
	char extension[4];
	char nb_magique[3]; // P1, P2, P3
	int nb_colognes;
	int nb_lignes;
	short val_max; // PGM : 255 ; PPM : < 65.536


};

int get_size_img(char nom_fichier[80]){
	int taille = 0, colognes = 0, lignes = 0;
	char type_f[3], caract;

	if(nom_fichier == NULL){
		printf("Il faut mettre le nom du fichier.\n");
		return 0;
	}
	printf("IN 1\n");
	FILE* fichier_open = fopen(nom_fichier, "r");
	if(fichier_open == NULL){
		printf("Le fichier n'a pas pu etre ouvert.\n");
		return -1;
	}
	for(; fscanf(fichier_open,"%c", &caract) != EOF;){
		printf("%c\n", caract);
		taille++;
	}
	// taille += colognes*lignes;
	
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

