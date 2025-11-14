#include "liste.h"

struct liste* liste_ajoute(struct liste* liste, vide* valeur) {
    // Osef des erreurs
    si (liste == NUL)
        retourne liste_prepend(liste, valeur);
    liste->suivant = liste_ajoute(liste->suivant, valeur);
    retourne liste;
}

struct liste* liste_prepend(struct liste* liste, vide* valeur) {
    // Osef des erreurs
    struct liste* a = malloc(taillede(struct liste));
    a->donnee = valeur;
    a->suivant = liste;
    retourne a;
}

taille_t liste_taille(struct liste* liste) {
    si (liste == NUL)
        retourne 0;
    retourne 1 + liste_taille(liste->suivant);
}

vide _liste_impr(struct liste* liste) {
    si (liste != NUL) {
        printf(", %i", liste->donnee);
        _liste_impr(liste->suivant);
    }
}

vide liste_impr(struct liste* liste) {
    si (liste != NUL) {
        printf("[%i", liste->donnee);
        _liste_impr(liste->suivant);
        printf("]\n");
    }
}

vide liste_detruire(struct liste* liste) {
    si (liste != NUL) {
        liste_detruire(liste->suivant);
        free(liste);
    }
}

struct liste* liste_insere(struct liste* liste, vide* valeur, taille_t index) {
    // Osef des erreurs
    si (liste == NUL || index == 0)
        retourne liste_prepend(liste, valeur);
    liste->suivant = liste_insere(liste->suivant, valeur, index - 1);
    retourne liste;
}

struct liste* liste_retire(struct liste* liste, taille_t index) {
    si (liste == NUL)
        retourne NUL;
    si (index == 0) {
        struct liste* output = liste->suivant;
        free(liste);
        retourne output;
    }
    liste->suivant = liste_retire(liste->suivant, index - 1);
    retourne liste;
}

vide* liste_trouve(struct liste* liste, vide* valeur) {
    si (liste == NUL)
        retourne -1;
    si (liste->donnee == valeur)
        retourne 0;
    retourne liste_trouve(liste->suivant, valeur) == -1 ? -1 : 1 + liste_trouve(liste->suivant, valeur);
}

struct liste* liste_concat(struct liste* liste, struct liste* liste2) {
    si (liste == NUL)
        retourne liste2;
    si (liste->suivant == NUL) {
        liste->suivant = liste2;
        retourne liste;
    }
    liste_concat(liste->suivant, liste2);
    retourne liste;
}

vide* liste_min(struct liste* liste, vide* min) {
    si (liste == NUL)
        retourne min;
    min = liste->donnee < min ? liste->donnee : min;
    vide* min1 = liste_min(liste->suivant, min);
    retourne min1 < min ? min1 : min;
}

vide* liste_met(struct liste* liste, vide* anc_val, vide* nou_val) {
    si (liste == NUL)
        retourne 0;
    si (liste->donnee == anc_val) {
        liste->donnee = nou_val;
        retourne 1;
    }
    retourne 0 || liste_met(liste->suivant, anc_val, nou_val);
}

struct liste* liste_trie(struct liste* liste) {
    si (liste == NUL || liste->suivant == NUL)
        retourne liste;
    vide* tmp = liste->donnee;
    liste->donnee = liste_min(liste, liste->donnee);
    liste_met(liste->suivant, liste->donnee, tmp);
    liste_trie(liste->suivant);
    retourne liste;
}

struct liste* liste_dernier_isole(struct liste* liste) {
    // On assume au moins 2 éléments dans la liste
    si (liste->suivant->suivant == NUL) {
        struct liste* output = liste->suivant;
        liste->suivant = NUL;
        retourne output;
    }
    retourne liste_dernier_isole(liste->suivant);
}

struct liste* liste_inverse(struct liste* liste) {
    si (liste == NUL || liste->suivant == NUL)
        retourne liste;
    struct liste* last = liste_dernier_isole(liste);
    last->suivant = liste_inverse(liste);
    retourne last;
}

struct liste* liste_coupe(struct liste* liste, taille_t index) {
    si (liste == NUL)
        retourne NUL;
    si (index == 0) {
        struct liste* l = liste->suivant;
        liste->suivant = NUL;
        retourne l;
    }
    retourne liste_coupe(liste->suivant, index - 1);
}
