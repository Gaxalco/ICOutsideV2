# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# SDL2 library
LIBS = -lSDL2

# Source files
SRCS = test.c assets/lib/init.c assets/lib/inputs.c assets/lib/constants.c assets/lib/tools.c assets/lib/debug.c assets/lib/update.c assets/lib/render.c assets/lib/physics.c assets/lib/getters.c assets/lib/draw.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = exe

# Default target
all: $(EXEC) post-build

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Post-build target to remove object files
post-build:
	rm -rf $(OBJS)

# Clean up object files and executable
clean:
	rm -rf $(OBJS) $(EXEC) *.o

# Phony targets
.PHONY: all clean post-build