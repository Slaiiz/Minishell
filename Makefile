include Powermake.mk

$(call enable-verbose)

$(call set-compiler,gcc)
$(call set-compiler-flags,-Wall -Wextra -Werror)

$(call add-hook,on-add-object-folder-recipe,add-folder)

$(call add-target,minishell)
 $(call add-object-folder,obj/builtins/)
  $(call add-object,cd.o)
  $(call add-object,env.o)
  $(call add-object,exit.o)
  $(call add-object,help.o)
  $(call add-object,pwd.o)
  $(call add-object,setenv.o)
  $(call add-object,unsetenv.o)
 $(call add-object-folder,obj/)
  $(call add-object,execute.o)
  $(call add-object,error.o)
  $(call add-object,input.o)
  $(call add-object,main.o)
  $(call add-object,output.o)
  $(call add-object,vars.o)
 $(call set-source-folder,src/)
 $(call add-include-folder,include/)
 $(call add-dependency,libft/libft.a)
 $(call add-dependency,libflag/libflag.a)

$(call run-powermake)
