CFLAGS = -Wall -Wextra -std=c99 -Wshadow -pipe -march=native -Wno-unused-parameter -g -g3 -ggdb
all: disambiguate
disambiguate: disambiguate.o
	cc $(CFLAGS) disambiguate.o -o disambiguate
