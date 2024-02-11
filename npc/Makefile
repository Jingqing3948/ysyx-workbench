TOPNAME = top
NXDC_SOURCES=constr/top.nxdc
INC_PATH = /usr/include/SDL2
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                -O3 --x-assign fast --x-initial fast --noassert --trace

BUILD_DIR = $(abspath ./build)
OBJ_DIR = $(abspath ./build/obj_dir)

$(shell mkdir -p $(BUILD_DIR))

CSOURCES=$(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
VSOURCES=$(shell find $(abspath ./vsrc) -name "*.v")
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
CSOURCES += $(SRC_AUTO_BIND)

include $(NVBOARD_HOME)/scripts/nvboard.mk

INCFLAGS = $(addprefix -I, $(INC_PATH))



CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

# 定义链接库
LDFLAGS = -lSDL2 -lSDL2_image


$(SRC_AUTO_BIND):$(NXDC_SOURCES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@


all:
	@echo "Write this Makefile by your self."

sim:$(VSOURCES) $(CSOURCES) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "-- Verilator npc"
	@echo "-- VERILATE & BUILD --------"
	
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
	--top-module $(TOPNAME) $^ \
	$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
	--Mdir $(OBJ_DIR) --exe -o $(OBJ_DIR)/$(TOPNAME)

	@echo "-- RUN ---------------------"
	$(OBJ_DIR)/top
	@echo "-- DONE --------------------"
	@echo "Note: Once this example is understood, see examples/make_tracing_c."

include ../Makefile

clean:
	rm -rf $(OBJ_DIR)
