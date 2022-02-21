# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 11:38:11 by anifanto          #+#    #+#              #
#    Updated: 2022/02/21 16:37:55 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Library/libft.a
BONUS = Library/libftbonus.a

ifndef VERBOSE
.SILENT:
endif

LIST =	ft_atoi.c ft_bzero.c ft_calloc.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_memchr.c\
		ft_memcmp.c	ft_memcpy.c	ft_memmove.c\
		ft_memset.c	ft_strchr.c\
		ft_strdup.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strncmp.c ft_strnstr.c\
		ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_split.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c	
		
LIST_BONUS =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c		

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ_DIR = Objects
OBJB_DIR = Objects_B
HEADER = include/libft.h
SRC = src
OPTION = -c -I $(HEADER)
STAND_M = $(LIST:.c=.o)
STAND_B = $(LIST_BONUS:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(STAND_M))
OBJ_BONUS = $(addprefix $(OBJB_DIR)/, $(STAND_B))
FT_PRINTF = ft_printf
GNL = get_next_line
GNLB = get_next_line_bonus

$(OBJ_DIR)/%.o : src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(OPTION) -c $< -o $@

$(OBJB_DIR)/%.o : src/%.c
	mkdir -p $(OBJB_DIR)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME) $(BONUS) libftprintf.a gnl_m.a gnl_b.a
	@tput setaf 3; echo "libft->"
	@tput setaf 5; echo "\n--- Nothing Left To Do ---\n"

$(NAME) : $(OBJ) $(HEADER) $(SRC)
	@tput setaf 3; echo "\nBuilding->"
	@mkdir -p Library
	@ar -rc $(NAME) $(OBJ) 
	@tput setaf 2; echo "libft.a->       [ok] [ok]"

$(BONUS) : $(OBJ_BONUS) $(HEADER)
	@tput setaf 3; echo "\nBuilding->"
	@mkdir -p Library
	@ar -rc $(BONUS) $(OBJ_BONUS)
	@tput setaf 2; echo "libftbonus.a->  [ok] [ok]"

libftprintf.a:
	@mkdir -p Library
	@make -C $(FT_PRINTF)

gnl_m.a:
	@mkdir -p Library
	@make -C $(GNL)

gnl_b.a:
	@mkdir -p Library
	@make -C $(GNLB)

clean:
	@tput setaf 3; echo "\nCleaning->"
	@rm -r -f $(OBJ) $(OBJ_BONUS) $(OBJ_DIR) $(OBJB_DIR)
	@make clean -C $(FT_PRINTF)
	@make clean -C $(GNL)
	@make clean -C $(GNLB)
	@tput setaf 1; echo "Objects->" | tr -d '\n'
	@tput setaf 2; echo "       [ok] [ok]"

fclean: clean
	@tput setaf 3; echo "\nCleaning->"
	@rm -r -f $(NAME) $(BONUS) Library
	@tput setaf 1; echo "Libraries->" | tr -d '\n'
	@tput setaf 2; echo "     [ok] [ok]"

re : fclean all
	@tput setaf 3; echo "\nRecreated->"
	@tput setaf 2; echo "All->           [ok] [ok]"

.PHONY : all clean fclean re
