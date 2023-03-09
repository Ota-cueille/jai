#include "parser.hpp"

#include "lexer.hpp"

namespace parser
{
	/**
	 * Expression:
	 * 	| Term (+|-) Term;
	 */
	void expression()
	{
		printf("Expression(");
		term();
		switch (lexer::lookahead.type)
		{
		case lexer::token_type::add_symbol:
		{
			auto t = lexer::eat(lexer::token_type::add_symbol);
			printf(" %s ", t.value.c_str());
			break;
		}
		case lexer::token_type::sub_symbol:
		{
			auto t = lexer::eat(lexer::token_type::sub_symbol);
			printf(" %s ", t.value.c_str());
			break;
		}
		default:
		{
			auto t = lexer::eat(lexer::lookahead.type);
			printf("%s  \"Error, undefined operator <%s> in expression !\" %s ", "\033[0;31m", t.value.c_str(), "\033[0m");
			break;
		}
		}
		term();
		printf(")\n");
	}

	/**
	 * Term:
	 * 	| <identifier>
	 * 	| <integer_literal>
	 * 	| <decimal_literal>
	 */
	void term()
	{
		switch (lexer::lookahead.type)
		{
		case lexer::token_type::decimal_literal:
		{
			auto t = lexer::eat(lexer::token_type::decimal_literal);
			printf("Term(%s)", t.value.c_str());
			break;
		}
		case lexer::token_type::integer_literal:
		{
			auto t = lexer::eat(lexer::token_type::integer_literal);
			printf("Term(%s)", t.value.c_str());
			break;
		}
		case lexer::token_type::identifier:
		{
			auto t = lexer::eat(lexer::token_type::identifier);
			printf("Term(%s)", t.value.c_str());
			break;
		}
		default:
		{
			auto t = lexer::eat(lexer::lookahead.type);
			printf("Error: %s is not a valid term in expression !\n", t.value.c_str());
			break;
		}
		}
	}
} // namespace parser
