# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 13:36:06 by aitawi           #+#    #+#               #
#    Updated: 2025/05/19 13:36:06 by aitawi          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memmove.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_calloc.c ft_memset.c ft_bzero.c ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strdup.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_atoi.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = ${SRCS:.c=.o}

BONUS = ft_lstdelone.c ft_lstmap.c ft_lstclear.c ft_lstiter.c ft_lstadd_front.c ft_lstadd_back.c ft_lstnew.c ft_lstlast.c ft_lstsize.c

BONUS_OBJ =	$(BONUS:.c=.o)

CC =	gcc

RM =	rm -f

CFLAGS =	-Wall -Wextra -Werror

NAME =	libft.a

${NAME}:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	${NAME}

bonus:	$(OBJS) $(BONUS_OBJ)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJ)

clean:
	   ${RM} ${OBJS} $(BONUS_OBJ)

fclean: clean
		${RM} ${NAME}

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus