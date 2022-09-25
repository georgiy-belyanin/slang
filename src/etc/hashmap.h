#pragma once

typedef struct hashmap_t hashmap_t;

hashmap_t* create_hashmap();
void destroy_hashmap(hashmap_t* hashmap);

void* hashmap_get(hashmap_t* hashmap, char* key);
void hashmap_set(hashmap_t* hashmap, char* key, void* val);

int hashmap_contains(hashmap_t* hashmap, char* key);