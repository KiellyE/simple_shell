#ifndef _KELLY_
#define _KELLY_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFSIZE15 1024
#define TOK_BUFSIZE15 128
#define TOK_DELIM15 " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data15 - struct that contains all relevant data
 * @av15: argument vecTOR
 * @input15: command line written by the user
 * @args15: tokens of the command line
 * @status15: last status of the shell
 * @counter15: lines counter-
 * @_environ15: environment variable_Z
 * @pidI15: process ID of the shell_0
 */
typedef struct data15
{
	char **av15;
	char *input15;
	char **args15;
	int status15;
	int counter15;
	char **_environ15;
	char *pid15;
} data_shell_15;

/**
 * struct sep_list_s15 - single linked list
 * @separator15: ; | &
 * @next15: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s15
{
	char separator15;
	struct sep_list_s15 *next;
} sep_list15;

/**

 * struct line_list_s15 - single linked list
 * @line15: command line
 * @next15: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s15
{
	char *line;
	struct line_list_s15 *next;
} line_list15;

/**
 * struct r_var_list15 - single linked list
 * @len_15: length of the variable
 * @value: value of the variable
 * @len_val15: length of the value
 * @next: next node_
 * Description: single linked list to store variables
 */
typedef struct r_var_list15
{
	int len_15;
	char *value;
	int len_val;
	struct r_var_list15 *next;
} r_var15;

/**
 * struct builtin_s15 - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f25: data type pointer function.
 */
typedef struct builtin_s15
{
	char *name;
	int (*f25)(data_shell_15 *datash_Mogale);
} builtin_t15;

/* aux_lists.c */
sep_list15 *add_sep_node_end(sep_list15 **head, char sep);
void free_sep_list(sep_list15 **head);
line_list15 *add_line_node_end(line_list15 **head, char *line);
void free_line_list(line_list15 **head);

/* aux_lists2.c */
r_var15 *add_rvar_node(r_var15 **head, int lvar, char *var, int lval);
void free_rvar_list(r_var15 **head);

/* aux_str functions */
char *strca_t(char *destination, const char *source);	
char *strcp_y(char *destination, char *source);
int strcm_p(char *string1, char *string2);
char *strch_r(char *s, char c);
int strsp_n(char *s, char *accept);

/* aux_mem.c */
void memcpy15(void *newptr15, const void *ptr15, unsigned int size15);
void *realloc15(void *ptr15, unsigned int old_size15, unsigned int new_size15);
char **reallocdp15(char **ptr15, unsigned int old_size15, unsigned int new_size15);

/* aux_str2.c */
char *strdup15(const char *s);
int strlen15(const char *s);
int cmp_chars15(char str[], const char *delim);
char *strtok15(char str[], const char *delim);
int _isdigit15(const char *s);

/* aux_str3.c */
void rev_string(char *s);

/* check_syntax_error.c */
int repeated_char(char *input15, int m);
int error_sep_op(char *input15, int m, char last);
int first_char(char *input15, int *m);
void print_syntax_error(data_shell_15 *datash_mogale, char *input15, int m, int bool);
int check_syntax_error(data_shell_15 *datash_mogale, char *input15);

/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(data_shell_15 *datash_mogale);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_char(char *input15, int bool);
void add_nodes(sep_list15 **head_s, line_list15 **head_l, char *input15);
void go_next(sep_list15 **list_s, line_list15 **list_l, data_shell_15 *datash_mogale);
int split_commands(data_shell_15 *datash_mogale, char *input15);
char **split_line(char *input15);

/* rep_var.c */
void check_env(r_var15 **h, char *in, data_shell_15 *data);
int check_vars(r_var15 **h, char *in, char *st, data_shell_15 *data);
char *replaced_input(r_var15 **head, char *input15, char *new_input, int nlen);
char *rep_var(char *input15, data_shell_15 *datash_mogale);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line(data_shell_15 *datash_mogale);

/* cmd_exec.c */
int is_cdir(char *path15, int *m);
char *_which(char *cmd15, char **_environ15);
int is_executable(data_shell_15 *datash_mogale);
int check_error_cmd(char *dir, data_shell_15 *datash_mogale);
int cmd_exec(data_shell_15 *datash_mogale);

/* env1.c */
char *_getenv(const char *name, char **_environ15);
int _env(data_shell_15 *datash_mogale);

/* env2.c */
char *copy_info(char *name, char *value15);
void set_env(char *name, char *value15, data_shell_15 *datash_mogale);
int _setenv(data_shell_15 *datash_mogale);
int _unsetenv(data_shell_15 *datash_mogale);

/* cd.c */
void cd_dot(data_shell_15 *datash_mogale);
void cd_to(data_shell_15 *datash_mogale);
void cd_previous(data_shell_15 *datash_mogale);
void cd_to_home(data_shell_15 *datash_mogale);

/* cd_shell.c */
int cd_shell(data_shell_15 *datash_mogale);

/* get_builtin */
int (*get_builtin(char *cmd15))(data_shell_15 *datash_mogale);

/* _exit.c */
int exit_shell(data_shell_15 *datash_mogale);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* aux_error1.c */
char *strcat_cd(data_shell_15 *, char *, char *, char *);
char *error_get_cd(data_shell_15 *datash_mogale);
char *error_not_found(data_shell_15 *datash_mogale);
char *error_exit_shell(data_shell_15 *datash_mogale);

/* aux_error2.c */
char *error_get_alias(char **args15);
char *error_env(data_shell_15 *datash_mogale);
char *error_syntax(char **args15);
char *error_permission(char **args15);
char *error_path_126(data_shell_15 *datash_mogale);


/* get_error.c */
int get_error(data_shell_15 *datash_mogale, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/* aux_help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* aux_help2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(data_shell_15 *datash_mogale);

#endif
