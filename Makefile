CC ?= gcc
CFLAGS ?= -g -Wall
LIBS = -lncurses

SRC = main.c information.c
EXEC = hexedit

PREFIX ?= /usr/local

.PHONY: build
build: $(SRC)
	@echo "Compiling..."
	$(CC) $(CFLAGS) $^ -o $(EXEC) $(LIBS)
	@echo "Compilation Complete."

.PHONY: install
install: $(EXEC)
	@echo "Installing..."
	install -D $< $(DESTDIR)$(PREFIX)/bin/$(EXEC)
	@echo "Installation Complete."

.PHONY: clean
clean:
	rm -rf $(EXEC)
