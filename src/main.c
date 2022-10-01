#include "ast.h"
#include "codegen.h"
#include "parser.h"
#include "utils.h"

int main(int argc, char** argv) {
  if (argc < 2)
    error("Usage: slang [filename]");


  // in_init(argv[1]);
  // codegen_init();

  // ast_t* ast;
  // while ((ast = parser_parse())) {
  //   codegen(ast);
  // }

  // out_init();
  // out_obj("out.o");

  return 0;
}