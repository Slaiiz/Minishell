#                   #
#    TABSTOP: 16    #
#                   #

NAME	 = libflag.a
GCC	 = gcc
GCCFLAGS	 = -Wall -Wextra -Werror
AR	 = ar
OBJS	 = libflag_add.o libflag_free.o libflag_parse.o
OBJSDIR	 = objs
INCLUDE	 = include
LIBFT	 = ../libft

INCLUDE	:= $(LIBFT) $(INCLUDE)
OBJS_	 = $(addprefix $(OBJSDIR)/,$(OBJS))
INCLUDE_	 = $(addprefix -I,$(INCLUDE))

.PHONY:	 all mostlyclean clean fclean re

ifneq	 ($(GCCFLAGS),-Wall -Wextra -Werror)
all:	 $(NAME)
	 $(warning Compilation flags disabled!)
else
all:	 $(NAME)
endif

$(NAME):	 $(OBJS_)
	 @echo "Linking $@..."
	 @$(AR) -cr $@ $^

$(OBJSDIR)/%.o:	 srcs/%.c | $(OBJSDIR)
	 @echo "Compiling $@..."
	 @$(GCC) $(GCCFLAGS) -o$@ -c $(INCLUDE_) $^

srcs/%.c:
	 $(error File $@ is missing!)

$(OBJSDIR):
	 @echo "Creating directory $@..."
	 @mkdir -p $@

mostlyclean:
	 @echo "Deleting objects..."
	 @rm -rf $(OBJSDIR)

clean:	 mostlyclean

fclean:	 clean
	 @echo "Deleting $(NAME)..."
	 @rm -f $(NAME)

re:	 fclean
	 @$(MAKE) all
