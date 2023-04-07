# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sheali <sheali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 01:20:14 by sheali            #+#    #+#              #
#    Updated: 2023/04/04 14:29:11 by sheali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAINFILES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove \
ft_memset ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_split \
ft_strchr ft_strdup ft_strjoin ft_striteri ft_strlcpy ft_strlen ft_strlcat \
ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr \
ft_tolower ft_toupper \

BONUSFILES = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
ft_lstlast ft_lstnew ft_lstsize \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MAINFILES)))
BONUSSRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUSFILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAINFILES)))
BONUSOBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUSFILES)))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(BONUSOBJS)
	$(AR) $@ $^

all: $(NAME)

bonus: $(BONUSOBJS) $(NAME)
	$(AR) $(NAME) $(BONUSOBJS)

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
