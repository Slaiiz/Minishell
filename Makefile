# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vchesnea <vchesnea@student.42.fr>            +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2016/10/06 18:19:52 by vchesnea            #+#    #+#             #
#   Updated: 2017/02/11 16:55:17 by vchesnea           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

include Powermake.mk

$(call enable-verbose)

$(call set-compiler,gcc)
$(call set-compiler-flags,-Wall -Wextra -Werror)

$(call add-target,minishell)
 $(call add-object-folder,obj/builtins/)
  $(call add-source-folder,src/builtins/)
   $(call add-object,cd.o)
   $(call add-object,env.o)
   $(call add-object,exit.o)
   $(call add-object,help.o)
   $(call add-object,pwd.o)
   $(call add-object,setenv.o)
   $(call add-object,unsetenv.o)
   $(call add-object,echo.o)
 $(call add-object-folder,obj/)
  $(call add-source-folder,src/)
   $(call add-object,execute.o)
   $(call add-object,error.o)
   $(call add-object,helpers.o)
   $(call add-object,input.o)
   $(call add-object,main.o)
   $(call add-object,output.o)
   $(call add-object,vars.o)
   $(call add-object,parsing.o)
 $(call add-include-folder,include/)
 $(call add-dependency,libft)
 $(call add-dependency,libflag)

$(call run-powermake)
