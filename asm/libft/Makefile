# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlarson <hlarson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 16:48:42 by hlarson           #+#    #+#              #
#    Updated: 2019/09/05 10:51:58 by sgarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./sourse/libft.a

CC=gcc

CFLAGS= -c -Wall -Wextra -Werror

FLAG_PATH_OBJ= -o $@

PATH_S=./obj/

OBJECT = buf_right_alignment.o buffer.o buffer_2.o count_numbers.o ft_atoi.o \
ft_atoi_precision.o ft_atoi_width.o ft_bzero.o ft_char.o ft_color_print.o \
ft_count_until.o ft_create_str.o ft_float.o ft_help_with_precision.o ft_hex.o \
ft_int.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
ft_itoa.o ft_long_composition.o ft_long_composition_dot.o ft_long_division.o \
ft_long_double.o ft_long_pow.o ft_long_pow_minus.o ft_long_sum.o ft_long_sum_dot.o \
ft_make_precision.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memdel.o ft_memmove.o ft_memset.o ft_minus_str.o ft_newtrim.o ft_octal.o ft_one.o \
ft_point.o ft_printf.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_remake_str.o ft_size.o \
ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o \
ft_strnew.o ft_strnew_one.o ft_strnew_zero.o ft_strnstr.o ft_strrchr.o ft_strrjoin.o \
ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o \
ft_type_e.o ft_type_e_l.o ft_unsigned_int.o ft_zero.o get_after_dot_float.o \
get_before_dot_float.o get_next_line.o inicialization.o long_world.o norm_buffer.o \
parser.o parser_flag.o parser_size.o parser_type.o print_percent.o print_w_flag.o \
quantity_world.o reinicialization.o until_per.o what_print.o world.o \
gnl_clist_del_node.o gnl_clist_find_prev.o gnl_clist_insert.o gnl_clist_new.o \
gnl_strmerge.o

PATH_SRC = $(patsubst %.o, $(PATH_S)%.o, $(OBJECT))

all: $(NAME)

$(NAME): $(PATH_SRC)
	@ar rc $(NAME) $(PATH_SRC)
	@echo "\r\033[K\033[34mLIBFT COMPILED\033[0m"

