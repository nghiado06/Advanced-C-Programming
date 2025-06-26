# Tên của chương trình
TARGET = main
# Thư mục chứa header và source files
HEADER_DIR = Header
SOURCE_DIR = Source
BUILD_DIR = Build
# Các tệp nguồn và tệp object tương ứng
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
# Trình biên dịch và các cờ
CC = gcc
CFLAGS = -I$(HEADER_DIR) -Wall -Wextra
# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(BUILD_DIR)/$(TARGET)
# Quy tắc để tạo ra tệp thực thi
$(BUILD_DIR)/$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) -o $@ $^
# Quy tắc để biên dịch các tệp .cpp thành .o
$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#Tự động tạo thư mục build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Quy tắc để làm sạch thư mục build
clean:
	rm -f $(SOURCE_DIR)/*.o $(TARGET) $(BUILD_DIR)/$(TARGET)
# Quy tắc giả (phony target)
.PHONY: all clean

