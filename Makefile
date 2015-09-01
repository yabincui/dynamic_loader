all: dynamic_loader

CC := g++
CFLAGS := -std=c++11
LD := g++
LDFLAGS :=

SRCS := \
	elf_file_reader.cpp \
	logging.cpp \
	main.cpp \
	
HEADERS := $(wildcard *.h)
	
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

dynamic_loader: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^