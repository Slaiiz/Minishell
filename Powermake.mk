################################################################################
#                                                             .%x              #
# @@@@@x                                                      .@x              #
# @#::x@x                                                     .@x              #
# @x   %%   =##=  :+.    +:  -x#+.   =+.x#+. +=xx-xx.  :x#x-  .@x  -x=   =##:  #
# @x  .%%  #@x#@x :@: x- @+ :@%x@%.  %@@#x@= @%#@%x@+ :@#x%@- .@x :@#.  #@x#@+ #
# @%xx%@= +@:  =@: @= @+ @: @#  .@x  #@+  -  @+ @+ @x  .  .@x .@x:@x   =@-  x@ #
# @%%#x:  #%   .@x @x-@#-@.-@#xxx@#  #@.     @+ @+ @x  :x##@x .@%@%    #@xxx#@ #
# @x      %%   .@x ##+x#=@ :@%#%##x  #@.     @+ @+ @x x@%xx@x .@%x@x   #@#%### #
# @x      x@-  :@= =@%.x%# .@x       #@.     @x @+ @x @x  .@x .@x x@=  x@.     #
# @x      .%@==@%  :@% =@x  x@=-:#-  #@.     @+ @+ @x @%==@@x .@x  #@: .@%:.xx #
# #=       .x@@x.  .#x .#:   x@@@#.  x#.     %+ %+ %+ :#@%=#+ .#+  .##. :#@@@= #
#                                                                              #
################################################################################
#                                                                              #
#    - When curiosity goes towards harnessing the full power of GNU Make! -    #
#                                 vchesnea                                     #
#                                                                              #
################################################################################
#   The present tool is currently adapted for binary projects but in a near    #
#           future it will be extended to a more general-purpose tool.         #
# ---------------------------------------------------------------------------- #
#                            MAKEFILE AUTOMATION                               #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void add-dependency(name, path)
# void add-include-folder(path)
# void add-object(path)
# void add-object-folder(path)
# void add-source-folder(path)
# void add-target(path)
# void run-powermake(void)
# void set-compiler(string)
# void set-compiler-flags(string)
#

# @name set-compiler
# @input string
# @brief Sets the compiler to use in producing objects.
define set-compiler
$(strip 
$(eval compiler_ := ${1}))
endef

# @name set-compiler-flags
# @input string
# @brief Sets the compiler flags to use in producing objects.
define set-compiler-flags
$(strip 
$(eval compiler-flags_ := ${1}))
endef

# @name add-target
# @input path
# @brief Adds a new produceable target. All subsequent calls to
# add-dependency, add-object, add-source-folder or add-include-folder
# will be bound to this target.
define add-target
$(strip 
$(eval current-target_ := ${1})
$(eval targets_ += $(sort ${1})))
endef

# @name add-dependency
# @input path
# @brief Adds a new dependency. It is assumed to be pointing at a file
# whose directory contains a Makefile.
define add-dependency
$(strip 
$(call add-include-folder,$(dir ${1}))
$(eval ${current-target_}-dependencies_ += $(sort ${1})))
endef

# @name add-object
# @input path
# @brief Adds a new object. Its sources will be fetched amongst the given
# source folders.
define add-object
$(strip 
$(eval 0a_ := ${current-object-folder_}${1})
$(eval ${current-target_}-objects_ += $(sort ${0a_})))
endef

