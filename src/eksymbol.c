/* 
 * Symbol table implementation for the Yoruba language
 * Copyright (C) 2024 Joseph Daniel
 */
#include <stdio.h>
#include "ekmem.h"
#include "ekun.h"
#include "eksymbol.h"
#include <stdlib.h>
#define __TEST

/* hash function  for the symbol table uses FNV-1a hash algorithm
 */

uint32_t hash(const char* key, int length) {
 uint32_t hash = 2166136261u;
 for (int i = 0; i < length; i++) {
 hash ^= key[i];
 hash *= 16777619;
 }
 return hash;
}


Symbol * new_table(void){
    Symbol * new = ek_malloc(sizeof(*new));
    new->size = 0;
    new->capacity = 0;
    new->bucket = NULL;
    return new;
}

/* Return the list entry containing key in table. if no list entry has key
 * return NULL
 */
Entry * lookup(Symbol * table, Objstring * key){
    uint32_t index = key->hash;

    Entry * entry = table->bucket[index % table->capacity];
    while(entry != NULL){
        if(CMP_EQUAL(entry->key->ch, key->ch)) break;
        entry = entry->next;
    }
    return entry;
}

void adjust_table(Symbol * table){
    int capacity = table->capacity == 0 ?
        INITIAL_SIZE : table->capacity * 2;
    int index;

        Entry ** bucket = ek_malloc(capacity * sizeof(Entry *));

        for(int i = 0; i < capacity; i++ )
            bucket[i] = NULL;

        for(int i = 0; i < table->capacity; i++){
            Entry * ptr = table->bucket[i];
            while(ptr != NULL){
                index = ptr->key->hash % capacity;
                Entry * ptr_next = ptr->next;
                ptr->next = bucket[index];
                bucket[index] = ptr;
                ptr = ptr_next;
            }
        }
        EK_FREE(table->bucket);
        table->capacity = capacity;
        table->bucket = bucket;
}


Lval * table_get(Symbol * table, Objstring * key){
    Entry * entry = lookup(table, key);
    return entry == NULL ? NULL : entry->value;
}


/* get value from hash table if it exists otherwise return null */
Entry * table_put(Symbol * table, Objstring * key, Lval * value){
    if (table->size + 1 >= table->capacity * GROWTH_RATE)
        adjust_table(table);

    Entry * entry =lookup(table, key);

    if (entry){
        entry->value = value;
        return entry;
    }
    else {
        uint32_t index = key->hash % table->capacity;
        entry = ek_malloc(sizeof(*entry));
        entry->key = key;
        entry->value = value;
        entry->next = table->bucket[index];
        table->bucket[index] = entry;
        table->size++;
    }
    return entry;
}


void free_entries(Symbol * table){
    EK_FREE(table->bucket);
}
