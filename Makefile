# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 22:47:45 by nhanafi           #+#    #+#              #
#    Updated: 2024/10/10 09:47:59 by nasreddineh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++17

SRC = main operand/Operand ofactory/operandfactory\
		vm/stack vm/command

INC = include

HEADER = include/common.hpp include/operand/Operand.hpp\
		 include/ofactory/operandfactory.hpp\
		 include/vm/stack.hpp include/vm/command.hpp

ODIR = obj

OBJ = $(addprefix $(ODIR)/, $(SRC:=.o))

NAME = VM

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(ODIR)/%.o: src/%.cpp $(HEADER)
	@echo src/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all