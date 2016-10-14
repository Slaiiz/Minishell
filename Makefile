#                   #
#    TABSTOP: 16    #
#                   #

NAME	 = minishell
GCC	 = gcc
GCCFLAGS	 = #-Wall -Wextra -Werror
OBJS	 = main.o error.o input.o output.o builtins.o vars.o
BUILTINS	 = cd pwd help env setenv unsetenv exit
OBJSDIR	 = objs
INCLUDE	 = include
LIBFT	 = libft/libft.a
LIBFLAG	 = libflag/libflag.a

PROLOGUE	 = register_builtin(
EPILOGUE	 = );
COMMA	 = ,
DEFBUILT	:= $(foreach _,$(BUILTINS),$(_)$(COMMA)builtin_$(_))
DEFBUILT	:= $(addprefix $(PROLOGUE),$(DEFBUILT))
DEFBUILT	:= $(addsuffix $(EPILOGUE),$(DEFBUILT))
DEFBUILT	:= REGISTER_BUILTINS="$(DEFBUILT)"
INCLUDE	:= $(INCLUDE) $(dir $(LIBFT)) $(dir $(LIBFLAG))
DOBJS	 = $(addprefix $(OBJSDIR)/,$(OBJS))
BUILTINSO	 = $(addsuffix .o,$(BUILTINS))
DOBJS	:= $(DOBJS) $(addprefix objs/,$(BUILTINSO))
IINCLUDE	 = $(addprefix -I,$(INCLUDE))
DEFINES	 = -D$(DEFBUILT) -DNUMBUILTINS=$(words $(BUILTINS))
.PHONY:	 all mostlyclean clean fclean re help
VPATH	 = srcs:srcs/builtins

ifneq	 ($(GCCFLAGS),-Wall -Wextra -Werror)
all:	 $(NAME)
	 $(warning Compilation flags disabled!)
	 $(warning $(RBUILTINS))
else
all:	 $(NAME)

endif

$(NAME):	 $(DOBJS) $(LIBFT) $(LIBFLAG)
	 @echo "Linking $@..."
	 @$(GCC) $(GCCFLAGS) -o$@ $^

$(MAINO)

$(OBJSDIR)/%.o:	 %.c $(LIBFT) $(LIBFLAG) | $(OBJSDIR)
	 @echo "Compiling $@..."
	 @$(GCC) $(GCCFLAGS) -o$@ -c $(IINCLUDE) $(DEFBUILT) $<

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
