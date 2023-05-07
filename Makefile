CC			= cc
CFLAGS		= -Wextra -Wall -Werror
CLIENT		= client
SERVER		= server
# BONUS_NAME	= bonus

LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

CLIENT_SRC_PATH 	= client_srcs/
CLIENT_OBJ_PATH 	= client_obj/

SERVER_SRC_PATH 	= server_srcs/
SERVER_OBJ_PATH 	= server_obj/
# BONUS_SRC_PATH = ./fdf_bonus/srcs/
# BONUS_OBJ_PATH = ./fdf_bonus/obj/

CLIENT_SRC     =   main.c \


SERVER_SRC     =   main.c \

# BONUS_SRC	=	

SERVER_SRCS	= $(addprefix $(SERVER_SRC_PATH), $(SERVER))
CLIENT_SRCS	= $(addprefix $(CLIENT_SRC_PATH), $(CLIENT))
# BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC))
SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)
# BONUS_OBJ = $(BONUS_SRC:.c=.o)
SERVER_OBJS	= $(addprefix $(SERVER_OBJ_PATH), $(SERVER_OBJ))
CLIENT_OBJS	= $(addprefix $(CLIENT_OBJ_PATH), $(CLIENT_OBJ))
# BONUS_OBJS = $(addprefix $(BONUS_OBJ_PATH), $(BONUS_OBJ))

 all: $(SERVER_OBJ_PATH) $(CLIENT_OBJ_PATH) $(SERVER) $(CLIENT) $(BONUS_OBJ_PATH) $(BONUS_NAME)

$(SERVER_OBJ_PATH)%.o: $(SERVER_SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJ_PATH)%.o: $(CLIENT_SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(BONUS_OBJ_PATH)%.o: $(BONUS_SRC_PATH)%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 

$(SERVER_OBJ_PATH):
	mkdir $(SERVER_OBJ_PATH)

$(CLIENT_OBJ_PATH):
	mkdir $(CLIENT_OBJ_PATH)

# $(BONUS_OBJ_PATH):
# 	mkdir $(BONUS_OBJ_PATH)

$(SERVER): $(LIBFT) $(SERVER_OBJ_PATH) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_OBJ_PATH) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT)

# $(BONUS_NAME): $(LIBFT) $(BONUS_OBJ_PATH) $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(SERVER_OBJ_PATH)
	rm -rf $(CLIENT_OBJ_PATH)
	rm -rf $(BONUS_OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
