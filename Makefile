CC=gcc
CFLAGS= -Wall -Wextra -pedantic -std=c99
OUTPUT_DIR=output
TARGET=$(OUTPUT_DIR)/my_text_editor
SRCS=main.c
OBJS=$(SRCS:%.c=$(OUTPUT_DIR)/%.o)
INCLUDES=
all: $(OUTPUT_DIR) $(TARGET)

$(OUTPUT_DIR):
	@mkdir -p $@
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
$(OUTPUT_DIR)/%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning build files..."
	@if [ -d "$(OUTPUT_DIR)" ]; then \
		rm -f $(OUTPUT_DIR)/*; \
		rmdir $(OUTPUT_DIR); \
		echo "Clean completed."; \
	else \
		echo "Nothing to clean."; \
	fi

.PHONY: all clean