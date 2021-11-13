SRC		=	./src/*.c
HEADER	=	./src/fractol.h
PROG	=	fractol
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3 -fsanitize=address -g
LIBDIR	=	./libft
LIB		=	$(LIBDIR)/libft.a

all		:	$(PROG)

$(LIB)	:
			make -s -C $(LIBDIR)

$(PROG)	:	$(SRC) $(LIB) $(HEADER)
			$(CC) $(CFLAGS) $(SRC) -L ./libft/ -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(PROG)

clean	:
			make clean -C $(LIBDIR)

fclean	:
			rm -f $(PROG)
			make fclean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all re clean fclean