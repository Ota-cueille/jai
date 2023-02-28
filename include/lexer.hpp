#pragma once

#include <cstdint>
#include <string>
// logging system

namespace lexer
{
	enum class token_type
	{
		none,
		lparen,
		rparen,
		identifier,
		integer_literal,
		decimal_literal,
		string_literal,
		count,
	};

	bool operator<(uint64_t i, token_type t);
	bool operator<=(uint64_t i, token_type t);
	bool operator>(uint64_t i, token_type t);
	bool operator>=(uint64_t i, token_type t);
	bool operator==(uint64_t i, token_type t);
	bool operator!=(uint64_t i, token_type t);

	bool operator<(token_type t, uint64_t i);
	bool operator<=(token_type t, uint64_t i);
	bool operator>(token_type t, uint64_t i);
	bool operator>=(token_type t, uint64_t i);
	bool operator==(token_type t, uint64_t i);
	bool operator!=(token_type t, uint64_t i);

	bool operator<(token_type t1, token_type t2);
	bool operator<=(token_type t1, token_type t2);
	bool operator>(token_type t1, token_type t2);
	bool operator>=(token_type t1, token_type t2);
	bool operator==(token_type t1, token_type t2);
	bool operator!=(token_type t1, token_type t2);

	struct token
	{
		token_type type;
		std::string value;
	};

	extern token lookahead;

	token eat(token_type t);

} // namespace lexer
