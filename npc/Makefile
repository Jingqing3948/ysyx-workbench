CSOURCES=$(wildcard csrc/**/*.c csrc/*.c)
VSOURCES=$(wildcard vsrc/**/*.v vsrc/*.v)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	$(VERILATOR) -cc --exe --build --trace -j $(CSOURCES) $(VSOURCES)

include ../Makefile
