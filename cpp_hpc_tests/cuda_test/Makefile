


SRCS=$(wildcard *.cpp)

PREFIXES=$(SRCS:.cpp=)

# EXES = $(SRCS:.cpp=.exe)

# all : *.c

# all : $(EXES) 

all : $(PREFIXES)

# if $(findstring midway, $(shell hostname) )
# 	CXX_OPTS = -I "
# endif 

CXX_OPTS = -I ../../include/

% : %.cpp Makefile
#	mpicxx -o normal/$@
	mkdir -p $@
	g++ -O3 $(CXX_OPTS) -o $@/$@.exe $<
	nvcc -O3 $(CXX_OPTS) -x cu -DUSE_CUDA -o $@/$@_+cuda.exe $<


# .PHONY: clean 
# clean:
# 	for i in $(SRCS)

# % : %.cpp

# 	# @for use_cuda in 0 1; do \
# 	# 	@echo $$use_cuda ; \
# 	# @done

# 	prefix:=$(addsuffix +cuda, $@)

# 	$(info "$@" is $@ )
# 	$(info prefix is $(prefix) )
# 	$(info 2 )

# 	prefix += "_+cuda"

# 	echo $(prefix)

# mpicxx -o $@ $<
