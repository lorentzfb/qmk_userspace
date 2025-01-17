# The /users/<name>/rules.mk file will be included in the build
# after the rules.mk from your keymap. This allows you to have
# features in your userspace rules.mk that depend on individual
# QMK features that may or may not be available on a specific keyboard.


# use these values if not defined at the keyboard level
BOOTMAGIC_ENABLE       ?= yes
CAPS_WORD_ENABLE       ?= yes
NUM_WORD_ENABLE        ?= yes
COMBO_ENABLE           ?= yes

RGB_MATRIX_ENABLE      ?= no

VPATH += $(USER_PATH)/features/

# Include my code that will be common across all my keyboards
SRC += $(USER_PATH)/lorentzfb.c



# ---------------------------------------------------------
# Include additional code for enabled features for each keyboard

ifeq ($(strip $(COMBO_ENABLE)), yes)
    INTROSPECTION_KEYMAP_C += features/combos.c
endif

# ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
#     SRC += features/caps_word.c
# endif

ifeq ($(strip $(NUM_WORD_ENABLE)), yes)
	SRC += features/num_word.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += $(USER_PATH)/features/rgb_matrix.c
endif
