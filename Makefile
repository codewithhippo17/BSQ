BIN_NAME = bsq

CUR_DIR = $(shell pwd)
SOURCES = main.c \
		  helpers.c \
		  input_helpers.c \
		  is_valid_map.c \
		  map_helpers.c \
		  read_map.c \
		  find_bsq.c
SOURCES_PATHS = $(SOURCES:%=$(CUR_DIR)/%)

CFLAGS = -Wall -Wextra -Werror

all: $(BIN_NAME)

$(BIN_NAME):
	cc $(CFLAGS) $(SOURCES_PATHS) -o $(CUR_DIR)/$(BIN_NAME)

fclean:
	rm -f $(CUR_DIR)/$(BIN_NAME)

re: fclean all