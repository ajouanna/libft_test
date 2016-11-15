NAME = test
SRC = ./srcs
INC = ./includes
LIBFT_PATH = ../libft
LIBFT_INC = $(LIBFT_PATH)
OBJ = .

LIST_SRC = $(SRC)/*.c

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJS)%.o)

all : $(NAME)

$(NAME) : $(LIST_SRC) $(LIBFT_PATH)/libft.a
	gcc -Wall -Wextra -Werror -I $(INC) -I $(LIBFT_INC)\
	   	$(LIST_SRC) -o $(NAME) -L$(LIBFT_PATH) -lft 

clean :
	/bin/rm -f $(LIST_OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
