#pragma once

#include "../ast.h"
#include "unit.h"

typedef struct codegen_t codegen_t;

codegen_t* create_codegen();
void destroy_codegen(codegen_t* codegen);

unit_t* codegen_gen(codegen_t* codegen, ast_t* ast);
void codegen_dump(codegen_t* codegen);



typedef struct out_t out_t;

out_t* create_out(codegen_t* codegen);
void destroy_out(out_t* out);

void out_obj(out_t* codegen, char* name);



typedef struct in_t in_t;

in_t* create_in();
void destroy_in(in_t* in);

char* in_read(in_t* in, char* filename);