$(PATH_S)gnl_strmerge.o: gnl_strmerge.c
	@$(CC) $(CFLAGS) gnl_strmerge.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)gnl_clist_new.o: gnl_clist_new.c
	@$(CC) $(CFLAGS) gnl_clist_new.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)gnl_clist_insert.o: gnl_clist_insert.c
	@$(CC) $(CFLAGS) gnl_clist_insert.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)gnl_clist_find_prev.o: gnl_clist_find_prev.c
	@$(CC) $(CFLAGS) gnl_clist_find_prev.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)gnl_clist_del_node.o: gnl_clist_del_node.c
	@$(CC) $(CFLAGS) gnl_clist_del_node.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)buf_right_alignment.o: buf_right_alignment.c
	@$(CC) $(CFLAGS) buf_right_alignment.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)buffer.o: buffer.c
	@$(CC) $(CFLAGS) buffer.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)buffer_2.o: buffer_2.c
	@$(CC) $(CFLAGS) buffer_2.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)count_numbers.o: count_numbers.c
	@$(CC) $(CFLAGS) count_numbers.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_atoi.o: ft_atoi.c
	@$(CC) $(CFLAGS) ft_atoi.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_atoi_precision.o: ft_atoi_precision.c
	@$(CC) $(CFLAGS) ft_atoi_precision.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_atoi_width.o: ft_atoi_width.c
	@$(CC) $(CFLAGS) ft_atoi_width.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_bzero.o: ft_bzero.c
	@$(CC) $(CFLAGS) ft_bzero.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_char.o: ft_char.c
	@$(CC) $(CFLAGS) ft_char.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_color_print.o: ft_color_print.c
	@$(CC) $(CFLAGS) ft_color_print.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_count_until.o: ft_count_until.c
	@$(CC) $(CFLAGS) ft_count_until.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_create_str.o: ft_create_str.c
	@$(CC) $(CFLAGS) ft_create_str.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_float.o: ft_float.c
	@$(CC) $(CFLAGS) ft_float.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_help_with_precision.o: ft_help_with_precision.c
	@$(CC) $(CFLAGS) ft_help_with_precision.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_hex.o: ft_hex.c
	@$(CC) $(CFLAGS) ft_hex.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_int.o: ft_int.c
	@$(CC) $(CFLAGS) ft_int.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_isalnum.o: ft_isalnum.c
	@$(CC) $(CFLAGS) ft_isalnum.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_isalpha.o: ft_isalpha.c
	@$(CC) $(CFLAGS) ft_isalpha.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_isascii.o: ft_isascii.c
	@$(CC) $(CFLAGS) ft_isascii.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_isdigit.o: ft_isdigit.c
	@$(CC) $(CFLAGS) ft_isdigit.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_isprint.o: ft_isprint.c
	@$(CC) $(CFLAGS) ft_isprint.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_itoa.o: ft_itoa.c
	@$(CC) $(CFLAGS) ft_itoa.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_composition.o: ft_long_composition.c
	@$(CC) $(CFLAGS) ft_long_composition.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_composition_dot.o: ft_long_composition_dot.c
	@$(CC) $(CFLAGS) ft_long_composition_dot.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_division.o: ft_long_division.c
	@$(CC) $(CFLAGS) ft_long_division.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_double.o: ft_long_double.c
	@$(CC) $(CFLAGS) ft_long_double.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_pow.o: ft_long_pow.c
	@$(CC) $(CFLAGS) ft_long_pow.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_pow_minus.o: ft_long_pow_minus.c
	@$(CC) $(CFLAGS) ft_long_pow_minus.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_sum.o: ft_long_sum.c
	@$(CC) $(CFLAGS) ft_long_sum.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_long_sum_dot.o: ft_long_sum_dot.c
	@$(CC) $(CFLAGS) ft_long_sum_dot.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_make_precision.o: ft_make_precision.c
	@$(CC) $(CFLAGS) ft_make_precision.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memalloc.o: ft_memalloc.c
	@$(CC) $(CFLAGS) ft_memalloc.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memccpy.o: ft_memccpy.c
	@$(CC) $(CFLAGS) ft_memccpy.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memchr.o: ft_memchr.c
	@$(CC) $(CFLAGS) ft_memchr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memcmp.o: ft_memcmp.c
	@$(CC) $(CFLAGS) ft_memcmp.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memcpy.o: ft_memcpy.c
	@$(CC) $(CFLAGS) ft_memcpy.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memdel.o: ft_memdel.c
	@$(CC) $(CFLAGS) ft_memdel.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memmove.o: ft_memmove.c
	@$(CC) $(CFLAGS) ft_memmove.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_memset.o: ft_memset.c
	@$(CC) $(CFLAGS) ft_memset.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_minus_str.o: ft_minus_str.c
	@$(CC) $(CFLAGS) ft_minus_str.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_newtrim.o: ft_newtrim.c
	@$(CC) $(CFLAGS) ft_newtrim.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_octal.o: ft_octal.c
	@$(CC) $(CFLAGS) ft_octal.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_one.o: ft_one.c
	@$(CC) $(CFLAGS) ft_one.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_point.o: ft_point.c
	@$(CC) $(CFLAGS) ft_point.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_printf.o: ft_printf.c
	@$(CC) $(CFLAGS) ft_printf.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putchar.o: ft_putchar.c
	@$(CC) $(CFLAGS) ft_putchar.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putchar_fd.o: ft_putchar_fd.c
	@$(CC) $(CFLAGS) ft_putchar_fd.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putendl.o: ft_putendl.c
	@$(CC) $(CFLAGS) ft_putendl.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putendl_fd.o: ft_putendl_fd.c
	@$(CC) $(CFLAGS) ft_putendl_fd.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putnbr.o: ft_putnbr.c
	@$(CC) $(CFLAGS) ft_putnbr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putnbr_fd.o: ft_putnbr_fd.c
	@$(CC) $(CFLAGS) ft_putnbr_fd.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putstr.o: ft_putstr.c
	@$(CC) $(CFLAGS) ft_putstr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_putstr_fd.o: ft_putstr_fd.c
	@$(CC) $(CFLAGS) ft_putstr_fd.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_remake_str.o: ft_remake_str.c
	@$(CC) $(CFLAGS) ft_remake_str.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_size.o: ft_size.c
	@$(CC) $(CFLAGS) ft_size.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strcat.o: ft_strcat.c
	@$(CC) $(CFLAGS) ft_strcat.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strchr.o: ft_strchr.c
	@$(CC) $(CFLAGS) ft_strchr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strclr.o: ft_strclr.c
	@$(CC) $(CFLAGS) ft_strclr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strcmp.o: ft_strcmp.c
	@$(CC) $(CFLAGS) ft_strcmp.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strcpy.o: ft_strcpy.c
	@$(CC) $(CFLAGS) ft_strcpy.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strdel.o: ft_strdel.c
	@$(CC) $(CFLAGS) ft_strdel.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strdup.o: ft_strdup.c
	@$(CC) $(CFLAGS) ft_strdup.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strequ.o: ft_strequ.c
	@$(CC) $(CFLAGS) ft_strequ.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_striter.o: ft_striter.c
	@$(CC) $(CFLAGS) ft_striter.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_striteri.o: ft_striteri.c
	@$(CC) $(CFLAGS) ft_striteri.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strjoin.o: ft_strjoin.c
	@$(CC) $(CFLAGS) ft_strjoin.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strlcat.o: ft_strlcat.c
	@$(CC) $(CFLAGS) ft_strlcat.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strlen.o: ft_strlen.c
	@$(CC) $(CFLAGS) ft_strlen.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strmap.o: ft_strmap.c
	@$(CC) $(CFLAGS) ft_strmap.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strmapi.o: ft_strmapi.c
	@$(CC) $(CFLAGS) ft_strmapi.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strncat.o: ft_strncat.c
	@$(CC) $(CFLAGS) ft_strncat.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strncmp.o: ft_strncmp.c
	@$(CC) $(CFLAGS) ft_strncmp.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strncpy.o: ft_strncpy.c
	@$(CC) $(CFLAGS) ft_strncpy.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strnequ.o: ft_strnequ.c
	@$(CC) $(CFLAGS) ft_strnequ.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strnew.o: ft_strnew.c
	@$(CC) $(CFLAGS) ft_strnew.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strnew_one.o: ft_strnew_one.c
	@$(CC) $(CFLAGS) ft_strnew_one.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strnew_zero.o: ft_strnew_zero.c
	@$(CC) $(CFLAGS) ft_strnew_zero.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strnstr.o: ft_strnstr.c
	@$(CC) $(CFLAGS) ft_strnstr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strrchr.o: ft_strrchr.c
	@$(CC) $(CFLAGS) ft_strrchr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strrjoin.o: ft_strrjoin.c
	@$(CC) $(CFLAGS) ft_strrjoin.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strsplit.o: ft_strsplit.c
	@$(CC) $(CFLAGS) ft_strsplit.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strstr.o: ft_strstr.c
	@$(CC) $(CFLAGS) ft_strstr.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strsub.o: ft_strsub.c
	@$(CC) $(CFLAGS) ft_strsub.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_strtrim.o: ft_strtrim.c
	@$(CC) $(CFLAGS) ft_strtrim.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_tolower.o: ft_tolower.c
	@$(CC) $(CFLAGS) ft_tolower.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_toupper.o: ft_toupper.c
	@$(CC) $(CFLAGS) ft_toupper.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_type_e.o: ft_type_e.c
	@$(CC) $(CFLAGS) ft_type_e.c $(FLAG_PATH_OBJ)  && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_type_e_l.o: ft_type_e_l.c
	@$(CC) $(CFLAGS) ft_type_e_l.c $(FLAG_PATH_OBJ)  && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_unsigned_int.o: ft_unsigned_int.c
	@$(CC) $(CFLAGS) ft_unsigned_int.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)ft_zero.o: ft_zero.c
	@$(CC) $(CFLAGS) ft_zero.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)get_after_dot_float.o: get_after_dot_float.c
	@$(CC) $(CFLAGS) get_after_dot_float.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)get_before_dot_float.o: get_before_dot_float.c
	@$(CC) $(CFLAGS) get_before_dot_float.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)get_next_line.o: get_next_line.c
	@$(CC) $(CFLAGS) get_next_line.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)inicialization.o: inicialization.c
	@$(CC) $(CFLAGS) inicialization.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)long_world.o: long_world.c
	@$(CC) $(CFLAGS) long_world.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)norm_buffer.o: norm_buffer.c
	@$(CC) $(CFLAGS) norm_buffer.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parser.o: parser.c
	@$(CC) $(CFLAGS) parser.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parser_flag.o: parser_flag.c
	@$(CC) $(CFLAGS) parser_flag.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parser_size.o: parser_size.c
	@$(CC) $(CFLAGS) parser_size.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parser_type.o: parser_type.c
	@$(CC) $(CFLAGS) parser_type.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)print_percent.o: print_percent.c
	@$(CC) $(CFLAGS) print_percent.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)print_w_flag.o: print_w_flag.c
	@$(CC) $(CFLAGS) print_w_flag.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)quantity_world.o: quantity_world.c
	@$(CC) $(CFLAGS) quantity_world.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)reinicialization.o: reinicialization.c
	@$(CC) $(CFLAGS) reinicialization.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)until_per.o: until_per.c
	@$(CC) $(CFLAGS) until_per.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)what_print.o: what_print.c
	@$(CC) $(CFLAGS) what_print.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)world.o: world.c
	@$(CC) $(CFLAGS) world.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
clean:
	@rm -f $(PATH_SRC)
fclean: clean
	@rm -f $(NAME)
re: fclean
	@make all
