# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasreddinehanafi <nasreddinehanafi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 22:47:45 by nhanafi           #+#    #+#              #
#    Updated: 2024/10/04 10:52:07 by nasreddineh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++17

SRC = main operand/Double operand/Float operand/Int16 operand/Int32 operand/Int8\
	ofactory/operandfactory

INC = include

HEADER = include/common.hpp include/operand/Double.hpp\
		include/operand/Float.hpp include/operand/IOperand.hpp\
		include/operand/Int16.hpp include/operand/Int32.hpp\
		include/operand/Int8.hpp include/ofactory/operandfactory.hpp include/operand/BaseType.hpp

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