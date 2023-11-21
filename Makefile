# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:12:03 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/11/21 22:21:04 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

SRC_DIR		:=	src
INC_DIR		:=	include
BUILD_DIR	:=	build

LIBFT_DIR	:=	$(SRC_DIR)/libft
LIBMLX_DIR	:=	$(SRC_DIR)/libmlx
LIBFT		:=	$(LIBFT_DIR)/libft.a
LIBMLX		:=	$(LIBMLX_DIR)/libmlx.a

AR			:=	/usr/bin/ar
CC			:=	/usr/bin/gcc
#LD			:=	ld
LDFLAGS		:=	-L$(LIBFT_DIR) -lft
LDFLAGS		+=	-framework OpenGL -framework AppKit -L$(LIBMLX_DIR) -lmlx
#LDFLAGS	+=	-lm

CFLAGS		:=	-Wall -Werror -Wextra -O3
CPPFLAGS	:=	-MMD -iquote$(INC_DIR)
CPPFLAGS	+=	-I$(LIBFT_DIR)/src -I$(LIBMLX_DIR)
DFLAGS		:=	-g -fsanitize='address,undefined'

SRC_FILES	:=	\
				$(SRC_DIR)/background.c \
				$(SRC_DIR)/check_player.c \
				$(SRC_DIR)/clean.c \
				$(SRC_DIR)/destroy.c \
				$(SRC_DIR)/dump_info.c \
				$(SRC_DIR)/dump_map.c \
				$(SRC_DIR)/keycode.c \
				$(SRC_DIR)/mouse.c \
				$(SRC_DIR)/parse_map.c \
				$(SRC_DIR)/raycast.c \
				$(SRC_DIR)/read_file.c \
				$(SRC_DIR)/render.c \
				$(SRC_DIR)/start.c \
				$(SRC_DIR)/textures.c \
				$(SRC_DIR)/utils_arr.c \
				$(SRC_DIR)/utils_color.c \
				$(SRC_DIR)/utils_draw.c \
				$(SRC_DIR)/utils_draw_quadrangle.c \
				$(SRC_DIR)/utils_lst.c \
				$(SRC_DIR)/utils_str.c \
				$(SRC_DIR)/validate_map.c \
				$(SRC_DIR)/validate_map_walls.c \
				$(SRC_DIR)/validate_info.c \
				$(SRC_DIR)/window.c
OBJ_FILES	=	$(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_FILES	=	$(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.d)

.PHONY: all debug clean fclean re

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJ_FILES) -o $(basename $@)

debug:: CFLAGS += $(DFLAGS)
debug:: $(NAME)

$(LIBFT) $(LIBMLX):: CFLAGS =
$(LIBFT) $(LIBMLX)::
	make -C $(dir $@)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(BUILD_DIR)
	@echo "$(BUILD_DIR) deleted"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(LIBMLX_DIR)
	rm -f $(NAME)

re: fclean
	@$(MAKE) --no-print-directory

-include $(DEP_FILES)
