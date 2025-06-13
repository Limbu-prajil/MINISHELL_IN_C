#ifndef EXECUTOR_H
# define EXECUTOR_H


#include "minishell.h"
#include "parser.h"


void execute_ast(t_ast *ast);

int execute_command(t_ast *node);


int is_builtin(const char *cmd);
int execute_builtin(t_ast *node);

void    setup_signalhandler(void);

#endif