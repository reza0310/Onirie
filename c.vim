" Fichier syntax de la libfr

" Une macro se met en début de ligne qu'importe l'indentation
syntax match cDefine /^#definir/
syntax match cDefine /^#dedef/
syntax match cInclude /^#inclure/
syntax match cPreProc /^#si/
syntax match cPreProc /^#snsi/
syntax match cPreProc /^#sinn/
syntax match cPreProc /^#finsi/
syntax match cPreProc /^#attention/
syntax match cPreProc /^#erreur/
syntax match cPreProc /^#ligne/

" Un type est suivi d'un espace ou d'une étoile si c'est un pointeur sur type
syntax match cType /vide[ \*]/
syntax match cType /cara[ \*]/
syntax match cType /ent[ \*]/
syntax match cType /flot[ \*]/
syntax match cType /court[ \*]/
syntax match cType /signe[ \*]/
syntax match cType /nnsigne[ \*]/
syntax match cType /taille_t[ \*]/

syntax match cConditional /si[ \n]/
syntax match cConditional /sinn[ \n]/
syntax match cConditional /saute[ \n]/
syntax match cConditional /cas[ \n]/
syntax match cConditional /defaut[ \n]/
syntax match cRepeat /pour[ \n]/
syntax match cRepeat /tantq[ \n]/
syntax match cRepeat /fait[ \n]/
syntax match cOperator /casse/
syntax match cOperator /retourne/
syntax match cOperator /vaa/

syntax match cConstant /NUL/
syntax match cOperator /taillede/
syntax match cType /deftype/
