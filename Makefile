gcc:
	gcc -o reversi main.c estado.c stack.c bot.c
clean:
	rm reversi
