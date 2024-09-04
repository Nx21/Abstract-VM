# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 22:47:45 by nhanafi           #+#    #+#              #
#    Updated: 2023/05/21 01:12:47 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++20
SRC = main 

INC = include

HEADER = 

ODIR = obj

OBJ = $(addprefix $(ODIR)/, $(SRC:=.o))

NAME = Server

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(OBJ)
	@echo $(ODIR)/%.o
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(ODIR)/%.o: src/%.cpp $(HEADER)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all