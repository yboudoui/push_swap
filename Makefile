# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 21:08:55 by yboudoui          #+#    #+#              #
#    Updated: 2022/08/31 16:07:08 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror -g3

RM					=	rm -f

# **************************************************************************** #

MEMORY_DIR			=	memory/

MEMORY_SRC			=	$(addprefix $(MEMORY_DIR),			\
						ft_memset.c							\
						ft_memcpy.c							\
						ft_memmove.c						\
						ft_memchr.c							\
						ft_memcmp.c							\
						ft_calloc.c							\
						)

MEMORY_INC			=	$(addprefix $(MEMORY_DIR),			\
						.									\
						)

# **************************************************************************** #

CHARSET_DIR			=	is_charset/

CHARSET_SRC			=	$(addprefix $(CHARSET_DIR),			\
						is_charset.c						\
						)

CHARSET_INC			=	$(addprefix $(CHARSET_DIR),			\
						.									\
						)

# **************************************************************************** #

UTILS_DIR			=	utils/

UTILS_SRC			=	$(addprefix $(UTILS_DIR),			\
						$(MEMORY_SRC)						\
						$(CHARSET_SRC)						\
						ft_atoi.c							\
						)

UTILS_INC			=	$(addprefix $(UTILS_DIR),			\
						$(MEMORY_INC)						\
						$(CHARSET_INC)						\
						.									\
						)

# **************************************************************************** #

PARSE_DIR			=	parse/

PARSE_SRC			=	$(addprefix $(PARSE_DIR),			\
						parse.c								\
						)

PARSE_INC			=	$(addprefix $(PARSE_DIR),			\
						.									\
						)

# **************************************************************************** #

MEDIAN_DIR			=	median/

MEDIAN_SRC			=	$(addprefix $(MEDIAN_DIR),			\
						median.c							\
						)

MEDIAN_INC			=	$(addprefix $(MEDIAN_DIR),			\
						.									\
						)

# **************************************************************************** #

INSTRUCTION_DIR		=	instruction/

INSTRUCTION_SRC		=	$(addprefix $(INSTRUCTION_DIR),		\
						base.c								\
						instruction.c						\
						push.c								\
						reverse_rotate.c					\
						rotate.c							\
						swap.c								\
						)

INSTRUCTION_INC		=	$(addprefix $(INSTRUCTION_DIR),		\
						.									\
						)

# **************************************************************************** #


STACKS_DIR			=	stacks/

STACKS_SRC			=	$(addprefix $(STACKS_DIR),			\
						$(UTILS_SRC)						\
						$(PARSE_SRC)						\
						$(MEDIAN_SRC)						\
						$(INSTRUCTION_SRC)					\
						stacks.c							\
						)

STACKS_INC			=	$(addprefix $(STACKS_DIR),			\
						$(UTILS_INC)						\
						$(PARSE_INC)						\
						$(MEDIAN_INC)						\
						$(INSTRUCTION_INC)					\
						.									\
						)

# **************************************************************************** #

SRCS				=	$(STACKS_SRC)				\
						print.c						\
						main.c						\

INCS				=	$(STACKS_INC)				\
						.							\

OBJS				=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS)	\
		$(addprefix -I , $(INCS))	\
		-c $<	\
		-o $(<:.c=.o)	\

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME)\
		$(OBJS)

all:		$(NAME)

valgrind_test:	all
		{ clear ; ARG=$$(shuf -i 0-500 -n 60) ; echo $$ARG ; valgrind ./push_swap $$ARG ; }

test:	all
		{ clear ; ARG=$$(shuf -i 0-9999 -n 500) ; ./push_swap $$ARG ; }

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
