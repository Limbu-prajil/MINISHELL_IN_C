#include "../../includes/executor.h"

int builtin_echo(char **args)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    if (!args || i || newline)
        printf("hello\n");
    printf("hello\n");
    /* return (1);
    return 0; */
    return 1;
}

int is_builtin(const char *cmd)
{
    if (isstrequal(cmd, "echo") 
    || isstrequal(cmd, "cd") 
    || isstrequal(cmd, "pwd") 
    || isstrequal(cmd, "export") 
    || isstrequal(cmd, "unset")
    || isstrequal(cmd, "env")
    || isstrequal(cmd, "exit"))
        return (1);
    else
        return (0);
}

int execute_builtin(t_ast *node)
{
    char **args;
    
    args = node->args;
    if (isstrequal(args[0], "echo"))
        return builtin_echo(args);
    /* else if (isstrequal(args[0], "cd"))
        return builtin_cd(args);
    else if (isstrequal(args[0], "pwd"))
        return builtin_pwd(args);
    else if (isstrequal(args[0], "export"))
        return builtin_export(args);
    else if (isstrequal(args[0], "unset"))
        return builtin_unset(args);
    else if (isstrequal(args[0], "env"))
        return builtin_env(args);
    else if (isstrequal(args[0], "exit"))
        return builtin_exit(args); */
    return (1);
}
void execute_ast(t_ast *ast)
{
    if (!ast)
        return ;
    if (ast->type == NODE_COMMAND)
    {
        if (!ast->args || !ast->args[0])
            return ;
        if (is_builtin(ast->args[0]))
        {
            printf("yes inbuilt\n");
            execute_builtin(ast);
        }
        else
            return ;//execute_command(ast);
    }
}