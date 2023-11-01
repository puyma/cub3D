# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:12:03 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/11/01 17:29:55 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	demo

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

CFLAGS		:=	-Wall -Werror -Wextra
CPPFLAGS	:=	-MMD -iquote$(INC_DIR)
CPPFLAGS	+=	-I$(LIBFT_DIR)/src -I$(LIBMLX_DIR)
DFLAGS		:=	-g -fsanitize='address,undefined'

SRC_FILES	:=	\
				$(SRC_DIR)/background.c \
				$(SRC_DIR)/clean.c \
				$(SRC_DIR)/destroy.c \
				$(SRC_DIR)/ft_check_map.c \
				$(SRC_DIR)/ft_load_textures.c \
				$(SRC_DIR)/ft_set_board.c \
				$(SRC_DIR)/ft_set_info.c \
				$(SRC_DIR)/handheld.c \
				$(SRC_DIR)/keycode.c \
				$(SRC_DIR)/map.c \
				$(SRC_DIR)/map_segments.c \
				$(SRC_DIR)/minimap.c \
				$(SRC_DIR)/mouse.c \
				$(SRC_DIR)/raycast.c \
				$(SRC_DIR)/read_file.c \
				$(SRC_DIR)/render.c \
				$(SRC_DIR)/start.c \
				$(SRC_DIR)/utils_arr.c \
				$(SRC_DIR)/utils_color.c \
				$(SRC_DIR)/utils_draw.c \
				$(SRC_DIR)/utils_lst.c \
				$(SRC_DIR)/utils_math.c \
				$(SRC_DIR)/utils_str.c

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
	rm -rf $(BUILD_DIR)
	#make fclean -C $(LIBFT_DIR)
	#make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

-include $(DEP_FILES)
