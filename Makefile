NAME			=	rush01
INCLUDES		=	include/
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
FILES			=	main init utils solution con_check fulfill_con pre_set_nb print_grid
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
GCC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
FSAN			=	-fsanitize=address -g3
RM				=	rm -rf

all:
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) $(FSAN) -I $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(GCC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all