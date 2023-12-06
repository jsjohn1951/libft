NAME = libft.a

SRCS = ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_strchr \
	ft_strdup \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_tolower \
	ft_toupper \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_itoa \
	ft_strjoin_mod \
	ft_lstnew \
	ft_lstadd_front \
	ft_lstsize \
	ft_lstlast \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstmap \
	get_next_line \
	get_next_line_utils

TREESRCS = ft_tree \
	ft_init_node \
	ft_lexi_compare \
	ft_insert_node \
	ft_print_tree \
	ft_destroy_tree \
	ft_find_node \
	ft_height_node \
	ft_min_max \
	ft_balance_tree \
	ft_delete_node \
	ft_tree_iterator \
	ft_null_node

FTPRINTFSRCS = ft_printf \
	ft_put_u \
	ft_put \
	ft_puthex \
	ft_putptr \
	ft_int_min

SRCSDIR = srcs

BINARYTREESRCSDIR = binaryTree

FTPRINTFSRCSDIR = ft_printf

OBJDIR = objects

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

OBJMAN = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

TREEOBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(TREESRCS)))

FTPRINTFOBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FTPRINTFSRCS)))

$(OBJDIR)/%.o : $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(BINARYTREESRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(FTPRINTFSRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJMAN) $(TREEOBJ) $(FTPRINTFOBJ)
	ar -rc $(NAME) $(OBJMAN) $(TREEOBJ) $(FTPRINTFOBJ)

tree : $(TREEOBJ)
	ar -rc $(NAME) $(TREEOBJ)

ft_printf : $(FTPRINTFOBJ)
	ar -rc $(NAME) $(FTPRINTFOBJ)

clean :
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re