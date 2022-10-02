#include "ast.h"
#include "codegen.h"
#include "lexer.h"
#include "parser.h"
#include "utils.h"

int main(int argc, char** argv) {
  if (argc < 2)
    error("Usage: slang [filename]");


  in_t* in = create_in();
  lexer_t* lexer = create_lexer(in_read(in, argv[1]));
  parser_t* parser = create_parser(lexer);
  codegen_t* codegen = create_codegen();

  ast_t* ast;
  while ((ast = parser_parse(parser))) {
    codegen_gen(codegen, ast);
  }

  out_t* out = create_out(codegen);
  out_obj(out, "out.o");

  destroy_out(out);
  destroy_codegen(codegen);
  destroy_parser(parser);
  destroy_lexer(lexer);
  destroy_in(in);

  return 0;
}