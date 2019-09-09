# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarry <sgarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 12:19:14 by sgarry            #+#    #+#              #
#    Updated: 2019/09/04 17:59:09 by sgarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

LDIR = ./libft/

PATH_S = ./obj/

FLAG_PATH_OBJ = -o $@

LIBFT = @make -C $(LDIR)

INCLUDES = ./includes/

SRC = ./source/

OBJECT = add_alist_back.o \
		add_arg_back.o \
		add_new_comand_asm_list.o \
		add_new_link_list.o \
		check_valid_comand.o \
		comand_asm_new_list.o \
		error_name_comment.o \
		free_parse_asm.o \
		inicializ_corewar.o \
		link_asm_new_list.o \
		main.o \
		new_list_asm.o \
		op.o \
		parse_one_line.o \
		parse_variables.o \
		read_cod_asm.o \
		replace.o \
		str_split_arg.o \
		tags_and_links.o \
		write_bytes.o \
		write_to_file.o \
		check_valid_link.o \
		free_all.o \
		free_asm_list.o \
		pars_arg.o \
		arg_t_dir.o \
		arg_t_ind.o \
		arg_t_reg.o

PATH_SRC = $(patsubst %.o, $(PATH_S)%.o, $(OBJECT))

all: LIB $(NAME)

LIB:
	$(LIBFT)

$(NAME): $(PATH_SRC)
	@$(CC) $(PATH_SRC) -o $(NAME) -I $(INCLUDES) -L $(LDIR)sourse -lft
	@echo "\r\033[K\033[36mASM COMPILED\033[m"

$(PATH_S)arg_t_ind.o: $(SRC)arg_t_ind.c
	@$(CC) $(CFLAGS) $(SRC)arg_t_ind.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)arg_t_reg.o: $(SRC)arg_t_reg.c
	@$(CC) $(CFLAGS) $(SRC)arg_t_reg.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)arg_t_dir.o: $(SRC)arg_t_dir.c
	@$(CC) $(CFLAGS) $(SRC)arg_t_dir.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)pars_arg.o: $(SRC)pars_arg.c
	@$(CC) $(CFLAGS) $(SRC)pars_arg.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)free_asm_list.o: $(SRC)free_asm_list.c
	@$(CC) $(CFLAGS) $(SRC)free_asm_list.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)add_alist_back.o: $(SRC)add_alist_back.c
	@$(CC) $(CFLAGS) $(SRC)add_alist_back.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)add_arg_back.o: $(SRC)add_arg_back.c
	@$(CC) $(CFLAGS) $(SRC)add_arg_back.c $(FLAG_PATH_OBJ)&& \
	echo "\033[32m§\033[m\c"
$(PATH_S)add_new_comand_asm_list.o: $(SRC)add_new_comand_asm_list.c
	@$(CC) $(CFLAGS) $(SRC)add_new_comand_asm_list.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)add_new_link_list.o: $(SRC)add_new_link_list.c
	@$(CC) $(CFLAGS) $(SRC)add_new_link_list.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)check_valid_comand.o: $(SRC)check_valid_comand.c
	@$(CC) $(CFLAGS) $(SRC)check_valid_comand.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)main.o: $(SRC)main.c
	@$(CC) $(CFLAGS) $(SRC)main.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)comand_asm_new_list.o: $(SRC)comand_asm_new_list.c
	@$(CC) $(CFLAGS) $(SRC)comand_asm_new_list.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)error_name_comment.o: $(SRC)error_name_comment.c
	@$(CC) $(CFLAGS) $(SRC)error_name_comment.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)free_parse_asm.o: $(SRC)free_parse_asm.c
	@$(CC) $(CFLAGS) $(SRC)free_parse_asm.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)inicializ_corewar.o: $(SRC)inicializ_corewar.c
	@$(CC) $(CFLAGS) $(SRC)inicializ_corewar.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)link_asm_new_list.o: $(SRC)link_asm_new_list.c
	@$(CC) $(CFLAGS) $(SRC)link_asm_new_list.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)new_list_asm.o: $(SRC)new_list_asm.c
	@$(CC) $(CFLAGS) $(SRC)new_list_asm.c $(FLAG_PATH_OBJ)&& \
	echo "\033[32m§\033[m\c"
$(PATH_S)op.o: $(SRC)op.c
	@$(CC) $(CFLAGS) $(SRC)op.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parse_one_line.o: $(SRC)parse_one_line.c
	@$(CC) $(CFLAGS) $(SRC)parse_one_line.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)parse_variables.o: $(SRC)parse_variables.c
	@$(CC) $(CFLAGS) $(SRC)parse_variables.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)read_cod_asm.o: $(SRC)read_cod_asm.c
	@$(CC) $(CFLAGS) $(SRC)read_cod_asm.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)replace.o: $(SRC)replace.c
	@$(CC) $(CFLAGS) $(SRC)replace.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)str_split_arg.o: $(SRC)str_split_arg.c
	@$(CC) $(CFLAGS) $(SRC)str_split_arg.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)tags_and_links.o: $(SRC)tags_and_links.c
	@$(CC) $(CFLAGS) $(SRC)tags_and_links.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)write_bytes.o: $(SRC)write_bytes.c
	@$(CC) $(CFLAGS) $(SRC)write_bytes.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)write_to_file.o: $(SRC)write_to_file.c
	@$(CC) $(CFLAGS) $(SRC)write_to_file.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)check_valid_link.o: $(SRC)check_valid_link.c
	@$(CC) $(CFLAGS) $(SRC)check_valid_link.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
$(PATH_S)free_all.o: $(SRC)free_all.c
	@$(CC) $(CFLAGS) $(SRC)free_all.c $(FLAG_PATH_OBJ) && \
	echo "\033[32m§\033[m\c"
clean:
	@make fclean -C $(LDIR) && \
	echo "\033[31mLIBFT DELITED\033[m"
	@rm -f $(PATH_SRC)
fclean: clean
	@rm -f $(NAME) && \
	echo "\033[31mASM DELITED\033[m"
re: fclean
	@echo "\033[31m---------------\033[m"
	@make all
