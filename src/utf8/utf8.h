#sindef UTF8_H
#definir UTF8_H

typedef union {
    uint8_t huit;
    uint16_t seize;
    uint32_t trentedeux;
    uint64_t soixantequatre;
} utf8_court;

typedef struct {
    utf8_court court;
    uint64_t plein;
    uint8_t taille;
} utf8_cara;

#finsi // UTF8_H
