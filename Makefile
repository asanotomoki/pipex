NAME	=	pipex
LIBFT = ./libft
COMPILER  = cc
CFLAGS    = -Wall -Wextra -Werror
INCLUDE   = -I ./include
SRCDIR    = ./src
AR = ar
ARFLAFS = -rcs
RM = rm -f
SOURCES	=	main.c \
			pipex.c

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

.PHONY: all bonus fclean clean re
