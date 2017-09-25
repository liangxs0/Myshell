objs=obj/myvim.o obj/main.o
INC=-Iinclude

bin/main:$(objs)
	gcc $^ $(INC) -o $@
$(objs):obj/%.o:src/%.c
	gcc -c $^ $(INC) -o $@
