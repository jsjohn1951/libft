# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:57:08 by wismith           #+#    #+#              #
#    Updated: 2022/02/21 17:48:29 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../Library/gnl_m.a

ifndef VERBOSE
.SILENT:
endif

LIST = get_next_line.c get_next_line_utils.c

HEADER = ../include/get_next_line.h
OBJDIR = Objects
OBJ = $(addprefix $(OBJDIR)/, $(LIST:.c=.o))
OPTION = -c -I $(HEADER)
FLAGS = -Wall -Werror -Wextra
CC = gcc

$(OBJDIR)/%.o : %.c
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(OPTION) -c $< -o $@

all : $(NAME)
	@tput setaf 5; echo "\n--- 'gnl' Nothing Left To Do ---\n"

$(NAME) : $(OBJ) $(HEADER)
	@tput setaf 3; echo "\nget_next_line-->"
	@tput setaf 3; echo "Building--->"
	@mkdir -p ../Library
	@ar -rc $(NAME) $(OBJ)
	@tput setaf 2; echo "gnl_m.a-> [ok] [ok]"

clean :
	@rm -f -r $(OBJ) $(OBJDIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re