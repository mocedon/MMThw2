CC = gcc
CCLINK = $(CC)
OBJS = user.o social_network.o main.o
EXEC = socialNet
CFLAG = -g -Wall
RM = rm -f

$(EXEC) : $(OBJS)
	$(CCLINK) -o $(EXEC) $(OBJS)

user.o : user.c user.h defs.h
social_network.o : social_network.c social_network.h user.h defs.h
main.o : main.c social_network.h user.h defs.h

clean:
	$(RM) $(EXEC) *.o