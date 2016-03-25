#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__


#include <stdint.h>
#include <string.h>
#include <malloc.h>


enum HASHTABLE_SIZE {
    HT_SIZE_SMALL,
    HT_SIZE_NORMAL
};


typedef struct HASHTABLE_ENTRY {
    char* key;
    void* value;
    void (*destroy)(void* params);
    struct HASHTABLE_ENTRY* next;
} HASHTABLE_ENTRY;


typedef struct HASHTABLE {
    HASHTABLE_ENTRY** table;
    uint32_t size;
    void (*put)(struct HASHTABLE* hashtable, char* key, void* params_create, void* (*create)(void* params), void (*destroy)(void* params));
    void* (*get)(struct HASHTABLE* hashtable, char* key);
    void (*remove)(struct HASHTABLE* hashtable, char* key);
    uint8_t (*contains)(struct HASHTABLE* hashtable, char* key);
    uint16_t (*hash)(char* key, size_t len);
    void* (*string_create)(void* params);
    void (*string_destroy)(void* params);
} HASHTABLE;


#endif
