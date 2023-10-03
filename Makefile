# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:12:03 by mpuig-ma          #+#    #+#              #
#    Updated: 2023/10/03 10:11:40 by mpuig-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3D

SRC_DIR		:=	src
INC_DIR		:=	$(SRC_DIR)
BUILD_DIR	:=	build

AR			:=	ar
CC			:=	gcc
LD			:=	ld
LDFLAGS		:=	-L$(SRC_DIR)/libft -lft
LDFLAGS		+=	-L$(SRC_DIR)/libmlx -lmlx

CFLAGS		:=	-Wall -Werror -Wextra
CPPFLAGS	:=	-MMD -I$(INC_DIR) -I$(SRC_DIR)/libmlx
DFLAGS		:=	-g -fsanitize='address,undefined'

SRC_FILES	:=	$(SRC_DIR)/main.c
INC_FILES	:=	$(INC_DIR)/cub3D.h

OBJ_FILES	=	$(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP_FILES	=	$(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.d)

LIBFT_DIR	:=	$(SRC_DIR)/libft
LIBMLX_DIR	:=	$(SRC_DIR)/libmlx
LIBFT		:=	$(LIBFT_DIR)/libft.a
LIBMLX		:=	$(LIBMLX_DIR)/libmlx.a

.PHONY: all debug clean fclean re

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ_FILES) $(INC_FILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ_FILES) -o $(basename $@) # use ld instead??

debug:: CFLAGS += $(DFLAGS)
debug:: $(NAME)

$(LIBFT) $(LIBMLX):: CFLAGS =
$(LIBFT) $(LIBMLX)::
	make -C $(dir $@)

clean:
	rm -rf $(BUILD_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

-include $(DEP_FILES)
