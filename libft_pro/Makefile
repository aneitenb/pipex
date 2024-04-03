NAME = libft.a

SOURCES =  ft_isdigit.c \
		   ft_split.c \
		   ft_strmapi.c \
		   ft_striteri.c \
		   ft_itoa.c \
		   ft_strtrim.c \
		   ft_strjoin.c \
		   ft_substr.c \
		   ft_putnbr_fd.c \
		   ft_putendl_fd.c \
		   ft_putstr_fd.c \
		   ft_putchar_fd.c \
		   ft_isalpha.c \
		   ft_calloc.c \
		   ft_strdup.c \
		   ft_atoi.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strlen.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strncmp.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_strlcpy.c\
		   ft_strlcat.c \
		   ft_strnstr.c \
		   ft_printf.c \
		   pf_putchar.c \
		   pf_putstr.c \
		   pf_putnbr.c \
		   pf_puthexbase.c \
		   pf_putun.c \
		   pf_putptr.c \
		   get_next_line.c \
		   get_next_line_utils.c
		  	 
OBJECTS = $(SOURCES:.c=.o)

B_OBJECTS = $(B_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = @cc

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar -cr $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean re all fclean
