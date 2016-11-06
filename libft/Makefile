# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vchesnea <vchesnea@student.42.fr>            +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2016/11/01 13:40:41 by vchesnea            #+#    #+#             #
#   Updated: 11/6/2016, 5:06:28 PM by vchesnea         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

gcc = gcc
gcc-flags = -Wall -Wextra -Werror

ar = ar
ar-flags = -cr

define obj-array
$(addprefix obj/array/,$(strip 
ft_arrdel.o      ft_arriter.o    ft_arrnew.o))
endef

define obj-buffer
$(addprefix obj/buffer/,$(strip 
ft_bufadd.o      ft_bufdel.o     ft_bufnew.o     ft_bufsub.o
ft_bufdup.o))
endef

define obj-integer
$(addprefix obj/integer/,$(strip 
ft_abs.o         ft_atoi.o       ft_max.o        ft_min.o
ft_nbrlen.o      ft_parseint.o))
endef

define obj-io
$(addprefix obj/io/,$(strip 
ft_putchar_fd.o  ft_putchar.o    ft_putendl_fd.o ft_putendl.o
ft_putnbr_base.o ft_putnbr_fd.o  ft_putnbr.o     ft_putstr_fd.o
ft_putstr.o))
endef

define obj-list
$(addprefix obj/list/,$(strip 
ft_lstadd.o      ft_lstdel.o     ft_lstdelone.o  ft_lstdup.o
ft_lstiter.o     ft_lstlen.o     ft_lstmap.o     ft_lstnew.o))
endef

define obj-memory
$(addprefix obj/memory/,$(strip 
ft_bzero.o       ft_memalloc.o   ft_memccpy.o    ft_memchr.o
ft_memcmp.o      ft_memcpy.o     ft_memdel.o     ft_memdel.o
ft_memdup.o      ft_memmove.o    ft_memset.o))
endef

define obj-printf
$(addprefix obj/printf/,$(strip 
display.o        extras.o        main.o          utilities.o))
endef

define obj-qtree
$(addprefix obj/qtree/,$(strip 
ft_qtreedel.o    ft_qtreeget.o   ft_qtreeiter.o  ft_qtreenew.o
ft_qtreeset.o))
endef

define obj-special
$(addprefix obj/special/,$(strip 
ft_chrrep.o      ft_expect.o     ft_printmem.o   ft_rot13.o
ft_seekstr.o))
endef

define obj-string
$(addprefix obj/string/,$(strip 
ft_isalnum.o     ft_isalpha.o    ft_isascii.o    ft_isblank.o
ft_isdigit.o     ft_isprint.o    ft_itoa_base.o  ft_itoa_base64.o
ft_itoa.o        ft_strcat.o     ft_strchr.o     ft_strclr.o
ft_strcmp.o      ft_strcmpcase.o ft_strcpy.o     ft_strdel.o
ft_strdup.o      ft_strequ.o     ft_striter.o    ft_striteri.o
ft_strjoin.o     ft_strlcat.o    ft_strlen.o     ft_strlowcase.o
ft_strmap.o      ft_strmapi.o    ft_strncat.o    ft_strncmp.o
ft_strncpy.o     ft_strndup.o    ft_strnequ.o    ft_strnew.o
ft_strnstr.o     ft_strrchr.o    ft_strrev.o     ft_strsplit.o
ft_strstr.o      ft_strsub.o     ft_strtrim.o    ft_strupcase.o
ft_tolower.o     ft_toupper.o    ft_uitoa_base.o ft_uitoa_base64.o
ft_itoa64.o      ft_uitoa64.o))
endef

define objs
$(strip 
${obj-array} ${obj-buffer} ${obj-integer} ${obj-io} ${obj-list}
${obj-memory} ${obj-special} ${obj-string} obj/printf/ft_printf.o)
endef

.phony: all mostlyclean clean fclean re obj-buffer obj-integer obj-io \
        obj-list obj-memory obj-qtree obj-special obj-string

lib/libft.a: ${objs} | lib/
	${ar} ${ar-flags} $@ ${obj-array} ${obj-buffer} ${obj-integer} \
	${obj-io} ${obj-list} ${obj-memory} ${obj-special} ${obj-string} \
	obj/printf/ft_printf.o
lib/:
	mkdir -p $@

all: lib/libft.a

mostlyclean:
	rm -rf obj

clean: mostlyclean

fclean: clean
	rm -rf lib

re: fclean
	${MAKE} all

obj/array/%.o: src/array/%.c | obj/array
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/array:
	mkdir -p $@

obj/buffer/%.o: src/buffer/%.c | obj/buffer
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/buffer:
	mkdir -p $@

obj/integer/%.o: src/integer/%.c | obj/integer
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/integer:
	mkdir -p $@

obj/io/%.o: src/io/%.c | obj/io
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/io:
	mkdir -p $@

obj/list/%.o: src/list/%.c | obj/list
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/list:
	mkdir -p $@

obj/memory/%.o: src/memory/%.c | obj/memory
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/memory:
	mkdir -p $@

obj/printf/%.o: src/printf/%.c | obj/printf
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/printf:
	mkdir -p $@

obj/qtree/%.o: src/qtree/%.c | obj/qtree
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/qtree:
	mkdir -p $@

obj/special/%.o: src/special/%.c | obj/special
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/special:
	mkdir -p $@

obj/string/%.o: src/string/%.c | obj/string
	${gcc} ${gcc-flags} -o $@ -c -I include/libft $^
obj/string:
	mkdir -p $@

obj/printf/ft_printf.o: ${obj-printf} | obj/printf
	${gcc} ${gcc-flags} -o $@ -r $^

src/%.c:
	$(error File $@ not found)
