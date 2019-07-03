#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/13 11:11:47 by pacovali      #+#    #+#                  #
#    Updated: 2019/01/19 19:16:26 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libvec.a
SRCS = deg_to_rad.c rad_to_deg.c v2_a_to_b.c v2_add.c v2_angle_deg.c v2_dot.c \
v2_isequal.c v2_isnull.c v2_len.c v2_new_null.c v2_new_val.c v2_norm.c \
v2_reflect.c v2_reflectance.c v2_refract.c v2_rotate.c v2_sub.c v2_to_len.c \
v2_x_num.c v2_x_v2.c v3_a_to_b.c v2_negate.c\
v3_add.c v3_angle_deg.c v3_angle_rad.c v3_cross.c v3_distance.c \
v3_dot.c v3_isequal.c v3_isnull.c v3_len.c v3_new_null.c v3_new_val.c \
v3_norm.c v3_reflect.c v3_reflectance.c v3_refract.c v3_rotate_xyz.c \
v3_rotate_zyx.c v3_sub.c v3_to_len.c v3_x_num.c v3_x_v3.c v3_negate.c \
v3_rotate_x.c v3_rotate_y.c v3_rotate_z.c
MKOBJ = @gcc -c -Wall -Wextra -Werror
HDRS = -I .
OBJS = deg_to_rad.o rad_to_deg.o v2_a_to_b.o v2_add.o v2_angle_deg.o v2_dot.o \
v2_isequal.o v2_isnull.o v2_len.o v2_new_null.o v2_new_val.o v2_norm.o \
v2_reflect.o v2_reflectance.o v2_refract.o v2_rotate.o v2_sub.o v2_to_len.o \
v2_x_num.o v2_x_v2.o v3_a_to_b.o v2_negate.o\
v3_add.o v3_angle_deg.o v3_angle_rad.o v3_cross.o v3_distance.o \
v3_dot.o v3_isequal.o v3_isnull.o v3_len.o v3_new_null.o v3_new_val.o \
v3_norm.o v3_reflect.o v3_reflectance.o v3_refract.o v3_rotate_xyz.o \
v3_rotate_zyx.o v3_sub.o v3_to_len.o v3_x_num.o v3_x_v3.o v3_negate.o \
v3_rotate_x.o v3_rotate_y.o v3_rotate_z.o
MKLIB = @ar -rc

all: $(NAME)
$(NAME):
	$(MKOBJ) $(SRCS) $(HDRS)
	$(MKLIB) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) *~

fclean: clean
	@rm -f $(NAME)

re: fclean all