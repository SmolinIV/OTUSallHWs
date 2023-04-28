// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include <iostream>
#include "lexer.hpp"

#include <cctype>

Lexer::Token Lexer::next_token()
{
    for (;;)
    {
        switch (state_)
        {
        case State::End:
            return Token::End;
        case State::ReadNumber:
            if (end())
            {
                state_ = State::End;
                return Token::Number;
            }
            if (std::isdigit(ch_))
            {
                number_ = 10 * number_ + (ch_ - '0');
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_))
            {
                state_ = State::End;
                return Token::End;
            }

            if (ch_ == ' ')
                while (ch_ == ' ')
                {
                    next_char();
                }

            state_ = State::Empty;
            return Token::Number;
        case State::ReadName:
            if (end())
            {
                state_ = State::End;
                return Token::Name;
            }
            if (std::isalpha(ch_) || std::isdigit(ch_))
            {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Name;
        case State::Empty:
            if (end())
            {
                state_ = State::End;
                return Token::End;
            }
            if (std::isspace(ch_))
            {
                next_char();
                break;
            }
            if (isoperator(ch_))
            {
                operator_ = ch_;
                next_char();
                return Token::Operator;
            }
            if (ch_ == '(')
            {
                ++brace_counter_;
                next_char();
                return Token::Lbrace;
            }
            if (ch_ == ')')
            {
                --brace_counter_;
                next_char();
                return Token::Rbrace;
            }
            if (std::isdigit(ch_))
            {
                number_ = ch_ - '0';
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_))
            {
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
            if (state_ == State::Empty)
            {
                return Token::End;
            }
        }
    }
}

// ѕроверка на неправильную последовательность токенов (два оператора, незавершЄнна€ строка и т.д.)
bool Lexer::incorrect_sequence(const Token prev_tok, const Token current_tok)
{
    switch (current_tok)
    {
    case Token::End:
        switch (prev_tok)
        {
        case Token::Start:
        case Token::Operator:
        case Token::Lbrace:
            return true;
        default:
            return false;
        }
    case Token::Lbrace:
        switch (prev_tok)
        {
        case Token::Number:
        case Token::Name:
            return true;
        default:
            return false;
        }
    case Token::Name:
        switch (prev_tok)
        {
        case Token::Name:
        case Token::Number:
        case Token::Rbrace:
            return true;
        default:
            return false;
        }
    case Token::Number:
        switch (prev_tok)
        {
        case Token::Name:
        case Token::Number:
        case Token::Rbrace:
            return true;
        default:
            return false;
        }
    case Token::Operator:
        switch (prev_tok)
        {
        case Token::Start:
        case Token::Operator:
        case Token::Lbrace:
            return true;
        default:
            return false;
        }
    case Token::Rbrace:
        switch (prev_tok)
        {
        case Token::Start:
        case Token::Operator:
        case Token::Lbrace:
            return true;
        default:
            return false;
        }
    case Token::Start:
        return true;
    }
}