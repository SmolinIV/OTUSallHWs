#include "parser.hpp"
#include "kindsOfAstnode.hpp"

using Token = Lexer::Token;

// Начинаем пасринг с присваивания стартового Токена (чтобы опроеделить ошбику ввода первыого символа)
ASTNode *Parser::parse()
{
	tok_ = Token::Start;
	return expr();
}

// Запоминаем текущий токен и парсим следующий, после чего проверяем их на правильную последвательность
void Parser::next_token()
{
	prev_token = tok_;
	tok_ = lexer_.next_token();
	current_token = tok_;

	if (lexer_.incorrect_sequence(prev_token, current_token))
	{
		parsing_error = true;
		tok_ = Token::End;
	}
}

// Парсим ветки сложения и вычитания.
ASTNode *Parser::expr()
{
	ASTNode *root = prim();
	ASTNode *temp_leaf;
	ASTNode *temp_root;
	std::string op;
	while (tok_ != Token::End)
	{
		if (tok_ == Token::Operator)
		{
			op = lexer_.get_operator();
			switch (op.front())
			{
			case '+':
				temp_leaf = prim();
				temp_root = term(temp_leaf);
				root = new Add(op, root, temp_root);
				break;
			case '-':
				temp_leaf = prim();
				temp_root = term(temp_leaf);
				root = new Sub(op, root, temp_root);
				break;
			case '*':
			case '/':
				root = (op, root, term(root));
			}
		}
		// Проверка на завершение скобочного выражения (открытие скобок проверяется в парсере чисел/имён)
		if (tok_ == Token::Rbrace)
		{
			if (lexer_.get_brace_counter() < 0)
			{
				tok_ = Token::End;
				return nullptr;
			}
			return root;
		}
	}

	return root;
}

// Парсим ветку умножения и деления.
ASTNode *Parser::term(ASTNode *temp_leaf)
{
	if (tok_ == Token::Rbrace)
	{
		return temp_leaf;
	}
	while (tok_ != Token::End)
	{
		if (tok_ == Token::Operator)
		{
			std::string op = lexer_.get_operator();
			switch (op.front())
			{
			case '+':
			case '-':
				return temp_leaf;
			case '*':
				temp_leaf = new Mul(op, temp_leaf, prim());
				break;
			case '/':
				temp_leaf = new Div(op, temp_leaf, prim());
				break;
			}
		}
		// Проверка на завершение скобочного выражения (открытие скобок проверяется в парсере чисел/имён)
		if (tok_ == Token::Rbrace)
		{
			if (lexer_.get_brace_counter() < 0)
			{
				tok_ = Token::End;
				return nullptr;
			}
			return temp_leaf;
		}
	}
	return temp_leaf;
}

// Парсим числа и имена, а так же создаём новый корень, если открывается скобка
ASTNode *Parser::prim()
{
	ASTNode *node = nullptr;

	if (!parsing_error)
	{
		next_token();
	}

	switch (tok_)
	{
	case Token::Lbrace:
		node = expr();
		break;
	case Token::Number:
		node = new Number(lexer_.get_number());

		break;
	case Token::Name:
		node = new Variable(lexer_.get_name());

		break;
	}

	if (!parsing_error)
	{
		next_token();
	}
	return node;
}