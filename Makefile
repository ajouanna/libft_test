NAME = test
SRC = ./srcs
INC = ./includes
LIBFT_PATH = ../libft
LIBFT_INC = $(LIBFT_PATH)/includes
OBJ = .

LIST_SRC = $(SRC)/*.c

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJS)%.o)

all : $(NAME)

$(NAME) : $(LIST_SRC) $(LIBFT_PATH)/libft.a
	gcc -Wall -Wextra -Werror -L$(LIBFT_PATH) -lft -I $(INC) -I $(LIBFT_INC)\
	   	$(LIST_SRC) -o $(NAME)

clean :
	/bin/rm -f $(LIST_OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
