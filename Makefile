uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

#Linux (default)
EXE = hw2
LDFLAGS = -lGL -lGLU -lglut
	
#OS X
ifeq ($(uname_S), Darwin)
	LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT
endif

$(EXE) : hw2.c
	 gcc -Wall -o $@ $< $(CFLAGS) $(LDFLAGS) 
