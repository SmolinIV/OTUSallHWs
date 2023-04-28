// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>

class Lexer
{
private:
  enum class State
  {
    Empty,
    ReadNumber,
    ReadName,
    End,
  };
  char next_char();
  bool end() const;

  State state_;
  std::string name_;
  int number_;
  std::string operator_;
  char ch_;
  std::istream &in_;

  int brace_counter_ = 0;

protected:
  bool isbrace(char ch) const;

  bool isoperator(char ch) const;

public:
  enum class Token
  {
    Number,
    Operator,
    End,
    Lbrace,
    Rbrace,
    Name,
    Start
  };

  explicit Lexer(std::istream &in);

  Lexer(const Lexer &other) = delete;

  Lexer &operator=(const Lexer &other) = delete;

  Token next_token();

  bool incorrect_sequence(const Token prev_tok, const Token current_tok);

  int get_number() const { return number_; }

  std::string get_operator() const { return operator_; }

  std::string get_name() const { return name_; }

  int get_brace_counter() { return brace_counter_; };
};

inline Lexer::Lexer(std::istream &in) : state_(State::Empty), number_(0), in_(in) { next_char(); }

inline char Lexer::next_char()
{
  in_.get(ch_);
  return ch_;
}

inline bool Lexer::end() const { return in_.eof() || ch_ == '\n'; }

inline bool Lexer::isbrace(char ch) const { return ch == '(' || ch == ')'; }

inline bool Lexer::isoperator(char ch) const
{
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
