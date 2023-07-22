TARGET = bsq

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = ./src/atoi.c \
	 ./src/bsq_solver.c \
	 ./src/find_bsq.c \
	 ./src/fl_analyses.c \
	 ./src/ft_split.c \
	 ./src/main.c \
	 ./src/str_analyses.c \
	 ./src/utilities.c \
	 ./src/write.c \
	 ./src/inputs.c \
	 ./src/std_input.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)

%.o: %.c 
	$(CC) -c -o $@ $^ $(FLAGS) -I.

.PHONY: all

all : $(TARGET)

clean:
	rm -f ./src/*.o

fclean: clean
	rm -f bsq

re: fclean
	make