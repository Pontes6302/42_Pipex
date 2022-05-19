SRCS = ${wildcard *.c}
TEXT = /text_art/${wildcard *.txt}
OBJS = ${SRCS:.c=.o}
FLAGS = 
INCS = pipex.h
NAME = pipex

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all:
	@clear
	@cat MakeArt/compiling.txt
	${NAME}
	@clear
	@cat MakeArt/compiled.txt

# bonus: ${NAME} ${OBJS_B}
# 	ar rcs ${NAME} ${OBJS_B}

.c.o:
	@gcc $(FLAGS) -I ${INCS} -c $< -o ${<:c=o}

clean:
	@clear
	@cat MakeArt/cleaning.txt
	@rm -rf ${OBJS} ${OBJS_B}
	@clear
	@cat MakeArt/cleaned.txt

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re .c.o