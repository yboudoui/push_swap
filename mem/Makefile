# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 13:44:44 by yboudoui          #+#    #+#              #
#    Updated: 2022/08/14 19:38:01 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmem.a

#-----------------------------------------------------------------------------#

DIR			=	./

HEADER		=	$(addprefix $(DIR),	\
					mem_size.h		\
					mem_utils.h		\
					mem.h			\
					mem_io.h		\
				)

SRC			=	$(addprefix $(DIR),	\
					mem_size.c		\
					mem_utils.c		\
					mem.c			\
					mem_io.c		\
				)

OBJS		=	$(SRC:.c=.o)

#-----------------------------------------------------------------------------#

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror -g3

RM					=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
