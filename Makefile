################################################################################
# Makefile
################################################################################

# Makefile by fletcher
# Version: 1.0

# This makefile can be copied to a directory and it will generate the file
# structure and initialize a git repository with the .init rule. Any variables
# and rules for the specifique project can be added in the appropriate section.

################################################################################
# Project Variables
################################################################################

NAME = libftprintf.a
AR = ar rcs

################################################################################
# Configs
################################################################################

VERBOSE = false
MAKEFLAGS += --silent

################################################################################
# Compiler & Flags
################################################################################

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
# DFLAGS = -g -fsanitize=address

################################################################################
# Folders & Files
################################################################################

BIN_ROOT = bin/
SRC_ROOT = src/
INC_ROOT = inc/
OBJ_ROOT = obj/
DEP_ROOT = dep/
TESTS_ROOT = tests/

DIRS =

SRC_DIRS := $(addprefix ${SRC_ROOT}, ${DIRS})
OBJ_DIRS := $(addprefix ${OBJ_ROOT}, ${DIRS})
DEP_DIRS := $(addprefix ${DEP_ROOT}, ${DIRS})

SRCS := $(foreach dir, ${SRC_DIRS}, $(wildcard ${dir}*.c))
SRCS += $(wildcard ${SRC_ROOT}*.c)
OBJS := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS:.c=.o})
DEPS := $(subst ${SRC_ROOT}, ${DEP_ROOT}, ${SRCS:.c=.d})

TESTS := $(wildcard ${TESTS_ROOT}*.c)

INCS := -I ${INC_ROOT}

BINS := ${BIN_ROOT}${NAME}
TEST := ${TESTS_ROOT}mytest

LIBFT_ROOT = libft/
LIBFT_INC := ${LIBFT_ROOT}inc
LIBFT = ${LIBFT_ROOT}bin/libft.a

INCS += -I ${LIBFT_INC}

################################################################################
# VPATHS
################################################################################

vpath %.o $(OBJ_ROOT)
vpath %.h $(INC_ROOT)
vpath %.c $(SRC_DIRS)
vpath %.d $(DEP_DIRS)

################################################################################
# Conditions
################################################################################

ifeq ($(VERBOSE),true)
	AT =
else
	AT = @
endif

################################################################################
# Project Target
################################################################################

all: ${NAME} bonus
	cp ${BIN_ROOT}${NAME} ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${AT}printf "\033[38;5;46m[CREATING LIBFTPRINTF ARCHIVE]\033[0m\n"
	${AT}mkdir -p ${BIN_ROOT}
	${AT}cp ${LIBFT} ${BIN_ROOT}${NAME}
	${AT}cd ${BIN_ROOT}; ${AR} ${@F} $(addprefix ../, ${OBJS})

bonus:

${LIBFT}:
	${AT}make all -C ${LIBFT_ROOT}

################################################################################
# Setup Target
################################################################################

.init:
	${AT}printf "\033[33m[CREATING FOLDER STRUCTURE]\033[0m\n"
	${AT}mkdir -p ${BIN_ROOT}
	${AT}mkdir -p ${DEP_ROOT}
	${AT}mkdir -p ${INC_ROOT}
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}mkdir -p ${SRC_ROOT}
	${AT}mkdir -p ${TESTS_ROOT}
	${AT}printf "\033[33m[INITIALIZING GIT REPOSITORY]\033[0m\n"
	${AT}git init
	${AT}echo *.o\n*.d\n.vscode\na.out\n.init > .gitignore
	${AT}touch ${BIN_ROOT}.gitkeep
	${AT}touch ${DEP_ROOT}.gitkeep
	${AT}touch ${OBJ_ROOT}.gitkeep
	${AT}touch $@

################################################################################
# General Targets
################################################################################

clean:
	${AT}printf "\033[38;5;1m[REMOVING OBJECTS]\033[0m\n"
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}find ${OBJ_ROOT} -type f -delete 2>/dev/null
	${AT}make $@ -C ${LIBFT_ROOT}

fclean: clean
	${AT}printf "\033[38;5;1m[REMOVING BINARIES]\033[0m\n"
	${AT}mkdir -p ${BIN_ROOT}
	${AT}find ${BIN_ROOT} -type f -delete
	${AT}make $@ -C ${LIBFT_ROOT}

clean_dep:
	${AT}printf "\033[38;5;1m[REMOVING DEPENDENCIES]\033[0m\n"
	${AT}mkdir -p ${DEP_ROOT}
	${AT}find ${DEP_ROOT} -type f -delete 2>/dev/null
	${AT}make $@ -C ${LIBFT_ROOT}

clean_all: clean_dep fclean

re: fclean all

################################################################################
# Test Targets
################################################################################

debug: CFLAGS += ${DFLAGS}
debug: libft_debug all

debug_re: fclean debug

libft_debug:
	${AT}make debug -C ${LIBFT_ROOT}

################################################################################
# Test Targets
################################################################################

testre: debug_re ${TEST}

testm: libft_debug debug ${TEST}

${TEST}: CFLAGS += ${DFLAGS}
${TEST}:
	${AT}printf "\033[38;5;46m[GENERATING TEST]\033[0m\n"
	${AT}${CC} ${CFLAGS} ${INCS} ${TESTS} ${BIN_ROOT}${NAME} -o $@
	${AT}printf "\033[33m[RUNNING TEST]\033[0m\n"
	${AT}./$@

################################################################################
# .PHONY
################################################################################

.PHONY : clean fclean clean_dep clean_all re all testm testre ${LIBFT} ${TEST}

################################################################################
# Function
################################################################################

define make_obj
${1} : ${2} ${3}
	$${AT}printf "\033[38;5;14m[OBJ]: \033[38;5;47m$$@\033[0m\n"
	$${AT}mkdir -p $${@D}
	$${AT}$${CC} $${CFLAGS} $${INCS} -c $$< -o $$@
endef

define make_dep
${1} : ${2}
	$${AT}printf "\033[38;5;13m[DEP]: \033[38;5;47m$$@\033[0m\n"
	$${AT}mkdir -p $${@D}
	$${AT}$${CC} -MM $$< $${INCS} -MF $$@
	$${AT}sed -i.tmp --expression 's|:| $$@ :|' $$@ && rm $$@.tmp
	$${AT}sed -i.tmp --expression '1 s|^|$${@D}/|' $$@ && rm $$@.tmp
endef

################################################################################
# Function Generator
################################################################################

$(foreach src, $(SRCS), $(eval \
$(call make_dep, $(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)), $(src))))

$(foreach src, $(SRCS), $(eval \
$(call make_obj, $(subst ${SRC_ROOT}, ${OBJ_ROOT}, $(src:.c=.o)), \
$(src), \
$(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)))))

################################################################################
# Includes
################################################################################

-include ${DEPS}
