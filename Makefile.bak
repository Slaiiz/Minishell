#                   #
#    TABSTOP: 16    #
#                   #

include Powermake.mk

NAME = minishell
GCC = gcc
GCCFLAGS = #-Wall -Wextra -Werror
OBJS = main.o error.o input.o output.o builtins.o vars.o
BUILTINS = cd pwd help env setenv unsetenv exit
OBJSDIR = objs
INCLUDE = include
LIBFT = libft/libft.a
LIBFLAG = libflag/libflag.a

INCLUDE += $(dir $(LIBFT)) $(dir $(LIBFLAG))
DOBJS = $(addprefix $(OBJSDIR)/,$(OBJS))
BUILTINSO = $(addsuffix .o,$(BUILTINS))
DOBJS += $(addprefix objs/,$(BUILTINSO))
IINCLUDE = $(addprefix -I,$(INCLUDE))
VPATH = srcs:srcs/builtins

.PHONY: all mostlyclean clean fclean re help

all: $(NAME)
	$(info $(DEFBUILT))

$(NAME): $(DOBJS) $(LIBFT) $(LIBFLAG)
	@echo "Linking $@..."
	@$(GCC) $(GCCFLAGS) -o$@ $^

$(OBJSDIR)/%.o: %.c $(LIBFT) $(LIBFLAG) | $(OBJSDIR)
	@echo "Compiling $@..."
	@$(GCC) $(GCCFLAGS) -o$@ -c $(IINCLUDE) $<

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

clean: mostlyclean
	@echo "Deleting libraries..."
	@make -C$(dir $(LIBFT)) fclean
	@make -C$(dir $(LIBFLAG)) fclean

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -f $(NAME)

re:	fclean
	@$(MAKE) all

help:
	@echo "all"
	@echo "mostlyclean"
	@echo "clean"
	@echo "fclean"
	@echo "re"
	@echo "help"
