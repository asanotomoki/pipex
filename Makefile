NAME	=	pipex
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
COMPILER  = cc
CFLAGS    = -Wall -Wextra -Werror
INCLUDES   = ./includes
SRCDIR    = ./srcs
AR = ar
ARFLAFS = -rcs
RM = rm -f
SOURCES	=	main.c 
OBJDIR    = ./obj
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

${NAME}: ${INCLUDES} ${OBJECTS}
		make -C $(LIBFTDIR)
		$(CC) ${CFLAGS} ${LIBFT} ${OBJECTS} -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)
	rm -rf $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all bonus fclean clean re
