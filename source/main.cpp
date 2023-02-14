#include <cstdint>
#include <cstdio>
#include <cstdlib>

int main(int ac, char *av[])
{
	printf("Hello, World!\n");

	const char *filename;
	if (ac == 2)
	{
		filename = av[1];
	}
	else
	{
		printf("no input file was fiven falling back to \"./assets/main.jai\"");
		filename = "assets/main.jai";
	}

	FILE *source_file = fopen(filename, "r");
	fseek(source_file, 0, SEEK_END);
	uint64_t file_size = ftell(source_file);
	fseek(source_file, 0, SEEK_CUR);

	char *buffer = (char *)malloc(sizeof(char) * file_size);
	fread(buffer, sizeof(char), file_size, source_file);

	fclose(source_file);
	free(buffer);

	return 0;
}
