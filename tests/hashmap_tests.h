#pragma once

#include <string.h>
#include "../src/etc.h"
#include "test.h"

TEST(hashmap, create) {
  hashmap_t* hashmap = create_hashmap();
  destroy_hashmap(hashmap);
  return 0;
}
TEST(hashmap, set) {
  hashmap_t* hashmap = create_hashmap();
  hashmap_set(hashmap, "foo", "bar");
  destroy_hashmap(hashmap);
  return 0;
}
TEST(hashmap, get) {
  hashmap_t* hashmap = create_hashmap();
  hashmap_set(hashmap, "foo", "bar");
  hashmap_set(hashmap, "buz", "qux");
  assert(strcmp(hashmap_get(hashmap, "foo"), "bar") == 0);
  assert(strcmp(hashmap_get(hashmap, "buz"), "qux") == 0);
  hashmap_set(hashmap, "foo", "foo");
  assert(strcmp(hashmap_get(hashmap, "foo"), "foo") == 0);
  destroy_hashmap(hashmap);
  return 0;
}

TESTS(hashmap) {
  test_run(hashmap, create);
  test_run(hashmap, set);
  test_run(hashmap, get);
}
