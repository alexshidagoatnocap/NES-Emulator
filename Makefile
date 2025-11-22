CPP = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -g
BUILDDIR = build
EXECDIR = exec
SRCDIR = src
INCDIR = inc
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TARGET = $(EXECDIR)/nes-emu

all: dirs $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# $(OBJECTS): $(SOURCES)
# 	$(CPP) $(CFLAGS) -c $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CFLAGS) -c $^ -o $@

dirs:
	mkdir -p $(BUILDDIR) $(EXECDIR)

clean:
	rm -rf $(BUILDDIR) $(EXECDIR)

.PHONY: all clean dirs
