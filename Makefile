#===================================================#
#			      BEGIN USER EDITABLES				#
#===================================================#
# Compiler
CC		=	g++

# Binary target
TARGET	=	MyCraft

# Directories and extensions
SRCDIR	=	src
INCDIR	=	inc
OBJDIR	=	obj
BINDIR	=	bin

SRCEXT	=	cpp
INCEXT	=	hpp
OBJEXT	=	o

# Flags, Libraries, and Header Include Directories
CFLAGS	=	-Wall -g
LIBS	=	-lGL -lGLU -lGLEW -lglfw
INC		=	$(INCSYS) $(INCUSR)
INCSYS	=	-I /usr/local/include
INCUSR	=	-I $(INCDIR)

#===================================================#
#				 END USER EDITABLES					#
#===================================================#

SOURCES	=	$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS	=	$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

all: directories $(TARGET)

remake:	clean all

directories:
	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)

run: all
	@./bin/$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(BINDIR)/$@ $^ $(LIBS)

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<


.PHONY: clean directories run
