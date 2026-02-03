# Module 1 Project: Network Info Tool

CC = gcc
CFLAGS = -Wall -Wextra

TARGET = network_info_tool

all: $(TARGET)

$(TARGET): network_info_tool.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

help:
	@echo "Network Info Tool"
	@echo "================="
	@echo ""
	@echo "Build: make"
	@echo "Run:   make run"
	@echo "       ./network_info_tool"
	@echo ""
	@echo "Features:"
	@echo "  - Display local IP addresses"
	@echo "  - Show network interface info"
	@echo "  - Demonstrate byte order conversion"

.PHONY: all clean run help
