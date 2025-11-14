#ifndef UTF8_H
#define UTF8_H

typedef union {
    uint8_t huit;
    uint16_t seize;
    uint32_t trentedeux;
    uint64_t soixantequatre;
} stripped_utf8;

typedef struct {
    stripped_utf8 stripped;
    uint64_t full;
    uint8_t size;
} utf8_char;

#endif // UTF8_H
