
# ------------ VARIABLES ----------

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
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
	   ft_lstnew_bonus.c \
	   ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c \
	   ft_lstadd_back_bonus.c \
	   ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c \
	   ft_lstmap_bonus.c \
	   ft_contain.c \
	   get_next_line.c

OBJS = $(SRCS:.c=.o)
ARFLAGS = rcs
AR = ar
HDEPS = libft.h
STAGE = -c

# ---------------- RULES ------------------

%.o: %.c $(HDEPS)
	@echo $(COLMPILE) $<
	@$(CC) $(STAGE) $(CFLAGS) $< -o $@


$(NAME): $(OBJS)
	@echo $(ARCHIVE) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)


clean:
	@echo $(REMOVE) $(OBJS) 
	@rm -f $(OBJS)

fclean: clean
	@echo $(REMOVE) $(NAME) 
	@rm -f $(NAME)

re: fclean $(NAME)


.PHONY:  clean


COLMPILE = "\033[1;33m🛠️ Compile :\033[0m"
ARCHIVE = "\033[1;36m🗃️ Archive :\033[0m"
REMOVE = "\033[1;90m🗑️  Remove :\033[0m"
