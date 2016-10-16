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
$(eval targets_ += ${1}))
endef

# @name add-dependency
# @input path
# @brief Adds a new dependency. It is assumed to be pointing at a file
# whose directory contains a Makefile.
define add-dependency
$(strip
$(call add-include-folder,$(dir ${1}))
$(eval ${current-target_}-dependencies_ += ${1}))
endef

# @name add-object
# @input path
# @brief Adds a new object. Its sources will be fetched amongst the given
# source folders.
define add-object
$(strip
$(eval ${current-target_}-objects_ += ${current-object-folder_}/${1}))
endef

# @name add-source-folder
# @input path
# @brief Adds a new source folder. It is assumed to contain source files.
define add-source-folder
$(strip
$(eval ${current-target_}-source-folders_ += ${1}))
endef

# @name add-object-folder
# @input path
# @brief Add a new object folder. All subsequent calls to add-object will
# be bound to this folder.
define add-object-folder
$(strip
$(eval current-object-folder_ := ${1})
$(eval ${current-target_}-object-folders_ += ${1}))
endef

# @name add-include-folder
# @input path
# @brief Adds a new include folder. It is assumed to contain include files.
define add-include-folder
$(strip
$(eval ${current-target_}-include-folders_ += ${1}))
endef

# @name run-powermake
# @brief Runs all the recipe work. This should be the last function to be
# called.
define run-powermake
$(strip
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
# @brief Enable script verbosity for debugging purposes.
define enable-verbosity
$(strip
$(eval verbose_ = true))
endef

# @name disable-verbose
# @brief Enable script verbosity for debugging purposes.
define disable-verbosity
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
$(eval ${1} = $(shell echo "${${1}}" | cut -f1 -d" ")))
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
$(call sub-var,${1},1))
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
#                              PRIVATE FUNCTIONS                               #
# ---------------------------------------------------------------------------- #

define add-target-recipe_
$(strip
$(eval ${recipe-target_})
$(call add-object-folder-recipes_,${1})
$(call add-source-folder-recipes_,${1})
$(call add-dependencies-recipes_,${1}))
endef

define add-object-folder-recipes_
$(strip
$(foreach _,${${1}-object-folders_},$(eval ${recipe-object-folder_})))
endef

define add-source-folder-recipes_
$(strip
$(foreach _,${${1}-source-folders_},$(eval ${recipe-source-folder_})))
endef

define add-dependencies-recipes_
$(strip
$(foreach _,${${1}-dependencies_},$(eval ${recipe-dependencies_})))
endef

# ---------------------------------------------------------------------------- #
#                              POWERMAKE RECIPES                               #
# ---------------------------------------------------------------------------- #

define recipe-all_
all: ${targets_}
endef

define recipe-mostlyclean_
$(eval a0_ := $(foreach _,${targets_},${${_}-objects}))
$(eval a1_ := $(foreach _,${targets_},${${_}-object-folders_}))
mostlyclean:
ifneq (${a0_},)
	rm -f ${a0_}
endif
ifneq (${a1_},)
	rm -rf ${a1_}
endif
endef

define recipe-clean_
$(eval a0_ := $(foreach _,${targets_},${${_}-dependencies_}))
clean: mostlyclean
ifneq (${a0_},)
	$(foreach _,${a0_},$$(MAKE) -C $(dir ${_}) fclean
	)
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
endef

define recipe-help_
help:
	@echo "Commands :"
	@echo " all"
	@echo " mostlyclean"
	@echo " clean"
	@echo " fclean"
	@echo " re"
	@echo " help"
endef

define recipe-target_
${1}: ${${1}-objects_} ${${1}-dependencies_}
	$$(compiler_) $$(compiler-flags_) -o$$@ $$^
endef

define recipe-object-folder_
$(eval 3a_ := ${${1}-dependencies_} | ${_})
$(eval 3b_ := $(addprefix -I,${${1}-include-folders_}))
${_}/%.o: $(addsuffix /%.c,${${1}-source-folders_}) ${3a_}
	$$(compiler_) $$(compiler-flags_) ${3b_} -o$$@ -c $$<
$(info ${3a_})
${_}:
	@echo "Creating $$@"
	mkdir -p $$@
endef

define recipe-source-folder_
${_}/%.c:
	$$(error Powermake : File $$@ not found!)
endef

define recipe-dependencies_
${_}:
	$$(MAKE) -C $(dir ${_})
endef
