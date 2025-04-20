NAME        := fractol
BONUS_NAME  := fractol_bonus

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -O3
MLX_FLAGS   := -lmlx -lX11 -lXext -lm
INCS        := -I includes

# ─ Mandatory ─────────────────────────────────────────────────────
MAND_SRCS   := \
	src/mandatory/main.c \
	src/mandatory/fractol.c \
	src/mandatory/error_handling.c \
	src/mandatory/draw.c \
	src/mandatory/events.c \
	src/mandatory/map_pixel.c \
	src/mandatory/map_to_color.c \
	src/mandatory/utils.c \
	src/mandatory/utils2.c \
	src/mandatory/init.c

MAND_OBJS   := $(MAND_SRCS:.c=.o)

# ─ Common (shared) ──────────────────────────────────────────────
COMMON_SRCS := \
	src/mandatory/fractol.c \
	src/mandatory/error_handling.c \
	src/mandatory/draw.c \
	src/mandatory/map_pixel.c \
	src/mandatory/map_to_color.c \
	src/mandatory/utils.c \
	src/mandatory/utils2.c

COMMON_OBJS := $(COMMON_SRCS:.c=.o)

# ─ Bonus ────────────────────────────────────────────────────────
BONUS_SRCS  := \
	src/bonus/main_bonus.c \
	src/bonus/events_bonus.c \
	src/bonus/init_bonus.c

BONUS_OBJS  := $(BONUS_SRCS:.c=.o)

# ─ Targets ──────────────────────────────────────────────────────

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MAND_OBJS)
	$(CC) $(CFLAGS) $(INCS) $^ -o $@ $(MLX_FLAGS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCS) $^ -o $@ $(MLX_FLAGS)

# compile any .c → .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(MAND_OBJS) $(COMMON_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.SECONDARY: $(MAND_OBJS) $(COMMON_OBJS) $(BONUS_OBJS)
