# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# SDL2 library
LIBS = -lSDL2

# Source files
SRCS = test.c assets/lib/init.c assets/lib/inputs.c assets/lib/constants.c assets/lib/lib.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = my_program

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean