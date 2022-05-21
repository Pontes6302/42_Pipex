SRCS = ${wildcard *.c}
TEXT = /MakeArt/${wildcard *.txt}
FLAGS = -Wall -Werror -Wextra
INCS = pipex.h
NAME = pipex

${NAME}: ${SRCS}
	@clear
	@cat MakeArt/compiling.txt
	@sleep 1
	@gcc ${SRCS} libftprintf.a $(FLAGS) -I ${INCS} -o ${NAME}
	@clear
	@cat MakeArt/compiled.txt
	@sleep 0.5
	@clear

all: ${NAME}

clean:
	@clear
	@cat MakeArt/cleaning.txt
	@rm -rf ${NAME}
	@sleep 1
	@clear
	@cat MakeArt/cleaned.txt
	@sleep 0.5
	@clear

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re .c.o