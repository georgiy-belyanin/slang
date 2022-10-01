#include "word_lexer.h"

#include <ctype.h>
#include "keyword.h"

token_t lexer_next_word(lexer_t* lexer) {
  char* word = calloc(sizeof(char), 50);

  for(int i = 0; i < sizeof(word) && isalnum(lexer->cur); i++) {
    word[i] = lexer->cur;
    lexer_next(lexer);
  }
  if (strcmp(word, KEYWORD_TRAIT) == 0)
    return TOKEN_TRAIT;
  else if (strcmp(word, KEYWORD_STRUCT) == 0)
    return TOKEN_STRUCT;
  else if (strcmp(word, KEYWORD_FUNC) == 0)
    return TOKEN_FUNC;
  else if (strcmp(word, KEYWORD_LET) == 0) 
    return TOKEN_LET;
  else if (strcmp(word, KEYWORD_RET) == 0) 
    return TOKEN_RET;
  else if (strcmp(word, KEYWORD_EXT) == 0) 
    return TOKEN_EXT;
  else if (strcmp(word, KEYWORD_IF) == 0) 
    return TOKEN_IF;
  else if (strcmp(word, KEYWORD_ELSE) == 0) 
    return TOKEN_ELSE;
  else if (strcmp(word, KEYWORD_WHILE) == 0) 
    return TOKEN_WHILE;
  else if (strcmp(word, KEYWORD_LOOP) == 0) 
    return TOKEN_LOOP;
  else if (strcmp(word, KEYWORD_NEW) == 0)
    return TOKEN_NEW;
  else if (strcmp(word, KEYWORD_DEL) == 0)
    return TOKEN_DEL;
  else if (strcmp(word, KEYWORD_TRUE) == 0)
    return TOKEN_TRUE;
  else if (strcmp(word, KEYWORD_FALSE) == 0)
    return TOKEN_FALSE;
  else {
    lexer->ident = word;
    return TOKEN_IDENT;
  }
}