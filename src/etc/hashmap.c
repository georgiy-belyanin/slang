#include "hashmap.h"

#include <stdlib.h>
#include <string.h>
#include "../utils.h"

#define CAP 2048

typedef struct pair_t pair_t;
struct pair_t {
  char* key;
  void* val;
  pair_t* next;
};
struct hashmap_t {
  pair_t** pairs;
};

static pair_t* create_pair(char* key, void* val) {
  pair_t* pair = malloc(sizeof(pair));
  pair->key = key;
  pair->val = val;
  return pair;
}
static void destroy_pair(pair_t* pair) {
  free(pair);
}

hashmap_t* create_hashmap() {
  hashmap_t* hashmap = malloc(sizeof(hashmap_t));
  hashmap->pairs = calloc(sizeof(pair_t*), CAP);
  return hashmap;
}
void destroy_hashmap(hashmap_t* hashmap) {
  for(int i = 0; i < CAP; i++)
    destroy_pair(hashmap->pairs[i]);
  free(hashmap->pairs);
  free(hashmap);
}

static unsigned int hash(hashmap_t* hashmap, char* key) {
  unsigned code;
  for (code = 0; *key != '\0'; key++) {
    code = *key + 31 * code;
  }
  return code % (CAP);
}

void* hashmap_get(hashmap_t* hashmap, char* key) {
  for (pair_t* cur = hashmap->pairs[hash(hashmap, key)]; cur != NULL; cur = cur->next)
    if (strcmp(cur->key, key) == 0) 
      return cur->val;
  return NULL;
}
void hashmap_set(hashmap_t* hashmap, char* key, void* val) {
  pair_t* pair = create_pair(key, val);
  pair_t* prev = hashmap->pairs[hash(hashmap, key)];

  if (prev == NULL) {
    hashmap->pairs[hash(hashmap, key)] = pair;
    return;
  }

  do {
    if (strcmp(prev->key, key) == 0) {
      prev->val = val;
      destroy_pair(pair);
      return;
    }

    prev = prev->next;
  } while (prev != NULL);

  prev->next = pair;
}
int hashmap_contains(hashmap_t* hashmap, char* key) {
  return hashmap->pairs[hash(hashmap, key)] != NULL;
}