#pragma once

#include <istream>

#include "astnode.hpp"
#include "lexer.hpp"

class Parser
{

private:
  void next_token();

  ASTNode *expr();
  ASTNode *term(ASTNode *temp_leaf);
  ASTNode *prim();

  Lexer &lexer_;
  Lexer::Token tok_;
  Lexer::Token prev_token;
  Lexer::Token current_token;
  bool parsing_error = false;

public:
  explicit Parser(Lexer &lexer)
      : lexer_(lexer) {}

  Parser(const Parser &other) = delete;

  Parser &operator=(const Parser &other) = delete;

  ~Parser() = default;

  ASTNode *parse();

  bool get_error_status() const { return parsing_error; }

protected:
  void set_parsing_error() { parsing_error = true; }
};
