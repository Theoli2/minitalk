NAME = libft.a

GNLPATH = ./GNL/
PRINTFPATH = ./printf/
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	$(GNLPATH)get_next_line_utils.c \
	$(GNLPATH)get_next_line.c \
	$(PRINTFPATH)ft_printadress.c \
	$(PRINTFPATH)ft_printchar.c \
	$(PRINTFPATH)ft_printdecimal.c \
	$(PRINTFPATH)ft_printhexa.c \
	$(PRINTFPATH)ft_printpercent.c \
	$(PRINTFPATH)ft_printstring.c \
	$(PRINTFPATH)ft_printunsigned.c \
	$(PRINTFPATH)ft_printf.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)

HEADER = libft.h

all: $(NAME)

bonus: $(NAMEBONUS) $(OBJSBONUS)
	ar rcs $(NAME) $(OBJSBONUS)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSBONUS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJSBONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE)

.PHONY : all clean fclean re bonus
