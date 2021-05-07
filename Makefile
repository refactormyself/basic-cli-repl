
# the compiler:
CC = g++

# compiler flags:
CFLAGS  = -g -std=gnu++11 -Wall

# the build target executable:
TARGET = basic_gtests

# include directorories each of the for -Imy_dir
INCLUDES = -I./include

# source files (all .cpp files in ./src)
SRCS = $(wildcard ./src/*.cpp)

# setup object files to be created for all .cpp files found
OBJS = $(SRCS:.cpp=.o)

# path to location of libraries which are not already inside /usr/lib (-Lmy_libs_path)
LFLAGS = 

# list the libraries that will be linked into the executables (-lmy_lib1)
LIBS = 

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
# adopted from:
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
#

.PHONY: depend clean

all:    $(TARGET)
		@echo  Just compiled - Basic gtests

$(TARGET): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables
#	- $<: the name of the prerequisite of  the rule(a .cpp file) 
#	- $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(TARGET)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
