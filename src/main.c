#include "ast.h"
#include "codegen.h"
#include "lexer.h"
#include "parser.h"
#include "utils.h"

static void handle_no_files(args_t* args) {
  if (args_file_get_count(args) != 0)
    return;

  error("Usage: slang <file>");
}

static void handle_help(args_t* args) {
  if (!args_flags_get(args, FLAG_TYPE_HELP))
    return;
  log("\n");
  log("Usage: slang [options] <file> make\n");
  log("\n");
  log("Arguments: \n");
  log("  -i            | --ir             - generates LLVM IR in 'module.txt'.\n");
  log("  -o=<filename> | --out=<filename> - specifies output name (default 'out.o')\n");
  log("  -h            | --help           - prints this help\n");
  log("\n");

  exit(0);
}
static void handle_ir(args_t* args, out_t* out) {
  if (args_flags_get(args, FLAG_TYPE_IR))
    out_txt(out, "module.txt");
}

int main(int argc, char** argv) {
  args_t* args = create_args(argc, argv);

  handle_help(args);
  handle_no_files(args);

  in_t* in = create_in();
  lexer_t* lexer = create_lexer(in_read(in, args_file_get(args, 0)));
  parser_t* parser = create_parser(lexer);
  codegen_t* codegen = create_codegen();

  ast_t* ast;
  while ((ast = parser_parse(parser))) {
    codegen_gen(codegen, ast);
    destroy_ast(ast);
  }

  out_t* out = create_out(codegen);
  out_obj(out, args_flags_get(args, FLAG_TYPE_OUT));

  handle_ir(args, out);


  destroy_out(out);
  destroy_codegen(codegen);
  destroy_parser(parser);
  destroy_lexer(lexer);
  destroy_in(in);
  destroy_args(args);

  return 0;
}