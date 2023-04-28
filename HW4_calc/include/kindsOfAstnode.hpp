#pragma once

#include <string>
#include "astnode.hpp"

class Number : public ASTNode
{
private:
    int val_;

public:
    Number(int val) : ASTNode(std::to_string(val)), val_(val) {}

    int value() const { return val_; }
};

class Variable : public ASTNode
{
private:
    std::string name_;

public:
    Variable(std::string name) : ASTNode(name), name_(name) {}
};

class Add : public ASTNode
{
private:
    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;

public:
    Add(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
        : ASTNode(repr, lhs, rhs),
          repr_(repr),
          lhs_{lhs},
          rhs_{rhs} {}
};

class Sub : public ASTNode
{
private:
    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;

public:
    Sub(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
        : ASTNode(repr, lhs, rhs),
          repr_(repr),
          lhs_{lhs},
          rhs_{rhs} {}
};

class Mul : public ASTNode
{
private:
    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;

public:
    Mul(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
        : ASTNode(repr, lhs, rhs),
          repr_(repr),
          lhs_{lhs},
          rhs_{rhs} {}
};

class Div : public ASTNode
{
private:
    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;

public:
    Div(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
        : ASTNode(repr, lhs, rhs),
          repr_(repr),
          lhs_{lhs},
          rhs_{rhs} {}
};

class inBraces : public ASTNode
{
private:
    ASTNode *exprRoot_;

public:
    inBraces(ASTNode *exprRoot)
        : ASTNode(exprRoot), exprRoot_{exprRoot} {}
};