OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

#the default goal is the one that is sxecuted when u run make without args.
.DEFAULT_GOAL := main.exe


#In a rule, the thing left tot he colon is the thing you wanna "make"
# the things at the right side of the colon are the requisites
# in the lines below the rule, u have what u gonna do to make the thing
main.exe : courses.o commands.o course.o users.o user.o sessions.o session.o problems.o problem.o main.o
	g++ -o main.exe $(OPCIONS) main.o courses.o course.o users.o user.o sessions.o session.o problems.o problem.o commands.o 

# This rule says: "for any x.o file you need the x.cc file
# $< means "the thing in the right side of the rule" i. e. the source file
# in this case (right to the colon)
%.o : %.cc
	g++ -c $(OPCIONS) $<

# This rule says the same with cpp, make will look for the first one that matches
%.o : %.cpp
	g++ -c $(OPCIONS) $< 

# Phony mean "fake" and allows us to put false targets and use them for special
# things, in this case, make (or make all) woud only make the main program.
.PHONY : all
all : main.exe

# The same with clean, but we'll delete the files.
.PHONY : clean
clean :
	rm *.o *.exe

