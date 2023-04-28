// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"cd 

int main()
{

    Lexer lexer(std::cin);
    Parser parser(lexer);

    ASTNode *ast = parser.parse();
    if (ast && lexer.get_brace_counter() == 0 && !parser.get_error_status())
    {
        ast->print(std::cout);
    }
    else
    {
        std::cout << "ERROR!" << std::endl;
    }
    return 0;
}