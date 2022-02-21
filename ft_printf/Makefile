# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 13:37:27 by wismith           #+#    #+#              #
#    Updated: 2022/02/21 17:48:41 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../Library/libftprintf.a
ifndef VERBOSE
.SILENT:
endif
LISTASSETS = ft_put_u.c\
			ft_put.c\
			ft_puthex.c\
			ft_putptr.c\
			ft_int_min.c\
			
LIST = ft_printf.c

HEADER = ../include/ft_printf.h
OBJ_LIST = $(LIST:.c=.o)
OBJ_LIST2 = $(LISTASSETS:.c=.o)
OBJ = $(addprefix $(OBJDIR)/, $(OBJ_LIST) $(OBJ_LIST2))
OPTION = -c -I $(HEADER)
FLAGS = -pthread -g -Wall -Werror -Wextra
OBJDIR = Objects

$(OBJDIR)/%.o : assets/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(OPTION) -c $< -o $@

all : $(NAME)
	@tput setaf 5; echo "\n--- 'ft_printf' Nothing Left To Do ---\n"
	
$(NAME) : $(OBJ) $(HEADER)
	@tput setaf 3; echo "\nft_printf-->"
	@tput setaf 3; echo "Building--->"
	@mkdir -p ../Library
	@ar -rc $(NAME) $(OBJ)
	@tput setaf 2; echo "libftprintf.a-> [ok] [ok]"
	@rm -f $(OBJ_LIST)
	
clean:
	@rm -f -r $(OBJDIR)
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@tput setaf 1; echo "\n\t--- Library Cleaned ---\n"
	
re : fclean all

.PHONY : all clean fclean re
