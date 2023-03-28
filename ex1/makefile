CC = gcc
OBJS = tool/main.o tool/AsciiArtTool.o RLEList.o
EXEC = AsciiArtTool
DEBUG_FLAG = # now empty, assign -g for debug
CFLAGS = -std=c99 -Wall -Werror -I/home/mtm/public/2122b/ex1 -Itool -pedantic-errors -DNDEBUG

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h
main.o : tool/main.c tool/AsciiArtTool.h
RLEList.o : RLEList.c

clean :
	rm -f $(OBJS) $(EXEC)