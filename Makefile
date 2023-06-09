CC ?= gcc
CFLAGS ?= -g -Wall
LIBS = -lncurses

VERSION ?= SPECIFY A VERSION

SRC = main.c information.c editor.c
EXEC = hexedit

PREFIX ?= /usr/local

.PHONY: build
build: $(SRC)
	@echo -e "\033[32m>>> Compiling...\033[0m"
	$(CC) $(CFLAGS) $^ -o $(EXEC) $(LIBS)
	@echo -e "\033[32m>>> Compilation Complete.\033[0m"

.PHONY: install
install: $(EXEC)
	@echo -e "\033[32m>>> Installing...\033[0m"
	install -D $< $(DESTDIR)$(PREFIX)/bin/$(EXEC)
	@echo -e "\033[32m>>> Installation Complete.\033[0m"

.PHONY: clean
clean:
	rm -rf $(EXEC)
	rm -rf release/
	rm -rf hexedit.1.gz

.PHONY: manual
manual:
	pandoc man.md -s -t man -o hexedit.1
	gzip -qf hexedit.1

.PHONY: release
release: $(SRC) manual
	@echo -e "\033[32m>>> Building for release.\033[0m"
	mkdir -p release/
	$(CC) $(CFLAGS) -m64 $(SRC) -o release/hexedit_$(VERSION)_linux_amd64 $(LIBS)
	$(CC) $(CFLAGS) -m32 $(SRC) -o release/hexedit_$(VERSION)_linux_386 $(LIBS)
	cd release/ ; \
		tar -czvf hexedit_$(VERSION)_linux_386.tar.gz hexedit_$(VERSION)_linux_386 ; \
		tar -czvf hexedit_$(VERSION)_linux_amd64.tar.gz hexedit_$(VERSION)_linux_amd64 ; \
		cp ../hexedit.1.gz . ; \
		sha256sum hexedit_$(VERSION)_linux_386.tar.gz hexedit_$(VERSION)_linux_amd64.tar.gz > checksums.txt
	@echo -e "\033[32m>>> Release built, cleaning up.\033[0m"
	rm -rf release/hexedit_$(VERSION)_linux_386 release/hexedit_$(VERSION)_linux_amd64
	@echo -e "\033[32m>>> Cleaned up. Done building release.\033[0m"
