NAME	=	libftprintf.a
LIBFT = ./libft
COMPILER  = cc
CFLAGS    = -Wall -Wextra -Werror
INCLUDE   = -I ./include
SRCDIR    = ./src
AR = ar
ARFLAFS = -rcs
RM = rm -f
SOURCES	=	

OBJDIR    = ./obj
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

$(NAME): $(OBJECTS) 
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(ARFLAFS) $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJECTS)
	rm -rf $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

test: all
	$(CC) $(CFLAGS) main.c $(NAME)  -fsanitize=address -g
	./a.out
	rm a.out

.PHONY: all bonus fclean clean re test
