CC = gcc
CFLAGS = -pedantic -Werror -Wall -Wextra -Wvla -Isrc
LDFLAGS =
OBJS:= $(shell find src -type f -name '*.o')

liste: src/liste/liste.o
utf8: liste src/utf8/utf8.o
liste utf8:
	$(CC) $(LDFLAGS) $(shell find build -type f -name '*.o') -o $@

$(OBJS): %.o: %.c
	python prepreprocessor.py $@ > /tmp/prepreprocessed.c
	$(CC) -c $(CFLAGS) /tmp/prepreprocessed.c -o $<
	mkdir -p build
	mv $< build

clean:
	rm -rf build
