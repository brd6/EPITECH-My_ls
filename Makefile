##
## Makefile for my_printf in /home/bongol_b/rendu/my_printf
## 
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Sun Nov  1 21:13:19 2015 berdrigue bongolo-beto
## Last update Sun May 22 00:44:49 2016 Berdrigue BONGOLO BETO
##

CC	= 	gcc

RM	= 	rm -Rf

NAME	= 	my_ls

SRCS	= 	my_ls.c \
		utils.c \
		utils2.c \
		info_file.c \
		my_advanced_sort_wordtab.c \
		my_strcmp.c \
		display_manager.c \
		utils3.c \
		my_strcat.c \
		fileinfo_util.c \
		info_sort.c \
		fileinfo_util2.c \
		utils4.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	=	-I./include/

LDFLAGS	=	-L./lib -lmy -lmyprintf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean
