TARGET = main
BUILD_DIR = Build
HEADER_DIR = Header
SOURCE_DIR = Source

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra

EXEC = $(BUILD_DIR)/$(TARGET)

all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SOURCE_DIR)/*.o
	rm -rf $(BUILD_DIR)

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run
