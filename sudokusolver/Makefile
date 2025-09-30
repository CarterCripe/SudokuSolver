CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -Wpedantic

TARGET := app
SRC := main.cpp

.PHONY: all run clean

all: run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	printf '%s\n' \
		000034091 \
		400170000 \
		006000700 \
		100003000 \
		905000120 \
		004500067 \
		620009000 \
		540210986 \
		870356410 | ./$(TARGET)

clean:
	rm -f $(TARGET)
