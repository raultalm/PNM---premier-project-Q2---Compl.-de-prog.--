/**
 * pnm.h
 * 
 * Ce fichier contient les déclarations de types et les prototypes
 * des fonctions pour la manipulation d'images PNM.
 * 
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiplies
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __PNM__
#define __PNM__

/**
 * Déclaration du type opaque PNM
 *
 */
// typedef struct PNM_t {

//    /* Insérez ici les champs de la structure PNM */
// 	char extension[4];
// 	char nb_magique[3]; // P1, P2, P3
// 	int nb_colognes, nb_lignes;
// 	short nb_elements;
// 	short val_max; // PGM : 255 ; PPM : < 65.536
// 	int *contenu;


// }PNM;
typedef struct PNM_t PNM;


/**
 * load_pnm
 *
 * Charge une image PNM depuis un fichier.
 *
 * @param image l'adresse d'un pointeur sur PNM à laquelle écrire l'adresse
 *              de l'image chargée.
 * @param filename le chemin vers le fichier contenant l'image.
 *
 * @pre: image != NULL, filename != NULL
 * @post: image pointe vers l'image chargée depuis le fichier.
 *
 * @return:
 *     0 Succès
 *    -1 Erreur à l'allocation de mémoire
 *    -2 Nom du fichier malformé
 *    -3 Contenu du fichier malformé
 *
 */
int load_pnm(PNM **image, char* filename);

/**
 * write_pnm
 *
 * Sauvegarde une image PNM dans un fichier.
 *
 * @param image un pointeur sur PNM.
 * @param filename le chemin vers le fichier de destination.
 *
 * @pre: image != NULL, filename != NULL
 * @post: le fichier filename contient l'image PNM image.
 *
 * @return:
 *     0 Succès
 *    -1 Nom du fichier malformé
 *    -2 Erreur lors de la manipulation du fichier
 *
 */
int write_pnm(PNM *image, char* filename);

/*
* get_size_img
* Donne la taille d'une image
* @param nom_fichier est le nom de du fichier
* @param type_fichier est le type de fichier: ppm, pbm ou pgm
*
* @pre: nom_fichier != NULL && (type_fichier != NULL && type_ficier == 'ppm' || type_fichier == 'pbm' || type_fichier == 'pgm')
* @post: la fonction returne la taille du fichier
*
* @return:
*		 0 nom_fichier == NULL
*		-1 Le fichier n'a pas pu etre ouvert
*		 la taile de l'image si l'opération a réussi
*/

int get_size_img(char nom_fichier[80], char type_fichier[4]);

/*
* get_en_tete
* Charge l'en tete du fichier dans lequel on va stoquer l'image, avec l'en tete du fichier image de base
* @param nom_fichier est le nom de du fichier
* @param type_fichier est le type de fichier: ppm, pbm ou pgm
* @param nb_magique est l'adresse de la variable dans laquelle on veut stoquer le nombre magique
* @param lignes est l'adresse de la variable dans laquelle on veut stoquer le nombre de lignes de 'limage'
* @param colognes est l'adresse de la variable dans laquelle on veut stoquer le nombre de colognes de l'image
* @param val_max est l'adresse de la variable dans laquelle on veut stoquer la valeur maximale que peut avoir un pixel
*
* @pre: nom_fichier != NULL && (type_fichier != NULL && type_ficier == 'ppm' || type_fichier == 'pbm' || type_fichier == 'pgm')
		&& nb_magique != NULL && lignes != NULL && colognes != NULL && val_max != NULL
* @post: PNM.nb_magique = nb_magique && PNM.lignes = lignes && PNM.colognes = colognes && PNM.vam_max = val_max
*
* @return:
*		 0 nom_fichier == NULL
*		-1 Le fichier n'a pas pu etre ouvert
*		 la taile de l'image si l'opération a réussi
*/

int get_en_tete(char nom_fichier[80], char type_fichier[4], PNM *pnm);


int test_me();

#endif // __PNM__

