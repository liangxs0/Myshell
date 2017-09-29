objs=obj/doline.o obj/main.o obj/myvim.o
INC=-Iinclude
bin/main:$(objs)
	gcc $^ $(INC) -o $@
$(objs):obj/%.o:src/%.c
	gcc -c $^ $(INC) -o $@
