# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitawi <aitawi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/22 10:00:00 by aitawi           #+#    #+#               #
#    Updated: 2026/08/22 10:00:00 by aitawi          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
BONUS_NAME		= pipex_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDES		= -I include -I libft

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
MAKE_LIBFT		= $(MAKE) --no-print-directory -C $(LIBFT_DIR)

SRC_DIR			= src
BONUS_DIR		= src_bonus
OBJ_DIR			= obj
BONUS_OBJ_DIR	= obj_bonus

SRC				= pipex.c execute.c path.c errors.c
BONUS_SRC		= pipex_bonus.c setup_bonus.c heredoc_bonus.c \
				  execute_bonus.c path_bonus.c errors_bonus.c

OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ		= $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(NAME) is ready."

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) is ready."

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/pipex.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ): $(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c include/pipex_bonus.h | $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR) $(BONUS_OBJ_DIR):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE_LIBFT)

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE_LIBFT) clean
	@echo "object files removed."

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE_LIBFT) fclean
	@echo "$(NAME) and $(BONUS_NAME) removed."

re: fclean all

.PHONY: all bonus clean fclean re
