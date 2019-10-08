# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/26 17:27:09 by vasalome     #+#   ##    ##    #+#        #
#    Updated: 2019/09/26 12:05:02 by vasalome    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

##						##
##	|	VARIABLES	|	##
##						##

#	Output:
NAME		=	wolf3d

#	Compiler:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MEMFLAGS	=	-ggdb -fsanitize=address

#	Directory:
SRCS_DIR	=	./srcs_wolf/
OBJ_DIR		=	./objs_wolf/
INC_DIR		=	./includes_wolf/

#	Sources:
SRCS		=	main_wolf.c
SRCS		+=	ft_init.c
SRCS		+=	ft_init_hub.c
SRCS		+=	ft_init_weapon.c
SRCS		+=	ft_init_texture.c
SRCS		+=	ft_fill_map.c
SRCS		+=	ft_map.c
SRCS		+=	ft_keys.c
SRCS		+=	ft_move.c
SRCS		+=	ft_teleport.c
SRCS		+=	ft_ray.c
SRCS		+=	ft_wall.c
SRCS		+=	ft_draw_wall.c
SRCS		+=	ft_spawn.c
SRCS		+=	ft_textures.c
SRCS		+=	ft_gameover.c
SRCS		+=	ft_usage.c

#	Objects:
OBJ			=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

#	Includes:
INC			=	$(addprefix -I,$(INC_DIR))

#	Library:
LIBFT		=	libft/libft.a

#	Cleaning:
RM			=	/bin/rm -f
RM_DIR		=	/bin/rm -rf

#	Colors:
_GREEN		=	\033[38;5;46m
_VIOLET		=	\033[38;5;141m
_RED		=	\033[38;5;1m
_CYAN		=	\033[38;5;45m
_ORANGE		=	\033[38;5;214m
_YELLOW		=	\033[38;5;220m
_PINK		=	\033[38;5;197m
_STOP		=	\033[0m

#	Fonts:
END			=	\033[0m
BOLD		=	\033[1m
R_BOLD		=	\033[21m
BLINK		=	\033[5m
R_BLINK		=	\033[25m
UNDERLINE	=	\033[4m
R_UNDERLINE	=	\033[24m


##					##
##	|	RULES	|	##
##					##

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c $(INC_DIR)*.h
	@printf "$(_ORANGE)[CC] $(<:.c=)...$(_STOP)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "\r                                             \r"

all:
	@echo "$(_ORANGE)$(UNDERLINE)WOLF3D:$(R_UNDERLINE)$(_STOP)		$(BOLD)COMPILATION OBJECTS: IN PROGRESS..$(_STOP)\n		OBJECTS DIRECTORY: CREATION || ->\n"
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME) --no-print-directory

make_libft:
	@make -C libft/

make_mlx:
	@echo "$(_ORANGE)$(UNDERLINE)MLX:$(R_UNDERLINE)$(_STOP)		$(BOLD)LIB IN PROGRESS..$(_STOP)\n"
	@make -C minilibx_macos/
	@echo "\n"

$(NAME): $(OBJ) $(INC_DIR) make_libft make_mlx
	@echo "$(_ORANGE)$(UNDERLINE)WOLF3D:$(R_UNDERLINE)$(_STOP)		$(BOLD)COMPILATION $(NAME): IN PROGRESS..$(_STOP)\n"
	@$(CC) $(CFLAGS) $(OBJ) -I ./minilibx_macos/mlx.h ./minilibx_macos/libmlx.a ./libft/libft.a -framework OpenGL -framework AppKit -I ./libft/includes $(INC) -o $(NAME)
	@echo "$(_ORANGE)| ->		$(NAME):" "$(_STOP)|\033[42m     $(BOLD)L O A D I N G$(R_BOLD)     $(_STOP)|" #| pv -qL 15
	@echo "		$(_ORANGE)$(BLINK)100%\n$(R_BLINK)$(_STOP)"
#	@sleep 1.5
#	@clear
	@echo "\n$(_ORANGE)	   _____________________________"
	@echo "	|>				 <|"
	@echo "	|>	   ┬ ┬┌─┐┬  ┌─┐		 <|"
	@echo "	|>	   ││││ ││  ├┤ 		 <|"
	@echo "	|>	   └┴┘└─┘┴─┘└  _3D	 <|"
	@echo "	|>				 <|"
	@echo "	   __________________$(_STOP)$(BLINK)$(_YELLOW)is ready$(R_BLINK)$(_ORANGE)____$(_STOP)\n"

clean:
	@echo "$(_ORANGE)$(UNDERLINE)WOLF3D:$(R_UNDERLINE)$(_STOP)		$(BOLD)CLEAN: IN PROGRESS..$(_STOP)\n		DELETING OBJECTS || ->\n"
	@$(RM_DIR) $(OBJ_DIR)
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C minilibx_macos/
	@echo "$(_ORANGE)| ->		CLEAN: DONE\n$(_STOP)"

fclean: clean
	@echo "$(_ORANGE)$(UNDERLINE)WOLF3D:$(R_UNDERLINE)$(_STOP)		$(BOLD)FCLEAN: IN PROGRESS..$(_STOP)\n		DELETING EXEC || ->\n"
	@$(RM_DIR) $(NAME) a.out wolf3d.dSYM a.out.dSYM
	@$(MAKE) fclean -C libft/
	@echo "$(_ORANGE)| ->		FCLEAN: DONE\n$(_STOP)"

fclean_wolf: clean
	@echo "$(_RED)$(UNDERLINE)WOLF3D:$(R_UNDERLINE)$(_STOP)		$(BOLD)FCLEAN: IN PROGRESS..$(_STOP)\n		DELETING EXEC || ->\n"
	@$(RM_DIR) $(NAME) a.out wolf3d.dSYM a.out.dSYM
	@echo "$(_RED)| ->		FCLEAN: DONE\n$(_STOP)"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

bin: re clean


.SILENT: make_mlx
#.PRECIOUS:
.PHONY: all clean fclean re bin make_libft