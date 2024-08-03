#ifndef __EKSYMBOL_H
#define __EKSYMBOL_H
#include "ektypes.h"
#include <stdint.h>

/* Entry data structure for the hash table */
typedef struct entry {
    Objstring * key;
    Lval * value;
    struct entry * next;
} Entry;

#define INITIAL_SIZE 8
#define GROWTH_RATE 0.75

typedef struct symbol {
    int size;
    int capacity;
    Entry ** bucket;
} Symbol;

/* get the data from an entry with key X, from table T 
 * Can cause error since no checking is perform for null
 * Assume the key exiss in the table
 * */

uint32_t hash(const char* key, int length);
static inline uint32_t hash_string(Objstring * obj){
    return hash(obj->ch, obj->length);
}

Symbol * new_table(void);
Entry * lookup(Symbol * table, Objstring * key);
Entry * table_put(Symbol * table, Objstring * key, Lval * value);
void free_entries(Symbol * table);
void  adjust_table(Symbol  * table);
#endif
