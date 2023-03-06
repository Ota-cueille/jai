#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "lexer.hpp"

int main(int ac, char *av[])
{
	const char *filename;
	if (ac == 2)
	{
		lexer::set_translation(av[1]);
	}
	else
	{
		printf("no input file was fiven falling back to \"./assets/main.jai\"\n");
		lexer::set_translation("./assets/main.jai");
	}

	// parse file
	while (lexer::lookahead.type != lexer::token_type::none)
		lexer::eat(lexer::lookahead.type);

	return 0;
}
