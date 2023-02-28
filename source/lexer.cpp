#include "lexer.hpp"

#include <array>
#include <cstdint>
#include <regex>
#include <string>

std::array<std::regex, size_t(lexer::token_type::count)> token_regex;

namespace lexer
{
	token lookahead;

	token next()
	{
	}

	token eat(token_type t)
	{
		if (lookahead.type == token_type::none)
		{
			// trace error
		}
		else if (t != lookahead.type)
		{
			// trace error
		}
		token current;
		lookahead = next();
		return current;
	}

#pragma region "operators"

	bool operator<(uint64_t i, token_type t)
	{
		return i < uint64_t(t);
	}

	bool operator<=(uint64_t i, token_type t)
	{
		return i <= uint64_t(t);
	}

	bool operator>(uint64_t i, token_type t)
	{
		return i > uint64_t(t);
	}

	bool operator>=(uint64_t i, token_type t)
	{
		return i >= uint64_t(t);
	}

	bool operator==(uint64_t i, token_type t)
	{
		return i == uint64_t(t);
	}

	bool operator!=(uint64_t i, token_type t)
	{
		return i != uint64_t(t);
	}

	bool operator<(token_type t, uint64_t i)
	{
		return uint64_t(t) < i;
	}

	bool operator<=(token_type t, uint64_t i)
	{
		return uint64_t(t) <= i;
	}

	bool operator>(token_type t, uint64_t i)
	{
		return uint64_t(t) > i;
	}

	bool operator>=(token_type t, uint64_t i)
	{
		return uint64_t(t) >= i;
	}

	bool operator==(token_type t, uint64_t i)
	{
		return i == t;
	}

	bool operator!=(token_type t, uint64_t i)
	{
		return i != t;
	}

	bool operator<(token_type t1, token_type t2)
	{
		return uint64_t(t1) < uint64_t(t2);
	}

	bool operator<=(token_type t1, token_type t2)
	{
		return uint64_t(t1) <= uint64_t(t2);
	}

	bool operator>(token_type t1, token_type t2)
	{
		return uint64_t(t1) > uint64_t(t2);
	}

	bool operator>=(token_type t1, token_type t2)
	{
		return uint64_t(t1) >= uint64_t(t2);
	}

	bool operator==(token_type t1, token_type t2)
	{
		return uint64_t(t1) == uint64_t(t2);
	}

	bool operator!=(token_type t1, token_type t2)
	{
		return uint64_t(t1) != uint64_t(t2);
	}

#pragma region

} // namespace lexer

std::array<std::regex, size_t(lexer::token_type::count)> token_regex = {
	std::regex(""),								   // none
	std::regex(R"(^()"),						   // lparen
	std::regex(R"(^))"),						   // lparen
	std::regex(R"(^[_a-zA-Z][_a-zA-Z0-9]{0,30})"), // identifier
	std::regex(R"(^.+[1-9])"),					   // integer_literal
	std::regex(R"(^(\d+.\d*?)|(\d*\.\d+?))"),	   // decimal_literal
	std::regex(R"(^".*?")"),					   // string_literal
};
