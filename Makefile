TARGET = app
CC = g++ 
CFLAGS = -g -Wall
SDL_CFLAGS = $(shell sdl-config --cflags)
SDL_LIBS = $(shell sdl-config --libs)
OBJS = CApp_OnEvent.o \
CSurface.o \
CApp_OnLoop.o \
CApp_OnRender.o \
CApp_OnCleanup.o \
CApp_OnInit.o \
CApp.o \
App.o

.PHONY: all $(TARGET) clean

all: $(TARGET)
	rm $(OBJS)

# Remember to put the linker directives after the object files. GCC is weird.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(OBJS) $(SDL_LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $<

clean:
	rm $(OBJS) $(TARGET)
