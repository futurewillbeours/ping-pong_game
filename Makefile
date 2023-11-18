all:
	gcc -Wall -Werror -Wextra pong.c -o game.out

rebuild:
	rm game.out
	gcc -Wall -Werror -Wextra pong.c -o game.out

clean:
	rm game.out