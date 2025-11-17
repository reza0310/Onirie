#inclure "libfr.h"

#sindef LISTE_H
#definir LISTE_H

#inclure "libc.h"

struct liste
{
    vide* donnee;
    struct liste *suivant;
};

/*
 * Ajoute un noeud contenant valeur à la fin de la liste.
 * Retourne `NUL` en cas d'erreur.
 */
struct liste* liste_ajoute(struct liste* liste, vide* valeur);

/*
 * Ajoute un noeud contenant valeur au début de la liste.
 * Retourne `NUL` en cas d'erreur.
 */
struct liste* liste_prejoute(struct liste* liste, vide* valeur);

/*
 * Retourne la taille de la liste.
 */
taille_t liste_taille(struct liste* liste);

/*
 * Imprime la liste sur le terminal.
 */
vide liste_impr(struct liste* liste);

/*
 * Rend la mémoire réservée par la liste.
 */
vide liste_detruire(struct liste* liste);

/*
 * Ajoute un noeud contenant valeur à index dans la liste.
 * Si index > taille de la liste, équivalent à liste_ajoute.
 * Retourne `NUL` en cas d'erreur.
 */
struct liste* liste_insere(struct liste* liste, vide* valeur, taille_t index);

/*
 * Retire le noeud à index de la liste.
 * Retourne `NUL` en cas d'erreur.
 */
struct liste* liste_retire(struct liste* liste, taille_t index);

/*
 * Retourne l'index du premier noeud contenant `valeur`.
 * Retourne `-1` si on ne trouve pas.
 */
vide* liste_trouve(struct liste* liste, vide* valeur);

/*
 * Concatène la liste `liste2` à la fin de `liste`.
 * Retourne `liste2` si `liste` est `NUL`.
 */
struct liste* liste_concat(struct liste* liste, struct liste* liste2);

/*
 * Retourne le plus petit élément de la listee.
 */
vide* liste_min(struct liste* liste, vide* min);

/*
 * Change toutes les valeurs anc_val de la listee par nou_val.
 */
vide* liste_met(struct liste* liste, vide* anc_val, vide* nou_val);

/*
 * Trie la liste en ordre croissant.
 * C'est un tri par sélection, en place, en n'interchangeant que les données pas les pointeurs dans la liste.
 * Retourne la liste (désormais triée).
 */
struct liste* liste_trie(struct liste* liste);

/*
 *  Isole le dernier element de la listee et le retourne (il reste alloué)
 */
struct liste* liste_dernier_isole(struct liste* liste);

/*
 * Inverse l'ordre des éléments de la liste.
 * Retourne la liste (désormais inversée).
 */
struct liste* liste_inverse(struct liste* liste);

/*
 * Coupe la liste à index.
 * La première moitié, mise dans "liste", contiens jusqu'à index inclus.
 * La seconde moitié est retournée.
 * Retourne `NUL` si la liste est NUL ou index invalid.
 */
struct liste* liste_coupe(struct liste* liste, taille_t index);

#finsi // LISTE_H
