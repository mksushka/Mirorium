#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef PATH_PREFIX
#define PATH_PREFIX ""
#endif
#define TOKEN_LENGTH 32

int generate_random_bytes(uint8_t *buffer, size_t length) {
	FILE *urandom = fopen("/dev/urandom", "rb");
	if (!urandom) return -1;
	size_t read_bytes = fread(buffer, 1, length, urandom);
	fclose(urandom);
	return (read_bytes == length) ? 0 : -1;
}

int main(int argc, char *argv[]) {
	if (argc < 2 || strcmp(argv[1], "tokenadd") != 0) {
		fprintf(stderr, "Usage: %s tokenadd\n", argv[0]);
		return 1;
	}

	uint8_t raw_token[TOKEN_LENGTH];
	if (generate_random_bytes(raw_token, TOKEN_LENGTH) != 0) {
		fprintf(stderr, "Generation error\n");
		return 1;
	}

	char hex_token[TOKEN_LENGTH * 2 + 1];
	for (size_t i = 0; i < TOKEN_LENGTH; i++) {
		sprintf(&hex_token[i * 2], "%02x", raw_token[i]);
	}
	hex_token[TOKEN_LENGTH * 2] = '\0';

	FILE *f = fopen(PATH_PREFIX "/c/mir/token.secret", "r");
	if (f) {
		fclose(f);
		f = fopen(PATH_PREFIX "/c/mir/token.secret", "a");
	} else {
		f = fopen(PATH_PREFIX "/c/mir/token.secret", "w");
	}

	if (!f) {
		fprintf(stderr, "File opening error\n");
		return 1;
	}

	fprintf(f, "%s\n", hex_token);
	fclose(f);

	printf("%s\n", hex_token);
	return 0;
}
