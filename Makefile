#                   #
#    TABSTOP: 16    #
#                   #

NAME	 = minishell
GCC	 = gcc
GCCFLAGS	 = #-Wall -Wextra -Werror
OBJS	 = main.o error.o input.o output.o vars.o
BUILTINS	 = cd help env setenv unsetenv exit
OBJSDIR	 = objs
INCLUDE	 = include
LIBFT	 = libft/libft.a
LIBFLAG	 = libflag/libflag.a

INCLUDE	:= $(INCLUDE) $(dir $(LIBFT)) $(dir $(LIBFLAG))
OBJS_	 = $(addprefix $(OBJSDIR)/,$(OBJS))
BUILTINS_	 = $(addsuffix .o,$(BUILTINS))
OBJS_	:= $(OBJS_) $(addprefix objs/,$(BUILTINS_))
INCLUDE_	 = $(addprefix -I,$(INCLUDE))
.PHONY:	 all mostlyclean clean fclean re help
VPATH	 = srcs:srcs/builtins

ifneq	 ($(GCCFLAGS),-Wall -Wextra -Werror)
all:	 $(NAME)
	 $(warning Compilation flags disabled!)
else
all:	 $(NAME)

endif

$(NAME):	 $(OBJS_) $(LIBFT) $(LIBFLAG)
	 @echo "Linking $@..."
	 @$(GCC) $(GCCFLAGS) -o$@ $^

$(OBJSDIR)/%.o:	 %.c $(LIBFT) $(LIBFLAG) | $(OBJSDIR)
	 @echo "Compiling $@..."
	 @$(GCC) $(GCCFLAGS) -o$@ -c $(INCLUDE_) $<

srcs/%.c:
	 $(error File $@ is missing!)

$(LIBFT):
	 @$(MAKE) -C$(dir $(LIBFT)) all

$(LIBFLAG):
	 @$(MAKE) -C$(dir $(LIBFLAG)) all

$(OBJSDIR):
	 @echo "Creating directory $@..."
	 @mkdir -p $@

mostlyclean:
	 @echo "Deleting objects..."
	 @rm -rf $(OBJSDIR)
	 @make -C$(dir $(LIBFT)) clean
	 @make -C$(dir $(LIBFLAG)) clean

clean:	 mostlyclean
	 @echo "Deleting libraries..."
	 @make -C$(dir $(LIBFT)) fclean
	 @make -C$(dir $(LIBFLAG)) fclean

fclean:	 clean
	 @echo "Deleting $(NAME)..."
	 @rm -f $(NAME)

re:	 fclean
	 @$(MAKE) all

help:
	 @echo "all"
	 @echo "mostlyclean"
	 @echo "clean"
	 @echo "fclean"
	 @echo "re"
	 @echo "help"
