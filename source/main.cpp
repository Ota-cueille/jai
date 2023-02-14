#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int ac, char *av[])
{
	const char *filename;
	if (ac == 2)
	{
		filename = av[1];
	}
	else
	{
		printf("no input file was fiven falling back to \"./assets/main.jai\"\n");
		filename = "assets/main.jai";
	}

	FILE *source_file = fopen(filename, "r");
	fseek(source_file, 0, SEEK_END);
	uint64_t file_size = ftell(source_file);
	fseek(source_file, 0, SEEK_SET);

	char *buffer = (char *)malloc(sizeof(char) * file_size);
	memset(buffer, '\0', sizeof(char) * file_size);
	fread(buffer, sizeof(char), file_size, source_file);

	printf(buffer);

	fclose(source_file);
	free(buffer);

	return 0;
}
