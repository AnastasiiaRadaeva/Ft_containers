# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 15:22:50 by kbatwoma          #+#    #+#              #
#    Updated: 2021/04/29 16:43:53 by kbatwoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	ft_containers
CC 			= 	clang++
FLAGS 		= 	-Wall -Wextra -Werror
HEADER_DIR  =	containers/
SRCS_DIR    = 	tests/
SRCS_LIST   =	main_list.cpp
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS		= $(patsubst %.cpp, %.o, $(SRCS))
D_FILES		= $(patsubst %.cpp, %.d, $(SRCS))

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
%.o : %.cpp
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@ -MD -g
include $(wildcard $(D_FILES))

#list:

#vector:

#map:

#stack:

#queue:

clean:
	rm -rf $(OBJS) $(D_FILES);
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re