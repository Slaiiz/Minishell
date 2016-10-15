# ---------------------------------------------------------------------------- #
#                            MAKEFILE AUTOMATION                               #
# ---------------------------------------------------------------------------- #

define set-compiler
$(strip
$(eval compiler = ${1}))
endef

define set-compiler-flags
$(strip
$(eval compiler-flags = ${1}))
endef

define add-target
endef

define add-dependency
endef

define add-object
endef

define add-include
endef

# ---------------------------------------------------------------------------- #
#                                TOKENIZATION                                  #
# ---------------------------------------------------------------------------- #

# @name peek-token
# @input variable
# @output token
# @brief Returns the next token in variable, without popping it off the stack.
define peek-token
endef

# @name get-token
# @input variable
# @output token
# @brief Returns the next token in variable, popping it off the stack.
define get-token
endef

# @name consume-token
# @input variable
# @brief Pops the next token in variable off the stack.
define get-token
endef

# ---------------------------------------------------------------------------- #
#                           VARIABLES & ARITHMETIC                             #
# ---------------------------------------------------------------------------- #

# @name initialize-var
# @input variable
# @brief Initializes a numeric variable.
define initialize-var
$(strip
$(eval ${1} := 0))
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
