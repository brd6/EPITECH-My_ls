##
## Makefile for my_printf in /home/bongol_b/rendu/my_printf
## 
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Sun Nov  1 21:13:19 2015 berdrigue bongolo-beto
## Last update Sun Nov 29 19:32:01 2015 berdrigue bongolo-beto
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

LDFLAGS	+=	-L./lib -lmy

LDFLAGS	+= 	-W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS):
	@$(CC) -c $(SRCS) $(CFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, mrproper, re, all, fclean
