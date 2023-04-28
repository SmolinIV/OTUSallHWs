// OTUS C++ basic course homework.
// ASTNode
#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ASTNode
{
private:
	void inner_print(std::ostream &out, size_t indent) const;

	std::string repr_;
	ASTNode *lhs_;
	ASTNode *rhs_;

public:
	ASTNode();

	explicit ASTNode(const std::string &repr);

	ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

	ASTNode::ASTNode(ASTNode *exprRoot);

	ASTNode(const ASTNode &other) = delete;

	ASTNode &operator=(const ASTNode &other)
	{
		repr_ = other.repr_;
		lhs_ = other.lhs_;
		rhs_ = other.rhs_;
	}

	~ASTNode();

	std::string repr() const { return repr_; }

	void print(std::ostream &out) const;
};
