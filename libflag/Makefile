# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vchesnea <vchesnea@student.42.fr>            +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2016/10/06 18:19:39 by vchesnea            #+#    #+#             #
#   Updated: 2017/00/02 15:32:46 by vchesnea           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

gcc = gcc
gcc-flags = -Wall -Wextra -Werror

ar = ar
ar-flags = -cr

define objects
$(addprefix obj/,$(strip 
flag_add.o
flag_free.o
flag_parse.o))
endef

.phony: all mostlyclean clean fclean re

lib/libflag.a: ${objects} | lib
	${ar} ${ar-flags} $@ $^

all: lib/libflag.a

mostlyclean:
	rm -rf obj

clean: mostlyclean

fclean: clean
	rm -rf lib

re: fclean
	${MAKE} all

lib:
	mkdir -p $@

obj/%.o: src/%.c | obj
	${gcc} ${gcc-flags} -o $@ -c -I include -I ../libft/include $^

src/%.c:
	$(error File $@ not found)

obj:
	mkdir -p $@

