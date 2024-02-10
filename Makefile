CC = gcc
SRCDIR = src
BINDIR = bin
EXECUTABLE = $(BINDIR)/chore

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)

.PHONY: all clean

all: $(BINDIR) $(EXECUTABLE)

$(BINDIR):
	mkdir -p $(BINDIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

$(OBJECTS): $(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $<

clean:
	rm -rf $(BINDIR)/*
