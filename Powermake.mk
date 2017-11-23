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
################################################################################

# List of builtin Powermake hooks :
#
# * on-run-powermake(void)
# * on-end-powermake(void)
# * on-add-target-recipe(target)
# * on-add-object-folder-recipe(target)
# * on-add-source-folder-recipe(target)
# * on-add-dependency-recipe(target)
# * on-missing-source-file(file)

# ---------------------------------------------------------------------------- #
#                            MAKEFILE AUTOMATION                               #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void add-dependency(name,path)
# void add-include-folder(path)
# void add-object(path)
# void add-object-folder(path)
# void add-source-folder(path)
# void add-target(path)
# void run-powermake(void)
# void set-compiler(string)
# void set-compiler-flags(string)

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
$(eval targets_ += ${1})
$(eval current-target_ := ${1}))
endef

# @name add-dependency
# @input path
# @brief Adds a new dependency. It is assumed to be pointing at a directory
# containing a Makefile, and at least these two directories : lib and include.
define add-dependency
$(strip
$(eval ${current-target_}-dependencies_ += ${1})
$(call add-include-folder,${1}/include/))
endef

# @name add-object
# @input path
# @brief Adds a new object. Its sources will be fetched amongst the given
# source folders.
define add-object
$(strip
$(eval ${current-target_}-${current-object-folder_}-objects_ += ${1}))
endef

