#include "lexer.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <regex>
#include <string>

#define SKIP_WHITESPACES true

extern std::array<std::regex, size_t(lexer::token_type::count)> token_regex;

namespace lexer
{
	token lookahead;

	struct file
	{
		const char *filepath;
		char *content;
		uint64_t curr, end;
	};

	static file translation;

	token next()
	{
		token tok = {
			.type = token_type::none,
			.value = "",
		};

		std::smatch match;
		std::string substr(&translation.content[translation.curr]);

#if SKIP_WHITESPACES == true

		if (std::regex_search(substr, match, token_regex[uint64_t(token_type::whitespaces)]))
		{
			tok.type = token_type::whitespaces;
			tok.value = match[0].str();
			translation.curr += match[0].length();
		}

#endif

		substr = std::string(&translation.content[translation.curr]);

		for (token_type t = token_type::whitespaces; t != token_type::none; t = token_type(uint64_t(t) + 1))
		{
			if (std::regex_search(substr, match, token_regex[uint64_t(t)]))
			{
				tok.type = t;
				tok.value = match[0].str();
				// printf("tok(type: %d): %s\n", tok.type, tok.value.c_str());

				translation.curr += match[0].length();
			}
		}
		return tok;
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
		auto current = lookahead;
		lookahead = next();
		return current;
	}

	void set_translation(const char *filepath)
	{
		if (translation.content)
		{
			free(translation.content);
		}
		translation.filepath = filepath;
		translation.curr = 0;

		auto source = fopen(filepath, "r");
		uint64_t buffer_size;

		fseek(source, 0, SEEK_END);
		buffer_size = ftell(source);
		translation.content = (char *)malloc(buffer_size * sizeof(char));
		fseek(source, 0, SEEK_SET);

		fread(translation.content, sizeof(char), buffer_size, source);
		translation.end = buffer_size;

		fclose(source);

		// read first lookahead
		lookahead = next();
	}

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

} // namespace lexer

std::array<std::regex, size_t(lexer::token_type::count)> token_regex = {
	std::regex(R"(^(\s+))"),						 // whitespaces
	std::regex(R"(^(\())"),							 // lparen
	std::regex(R"(^(\)))"),							 // rparen
	std::regex(R"(^(\+))"),							 // add_symbol
	std::regex(R"(^(-))"),							 // sub_symbol
	std::regex(R"(^(\d+))"),						 // integer_literal
	std::regex(R"(^((\d+\.\d*?)|(\d*\.\d+)))"),		 // decimal_literal
	std::regex(R"(^(".*?"))"),						 // string_literal
	std::regex(R"(^([_a-zA-Z][_a-zA-Z0-9]{0,30}))"), // identifier
													 // none | count
};
