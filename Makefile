TARGET=papercities

CC=gcc
CFLAGS=-g -O2 -Wall -luuid `sdl2-config --cflags --libs` -Iinclude

OBJS:=$(patsubst src/%.c,bin/%.o,$(shell find src -name '*.c'))

.PHONY: ${TARGET}

$(TARGET): $(OBJS)
	if [ ! -d "target" ]; then mkdir -p target; fi
	$(CC) $(CFLAGS) $(OBJS) -o target/$(TARGET)

bin/%.o: src/%.c
	if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf bin
