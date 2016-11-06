gcc = gcc
gcc-flags = -Wall -Wextra -Werror

ar = ar
ar-flags = -cr

define objects
$(addprefix obj/,$(strip 
libflag_add.o libflag_free.o libflag_parse.o))
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

