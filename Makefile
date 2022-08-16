# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 13:44:44 by yboudoui          #+#    #+#              #
#    Updated: 2022/08/15 16:24:22 by yboudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

#-----------------------------------------------------------------------------#

UTILS_DIR			=	utils/

UTILS_FILES_HEADER	=	utils.h

UTILS_FILES_SRC		=	ft_t_str.c\
						ft_allocate.c\
						ft_is_in_set.c\
						ft_atoi_and_skip.c\
						ft_itoa_base.c

UTILS_HEADER		=	$(addprefix $(UTILS_DIR), $(UTILS_FILES_HEADER))

UTILS_SRC			=	$(addprefix $(UTILS_DIR), $(UTILS_FILES_SRC))

UTILS_OBJS			=	$(UTILS_SRC:.c=.o)

#-----------------------------------------------------------------------------#

FORMATER_DIR			=	formater/

FORMATER_FILES_HEADER	=	formater.h

FORMATER_FILES_SRC		=	ft_flags_handler.c\
							ft_parser.c\
							ft_type_scalar.c\
							ft_type_string.c

FORMATER_HEADER			=	$(addprefix $(FORMATER_DIR), $(FORMATER_FILES_HEADER))

FORMATER_SRC			=	$(addprefix $(FORMATER_DIR), $(FORMATER_FILES_SRC))

FORMATER_OBJS			=	$(FORMATER_SRC:.c=.o)

#-----------------------------------------------------------------------------#

DIR					=	./

FILES_HEADER		=	ft_printf.h

FILES_SRC			=	ft_printf.c\
						ft_tokeniser.c

SRC					=	$(addprefix $(DIR), $(FILES_SRC))

HEADER				=	$(addprefix $(DIR), $(FILES_HEADER))

OBJS				=	$(SRC:.c=.o)

#-----------------------------------------------------------------------------#

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror -g3

RM					=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(UTILS_OBJS) $(FORMATER_OBJS) $(OBJS)
				$(MAKE) bonus -C ./libft
				cp ./libft/libft.a .
				mv libft.a $(NAME)
				ar rcs $(NAME) $(UTILS_OBJS) $(FORMATER_OBJS) $(OBJS)

all:		$(NAME)

bonus:		all

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(UTILS_OBJS) $(FORMATER_OBJS) $(OBJS)

fclean:		clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
