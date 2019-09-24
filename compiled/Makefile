SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
EXE_DIR = exe/
ASM_DIR = asm/

CXX = nvcc
# CXXFLAGS := -Wall -Werror -O3 -std=gnu11 # -g
CXXLINK=


FC = ifort
# FFLAGS = -Wall -Werror -O3 -Mcuda
FLINK = 


# ----------------------------------------------------------------



.SECONDARY: %.o 

SRCS = $(wildcard $(SRC_DIR)* ) 
PREFIXES = $(notdir $(SRCS) )

EXES := $(addsuffix .exe, $(addprefix $(EXE_DIR), $(PREFIXES) ) ) 
# EXES = $(addsuffix .exe, EXES )



# EXES = $(addprefix $(EXE_DIR), tests.exe )
# EXES += $(addsuffix .exe, $(addprefix exe/ )


# INC_FILES := $(wildcard $(INC_DIR)*.h)


# print stuff 
# $(info $(notdir $(wildcard $(SRC_DIR)*.c) ) )
# $(info $(ALL_OBJS) )



# # source: https://stackoverflow.com/questions/714100/os-detecting-makefile
# # for some reason i get errors when explicitly linking pthread on my personal machine (mac)
# UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S),Linux)
# 	CFLAGS += -pthread
# 	CLINK += -lpthread -lm
# endif



# objects that everyone needs 
# SHARED_OBJECTS = $(addprefix $(OBJ_DIR), lamport_queue.o fingerprint.o crc32.o \
# packetsource.o stopwatch.o generators.o checksum.o benchmark.o counter.o locks.o \
# utils.o )


.PHONY: all
all : $(EXES) 


$(EXE_DIR)%.f03.exe : $(SRC_DIR)%.f03  Makefile
	$(FC) $(FFLAGS) $< -o $@ $(FLINK)


$(EXE_DIR)%.cpp.exe : $(SRC_DIR)%.cpp  Makefile
	$(CXX) $(CXXFLAGS) $< -o $@ $(CXXLINK)



.PHONY: clean
clean :
	rm -f $(OBJ_DIR)*
	rm -f $(EXE_DIR)*

