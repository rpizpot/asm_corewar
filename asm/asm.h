/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpizpot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:57:02 by rpizpot           #+#    #+#             */
/*   Updated: 2019/08/23 18:57:02 by rpizpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ASM_H
#define ASM_ASM_H

#include "op.h"

#define COR_LIVE	"live"
#define COR_LB		"lb"
#define COR_ST		"st"
#define COR_ADD		"add"
#define COR_SUB		"sub"
#define COR_AND		"and"
#define COR_OR		"or"
#define COR_XOR		"xor"
#define COR_ZJMP	"zjmp"
#define COR_LDI		"ldi"
#define COR_STI		"sti"
#define COR_FORK	"fork"
#define COR_LLD		"lld"
#define COR_LLDI	"lldi"
#define COR_LFORK	"lfork"
#define COR_AFF		"aff"
#define BUFF_SIZE_ASM	1000

typedef struct s_asm
{
	char			*one_line;
	uint8_t			line_num;
	struct s_asm	*next;
	struct s_asm	*previous;
}					t_asm;

typedef struct			s_arg
{
	int					size;
	int 				arg_type;
	unsigned int		value;
	char				*name_label;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_link_asm
{
	char				*link_name;
	uint8_t				num_line;
	struct s_link_asm	*next;
	struct s_link_asm	*previous;
}						t_link_asm;

typedef struct			s_comand_asm
{
	char 				*comand;
	char 				*for_variables;
	t_arg				*arg;
	uint8_t				num_line;
	struct s_comand_asm	*next;
}						t_comand_asm;

typedef struct			s_op
{
	char				*name;
	int					codage;
	int					count_args;
	int					label_size;
	int					args[3];
	int					opcode;
	int					number_byte;
}						t_op;

t_op				g_operations[17];

typedef struct 		s_pars_asm
{
	char 			*name;
	char 			*comment;
	t_comand_asm	*comand_asm;
	t_link_asm		*link_asm;
}					t_pars_asm;

t_asm				*new_list_asm(char *line, int num_line);
t_asm				*add_alist_back(t_asm *old, t_asm *new);
int					read_cod_asm(int fd, t_asm **asm_list, int num_line);
void				inicializ_corewar(t_pars_asm *pars_asm);
char				*error_name(t_pars_asm *pars_asm, t_asm *asm_list);
char				*error_comment(t_pars_asm *pars_asm, t_asm *asm_list);
t_link_asm			*link_asm_new_list(char *line, uint8_t num_line, int len);
t_link_asm			*add_new_link_list(t_link_asm *old, t_link_asm *new);
t_comand_asm		*comand_asm_new_list(char *line, uint8_t num_line, char *for_va);
t_comand_asm		*add_new_comand_asm_list(t_comand_asm *old, t_comand_asm *new);
int					*check_valid_comand(char *comand);
void				parse_one_line(t_pars_asm *pars_asm, t_asm *asm_list, char *check);
void				parse_variables(t_pars_asm *pars_asm);
char				**str_split_arg(char *str);
t_arg				*add_arg_back(t_arg *old, t_arg *new);

#endif
