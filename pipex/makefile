# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:20:42 by lsaumon           #+#    #+#              #
#    Updated: 2024/05/14 15:01:48 by lsaumon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	pipex

# =================================== SOURCES ==================================

SRCS 		:=	srcs/main.c \
				srcs/utils.c \
				srcs/utils_2.c \
				srcs/utils_3.c \
				srcs/forking.c
			
OBJ_DIR		:= .objs
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================== FLAGS ====================================

CC =	cc
FLAGS =	-Wall -Wextra -Werror
RM =	rm -rf

$(OBJ_DIR)/%.o :%.c
	@mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

# =================================== COLORS ===================================

CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

# =================================== COMPILATION ==============================

all:	${NAME}

$(NAME):	$(OBJS) 
	@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@ echo "$(YELLOW)$(NAME) $(GREEN)created $(CLR_RMV)✔️"

# =================================== RULES ====================================

clean:

	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean

	@ $(RM) $(NAME) $(RM)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all bonus clean fclean re