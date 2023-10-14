# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 13:09:48 by mryoo             #+#    #+#              #
#    Updated: 2023/10/08 19:22:49 by mryoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Weror

RM = rm -rf

NAME = server
NAME2 = client
NAME_BONUS = server_bonus
NAME_BONUS2 = client_bonus

SRCS = server.c
SRCS2 = client.c
SRCS_BONUS = server_bonus.c
SRCS_BONUS2 = client_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS2 = $(SRCS2:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
OBJS_BONUS2 = $(SRCS_BONUS2:%.c=%.o)

all: $(NAME) $(NAME2) bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAG) $(OBJS_BONUS) -o $(NAME_BONUS)

$(NAME_BONUS2): $(OBJS_BONUS2)
	$(CC) $(CFLAG) $(OBJS_BONUS2) -o $(NAME_BONUS2)

bonus: $(NAME_BONUS) $(NAME_BONUS2)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS2)
	$(RM) $(OBJS_BONUS)
	$(RM) $(OBJS_BONUS2)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	$(RM) $(NAME_BONUS)
	$(RM) $(NAME_BONUS2)

re: fclean all

.PHONY: all clean fclean re
