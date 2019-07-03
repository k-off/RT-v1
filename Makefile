#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                  #
#    Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = RTv1
SRCS = main.c norm.c \
events/events.c events/keyboard.c events/threads.c \
meth/cone.c meth/cylinder.c meth/math.c meth/plane.c meth/sphere.c \
output/errors.c output/menu.c output/put_images.c output/time.c \
parser/parser_camera.c parser/parser_general.c parser/parser_lights.c \
parser/parser_objects.c parser/parser_tags_check.c parser/parser_utils1.c \
parser/parser_utils2.c parser/parser.c \
setnew/set_new.c setnew/set_rays.c \
tracer/get_images.c tracer/lights_shadows.c tracer/trace_rays.c \
tracer/trace_rays2.c
MKOBJ = @gcc -c -Wall -Wextra -Werror
HDRS = -I ./includes
OBJS = main.o norm.o \
events.o keyboard.o threads.o \
cone.o cylinder.o math.o plane.o sphere.o \
errors.o menu.o put_images.o time.o \
parser_camera.o parser_general.o parser_lights.o \
parser_objects.o parser_tags_check.o parser_utils1.o \
parser_utils2.o parser.o \
set_new.o set_rays.o \
get_images.o lights_shadows.o trace_rays.o \
trace_rays2.o
MLX = -L libmlx/ -lmlx -framework OpenGL -framework AppKit
LFT = -L libft -lft
LVC = -L libvec/ -lvec
MKEXE = @gcc -o

all: $(NAME)
$(NAME):
	@make -C libft
	@make -C libmlx
	@make -C libvec
	$(MKOBJ) $(SRCS) $(HDRS)
	$(MKEXE) $(NAME) $(OBJS) $(MLX) $(LFT) $(LVC)

clean:
	@make -C libft clean
	@make -C libmlx clean
	@make -C libvec clean
	@rm -f $(OBJS) *~

fclean: clean
	@make -C libft fclean
	@make -C libmlx clean
	@make -C libvec fclean
	@rm -f $(NAME)

re: fclean all