# @name add-source-folder
# @input path
# @brief Adds a new source folder. This folder is bound to its object folder and
# it will fetch its sources from here.
define add-source-folder
$(strip
$(eval a0_ = $$(subst //,/,$${1}))
$(eval ${current-target_}-${current-object-folder_}-sources_ := ${a0_}))
endef

# @name add-object-folder
# @input path
# @brief Adds a new object folder. All subsequent calls to set-source-folder
# will be bound to this folder.
define add-object-folder
$(strip
$(eval ${current-target_}-object-folders_ += $(subst //,/,${1}))
$(eval current-object-folder_ := ${1}))
endef

# @name add-include-folder
# @input path
# @brief Adds a new include folder. It is assumed to contain include files.
define add-include-folder
$(strip
$(eval ${current-target_}-include-folders_ += $(subst //,/,${1})))
endef

define run-powermake
$(strip
$(call run-hook,on-run-powermake)
$(eval ifeq (${verbose_},true)
$$(info $${all-recipe_})
$$(info $${mostlyclean-recipe_})
$$(info $${clean-recipe_})
$$(info $${fclean-recipe_})
$$(info $${re-recipe_})
$$(info $${help-recipe_})
endif)
$(eval ${all-recipe_})
$(eval ${mostlyclean-recipe_})
$(eval ${clean-recipe_})
$(eval ${fclean-recipe_})
$(eval ${re-recipe_})
$(eval ${help-recipe_})
$(foreach _,${targets_},
	$(call add-target-recipe,${_}))
$(call run-hook,on-end-powermake))
endef

# ---------------------------------------------------------------------------- #
#                                  DEBUGGING                                   #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void debug-var(variable)
# void disable-verbose(void)
# void enable-verbose(void)

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
# @brief Returns the next token in variable, consuming it in the process.
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
$(eval ${1} := $(shell echo "${${1}} " | cut -f 2- -d " ")))
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

# @name assign-var
# @input variable
# @input expression
# @brief Assigns expression to a numeric variable.
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
#                            PROGRAM EXECUTION FLOW                            #
# ---------------------------------------------------------------------------- #

# Function index :
#
# void repeat(count,string)
# void until(boolean,string)
# void while(boolean,string)

# @name repeat
# @input count
# @input string
# @brief Evaluates string count times. Like foreach but more flexible.
define repeat
$(strip
$(eval ifneq (${1},0)
${2}$$(call assign-var,0a_,${1} \- 1)
$$(call repeat,$${0a_},$${2})
endif))
endef

# @name while
# @input boolean
# @input string
# @brief Evaluates string as long as boolean is not 'false'.
# 'false' is interpreted as either 0, false or empty string. boolean should
# always be a reference to something unless you're into infinite loops.
define while
$(strip
$(eval 0a_ := $$(subst 0,,${1})
0a_ := $$(subst false,,$${0a_})
ifneq ($${0a_},)
${2}$$(call while,$${1},$${2})
endif))
endef

# @name until
# @input boolean
# @input string
# @brief Evaluates string as long as boolean is not 'true'.
# 'true' is interpreted as non-zero, non-false and non-empty combined.
# boolean should always be a reference to something unless you're into
# infinite loops.
define until
$(strip
$(eval 0a_ := $(subst 0,,${1})
0a_ := $$(subst false,,$${0a_})
ifeq ($${0a_},)
${2}$$(call until,$${1},$${2})
endif))
endef

# ---------------------------------------------------------------------------- #
#                       HOOK MANAGEMENT / EVENT HANDLING                       #
# ---------------------------------------------------------------------------- #

# @name add-hook
# @input hook
# @input function
# @brief Binds function to hook. On call, contextual data can be retrieved
# from the first argument ${1}.
define add-hook
$(strip
$(eval hooks_${1} += ${2}))
endef

# @name run-hook
# @input hook
# @input data
# @brief Evaluates all functions bound to hook. Data may be passed into
# the first argument of the functions involved.
define run-hook
$(strip
$(foreach _,${hooks_${1}},
	$(call ${_},${2})))
endef

# ---------------------------------------------------------------------------- #
#                         DISCLOSED PRIVATE FUNCTIONS                          #
# ---------------------------------------------------------------------------- #

# @name add-target-recipe
# @input target
# @brief Registers a recipe for target.
define add-target-recipe
$(strip
$(call run-hook,on-add-target-recipe,${1})
$(eval ifeq (${verbose_},true)
$$(info $${target-recipe_})
endif)
$(eval ${target-recipe_})
$(foreach _,${${1}-object-folders_},
	$(call add-object-folder-recipe,${1},${_}))
$(foreach _,${${1}-dependencies_},
	$(call add-dependency-recipe,${1},${_})))
endef

# @name add-object-folder-recipe_
# @input target
# @input object-folder
# @brief Registers a recipe from target for object-folder.
define add-object-folder-recipe
$(strip
$(call run-hook,on-add-object-folder-recipe,${2})
$(eval ifeq (${verbose_},true)
$$(info $${object-folder-recipe_})
endif)
$(eval ${object-folder-recipe_})
$(foreach _,${${1}-${2}-objects_},
	$(call add-object-recipe,${1},${2},${_})))
endef

# @name add-object-recipe
# @input target
# @input object-folder
# @input object
# @brief Registers a recipe from object-folder from target for object.
define add-object-recipe
$(strip
$(call run-hook,on-add-object-recipe,${3})
$(eval 0a_ := $$(addprefix -I,$${$${1}-include-folders_}))
$(eval ifeq (${verbose_},true)
$$(info $${object-recipe_})
endif)
$(eval ${object-recipe_}))
endef

# @name add-dependency-recipe_
# @input target
# @input dependency
# @brief Registers a recipe from target for dependency.
define add-dependency-recipe
$(strip
$(call run-hook,on-add-dependency-recipe,${2})
$(eval ifeq (${verbose_},true)
$$(info $${dependency-recipe_})
endif)
$(eval ${dependency-recipe_}))
endef

# ---------------------------------------------------------------------------- #
#                              POWERMAKE RECIPES                               #
# ---------------------------------------------------------------------------- #

define all-recipe_

all:
	$$(MAKE) -j ${targets_}
endef

define mostlyclean-recipe_
$(eval 0a_ = $$(foreach _,$${targets_},$${$${_}-object-folders_}))
mostlyclean:\
$(foreach _,${0a_},
	+rm -rf ${_})\
$(eval 0a_ = $$(foreach _,$${targets_},$${$${_}-dependencies_}))\
$(foreach _,${0a_},
	$$(MAKE) -C ${_} mostlyclean)
endef

define clean-recipe_
$(eval 0a_ = $$(foreach _,$${targets_},$${$${_}-dependencies_}))
clean: mostlyclean\
$(foreach _,${0a_},
	$$(MAKE) -C ${_} clean)
endef

define fclean-recipe_
$(eval 0a_ = $$(foreach _,$${targets_},$${$${_}-dependencies_}))
fclean: clean\
$(foreach _,${targets_},
	rm -f ${_})\
$(foreach _,${0a_},
	$$(MAKE) -C ${_} fclean)
endef

define re-recipe_

re: fclean
	$$(MAKE) -j
endef

define help-recipe_

help:
	@echo "* all"
	@echo "* mostlyclean"
	@echo "* clean"
	@echo "* fclean"
	@echo "* re"
	@echo "* help"
endef

define target-recipe_
$(eval 0a_ = $$(addprefix $${_},$${$${1}-$${_}-objects_}))\
$(eval 0b_ = $$(foreach _,$${$${1}-object-folders_},$${0a_}))
${1}: ${0b_} $(foreach _,${${1}-dependencies_},${_}/lib/$(notdir ${_}).a)
	${compiler_} ${compiler-flags_} -o $$@ $$^
endef

define object-folder-recipe_

${2}:
	mkdir -p $$@
endef

define object-recipe_

${2}${3}: ${${1}-${2}-sources_}$(3:.o=.c) | ${2}
	${compiler_} ${compiler-flags_} ${0a_} -o $$@ -c $$<

${${1}-${2}-sources_}$(3:.o=.c):
	$$(call run-hook,on-missing-source-file)
	$$(error Powermake : File $$@ not found!)
endef

define dependency-recipe_

${2}/lib/$(notdir ${2}).a:
	$$(MAKE) -C ${2} all
endef

# ---------------------------------------------------------------------------- #
#                           CHARACTER SUBSTITUTIONS                            #
# ---------------------------------------------------------------------------- #

# * co : comma
# * sp : space
# * nl : newline

define co
,
endef

define sp

endef

define nl


endef
