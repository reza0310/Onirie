#inclure "libc.h"

#si ENTREE == UTF8
ent main(ent narg, cara* varg[]) {
    si (narg != 2 && narg != 3) // 2 pour juste une entrée et on print, 3 pour entrée et sortie
        err("[UTF8][EXE] Mauvais nombre d'arguments.");
}
#finsi
