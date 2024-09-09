CC := gcc

CFLAGS  := -g -Wall
LDFLAGS := -lm

SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:%.c=%.app)

all: $(OBJS)

%.app: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJS)

