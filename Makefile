CFLAGS= -std=c11 -g -static -Wall
DEPFLAGS= -MT $@ -MMD -MP -MF $*.d
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
BIN=uncc

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c %.d
	$(CC) $(DEPFLAGS) $(CFLAGS) -c -o $@ $<

$(DEPS):

include $(wildcard $(DEPS))

run:
	./$(BIN)

test: $(BIN)
	./test.sh

clean:
	rm -f $(BIN) *.o core.* *.d

.PHONY: test clean run

