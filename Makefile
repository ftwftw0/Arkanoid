#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 17:59:57 by flagoutt          #+#    #+#              #
#    Updated: 2015/05/02 10:22:11 by cdeniau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# **************************************************************************** #
# 		PROGRAM																   #
# **************************************************************************** #
NAME		=	atari

# **************************************************************************** #
#		SOURCES
# **************************************************************************** #

DIRSRC		=	srcs

SRCS =	$(DIRSRC)/main.c \
		$(DIRSRC)/lol.c

# **************************************************************************** #
#		DIRECTORIES
# **************************************************************************** #

DIRBIN		=	bin
BIN			=	$(addprefix $(DIRBIN)/, $(SRCS:.c=.o))
DIRLIST		=	srcs
DIRINC_GLFW	=	./GLFW/include/
DIRINC_FT	=	./libft/
DIRINC		=	./includes/

# **************************************************************************** #
#		COMPILE
# **************************************************************************** #

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCS		=	-I$(DIRINC) -I$(DIRINC_FT) -I$(DIRINC_GLFW)
LIBS		=   -Llibft/ -lft -Lglfw/src -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

# **************************************************************************** #
#		RULES																   #
# **************************************************************************** #

all: mkglfw libft $(NAME)

mkglfw:
	git submodule update --init
	## GIT POUR PULL LE SUBMODULE (git submodule init & git submodule update)
	##[ -f ./glfw/src/libglfw3.a ] && echo "Found glfw3 lib"	|| ~/.brew/bin/cmake glfw/ | make -C glfw/

libft:
	@$(MAKE) -C libft

$(NAME): $(DIRBIN) $(BIN)
	@printf " ------------------------------------------------------------ \n"
	@$(CC) $(CFLAG) $(BIN) $(LIBS) -o $(NAME)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(addprefix $(DIRBIN)/, %.o) : %.c $(DIRINC) $(DIRINC_FT)
	@mkdir -p $(@D)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(CFLAG) $(INCS) -o $@ -c $<
	@printf "\t\e[32m[DONE]\e[0m\n"

$(DIRBIN) :
	@/bin/mkdir $(DIRBIN); \
		for DIR in $(DIRLIST); \
		do \
		/bin/mkdir $(DIRBIN)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning binaries...\t\t\t\t\t"
	@/bin/rm -rf $(DIRBIN);
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning project...\t\t\t\t\t"
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[DONE]\e[0m\n"
	@printf " ------------------------------------------------------------ \n"

re: fclean all

.PHONY: clean fclean re libft
