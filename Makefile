NAME	=	pipex
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
COMPILER  = cc
CFLAGS    = #-Wall -Wextra -Werror
INCLUDES   = ./includes
MANDATORY_DIR    = ./mandatory
AR = ar
ARFLAFS = -rcs
RM = rm -f
SOURCES	=	main.c \
			pipex.c
OBJDIR    = ./obj
OBJECTS   = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS   = $(OBJECTS:.o=.d)

${NAME}: ${INCLUDES} ${OBJECTS}
		make -C $(LIBFTDIR)
		$(CC) ${CFLAGS} -fsanitize=address -g ${LIBFT} ${OBJECTS} -o $@

$(OBJDIR)/%.o: $(MANDATORY_DIR)/%.c
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

test: $(NAME)
	  ./pipex infile "ls" "wc -l" outfile

.PHONY: all bonus fclean clean re test
