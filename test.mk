include Powermake.mk

define my-hook
$(info Done!)
endef

$(call add-hook,on-finish,my-hook)

# ...

$(call run-hook,on-finish)
