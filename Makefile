TARGET   = proj
CC       = g++
CFLAGS   = -c -Wall -std=c++11

LINKER   = g++ -o
LFLAGS   = -std=c++11

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .

#RAWSRC	 = main.cpp Fuu.cpp Baa.cpp
#RAWINC	 = 
#SOURCES  := $(addprefix $(SRCDIR), $(RAWSRC))
#INCLUDES := $(addprefix $(SRCDIR), $(RAWINC))
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

run: all
	$(BINDIR)/$(TARGET)

all: makedir $(BINDIR)/$(TARGET)

makedir:
	mkdir -p $(BINDIR) $(OBJDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
