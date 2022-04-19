PWD = $(shell pwd)

SRC = $(PWD)/src
MAIN = $(PWD)/main

STACK = $(MAIN)/main_stack

SUBDIRS = $(SRC)

all:	main
	$(shell mkdir build)
	$(shell cp $(STACK) ./build/)

main:	_all
	$(MAKE) -C $(MAIN)

_all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:	mclear
	$(shell rm -rf build)

mclear:	_clean
	$(MAKE) -C $(MAIN) clean

_clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