# @name set-source-folder
# @input path
# @brief Sets a new source folder. This folder is bound to its target and
# it will fetch its sources from here.
define set-source-folder
$(strip 
$(eval 0a_ := $(subst //,/,${1}/))
$(eval ${current-target_}-source-folder_ := $(sort ${0a_})))
endef

# @name add-object-folder
# @input path
# @brief Adds a new object folder. All subsequent calls to set-source-folder
# will be bound to this folder.
define add-object-folder
$(strip 
$(eval 0a_ := $(subst //,/,${1}/))
$(eval current-object-folder_ := ${0a_})
$(eval ${current-target_}-object-folders_ += $(sort ${0a_})))
endef

# @name add-include-folder
# @input path
# @brief Adds a new include folder. It is assumed to contain include files.
define add-include-folder
$(strip 
$(eval 0a_ := $(subst //,/,${1}/))
$(eval ${current-target_}-include-folders_ += $(sort ${0a_})))
endef

# @name run-powermake
# @brief Runs all the recipe work. This should be the last function to be
# called.
define run-powermake
$(strip 
$(eval ifeq (${verbose_},true)
$$(info $${recipe-all_})
$$(info $${recipe-mostlyclean_})
$$(info $${recipe-clean_})
$$(info $${recipe-fclean_})
$$(info $${recipe-re_})
$$(info $${recipe-help_})
endif)
$(eval ${recipe-all_})
$(eval ${recipe-mostlyclean_})
$(eval ${recipe-clean_})
$(eval ${recipe-fclean_})
$(eval ${recipe-re_})
$(eval ${recipe-help_})
$(foreach _,${targets_},$(call add-target-recipe_,${_})))
endef

# ---------------------------------------------------------------------------- #
#                                  DEBUGGING                                   #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void debug-var(variable)
# void disable-verbose(void)
# void enable-verbose(void)
#

# @name debug-var
# @input variable
# @brief Prints the debugged value of a given variable.
define debug-var
$(strip 
$(info ${1} is ${${1}}))
endef

# @name enable-verbose
# @brief Enable script verbose for debugging purposes.
define enable-verbose
$(strip 
$(eval verbose_ = true))
endef

# @name disable-verbose
# @brief Disable script verbose.
define disable-verbose
$(strip 
$(eval verbose_ = false))
endef

# ---------------------------------------------------------------------------- #
#                                TOKENIZATION                                  #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void consume-token(variable)
# token get-token(variable)
# token peek-token(variable)
#

# @name peek-token
# @input variable
# @output token
# @brief Returns the next token in variable, without popping it off the stack.
define peek-token
$(strip 
$(firstword ${${1}}))
endef

# @name get-token
# @input variable
# @output token
# @brief Returns the next token in variable, popping it off the stack.
define get-token
$(strip 
$(firstword ${${1}})
$(call consume-token,${1}))
endef

# @name consume-token
# @input variable
# @brief Pops the next token in variable off the stack.
define consume-token
$(strip 
$(eval ${1} := $(shell echo "${${1}} " | cut -f2- -d" ")))
endef

# ---------------------------------------------------------------------------- #
#                           VARIABLES & ARITHMETIC                             #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void add-var(variable,value)
# void assign-var(variable,value)
# void decrement-var(variable)
# void divide-var(variable,value)
# void increment-var(variable)
# void multiply-var(variable,value)
# void subtract-var(variable,value)
#

# @name assign-var
# @input variable
# @input value
# @brief Assigns value to a numeric variable.
define assign-var
$(strip 
$(eval ${1} := $(shell expr ${2})))
endef

# @name increment-var
# @input variable
# @brief Increments a numeric variable.
define increment-var
$(strip 
$(call add-var,${1},1))
endef

# @name decrement-var
# @input variable
# @brief Decrements a numeric variable.
define decrement-var
$(strip 
$(call subtract-var,${1},1))
endef

# @name add-var
# @input variable
# @input value
# @brief Computes the sum of variable and value into variable.
define add-var
$(strip 
$(eval ${1} := $(shell expr ${${1}} \+ ${2})))
endef

# @name subtract-var
# @input variable
# @input value
# @brief Computes the difference of variable and value into variable.
define subtract-var
$(strip 
$(eval ${1} := $(shell expr ${${1}} \- ${2})))
endef

# @name multiply-var
# @input variable
# @input value
# @brief Computes the product of variable and value into variable.
define multiply-var
$(strip 
$(eval ${1} := $(shell expr ${${1}} \* ${2})))
endef

# @name divide-var
# @input variable
# @input value
# @brief Computes the quotient of variable and value into variable.
define divide-var
$(strip 
$(eval ${1} := $(shell expr ${${1}} \/ ${2})))
endef

# ---------------------------------------------------------------------------- #
#                                MISCELLANEOUS                                 #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void repeat(count,string)
#

# @name repeat
# @input count
# @input string
# @brief Evaluates string count times. Like foreach but more flexible.
define repeat
$(strip 
$(eval ifneq (${1},0)
${2}$$(call assign-var,0a_,${1} \- 1)
$$(call repeat,${0a_},${2})
endif))
endef

# ---------------------------------------------------------------------------- #
#                              PRIVATE FUNCTIONS                               #
# ---------------------------------------------------------------------------- #

define add-target-recipe_
$(strip 
$(eval ifeq (${verbose_},true)
$$(info $${recipe-target_})
endif)
$(eval ${recipe-target_})
$(call add-object-folder-recipes_,${1})
$(call add-source-folder-recipe_,${1})
$(call add-dependencies-recipes_,${1}))
endef

define add-object-folder-recipes_
$(strip 
$(eval ifeq (${verbose_},true)
$$(foreach _,${${1}-object-folders_},$$(info $${recipe-object-folder_}))
endif)
$(foreach _,${${1}-object-folders_},$(eval ${recipe-object-folder_})))
endef

define add-source-folder-recipe_
$(strip 
$(eval ifeq (${verbose_},true)
$$(info $${recipe-source-folder_})
endif)
$(eval ${recipe-source-folder_}))
endef

define add-dependencies-recipes_
$(strip 
$(eval ifeq (${verbose_},true)
$$(foreach _,${${1}-dependencies_},$$(info $${recipe-dependencies_}))
endif)
$(foreach _,${${1}-dependencies_},$(eval ${recipe-dependencies_})))
endef

# ---------------------------------------------------------------------------- #
#                              POWERMAKE RECIPES                               #
# ---------------------------------------------------------------------------- #

define recipe-all_
all: ${targets_}
endef

define recipe-mostlyclean_
mostlyclean:
$(eval 0a_ := $(foreach _,${targets_},${${_}-objects_}))
ifneq (${0a_},)
	rm -f ${0a_}
endif
$(eval 0a_ := $(foreach _,${targets_},${${_}-object-folders_}))
ifneq (${0a_},)
	rm -rf ${0b_}
endif
$(eval 0a_ := $(foreach _,${targets_},${${_}-dependencies_}))
$(foreach _,${0a_},
	$$(MAKE) -C $(dir ${_}) mostlyclean)
endef

define recipe-clean_
$(eval 0a_ := $(foreach _,${targets_},${${_}-dependencies_}))
clean: mostlyclean
ifneq (${0a_},)
$(foreach _,${0a_},
	$$(MAKE) -C $(dir ${_}) fclean)
endif
endef

define recipe-fclean_
fclean: clean
ifneq (${targets_},)
	rm -f ${targets_}
endif
endef

define recipe-re_
re: fclean
	$$(MAKE) all
endef

define recipe-help_
help:
	@echo "Powermake commands :"
	@echo "  all"
	@echo "  mostlyclean"
	@echo "  clean"
	@echo "  fclean"
	@echo "  re"
	@echo "  help"
endef

define recipe-target_
${1}: ${${1}-objects_} ${${1}-dependencies_}
	$(compiler_) $(compiler-flags_) -o$$@ $$^
endef

define recipe-object-folder_
$(eval 0a_ := $(addprefix -I,${${1}-include-folders_}))
${_}%.o: ${${1}-source-folder_}%.c ${${1}-dependencies_} | ${_}
	$(compiler_) $(compiler-flags_) -o$$@ -c $$< ${0a_}
${_}:
	mkdir -p $$@
endef

define recipe-source-folder_
${1}%.c:
	$$(error Powermake : File $$@ not found!)
endef

define recipe-dependencies_
${_}:
	$$(MAKE) -C $(dir ${_})
endef
