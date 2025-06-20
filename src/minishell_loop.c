#include "../includes/minishell.h"
#include "../includes/tokenizer.h"
#include "../includes/parser.h"
#include "../includes/executor.h"

static t_ast *handle_input(void)
{
    t_token *tokens;
    char *input = readline("minishell$ ");
    if (!input)
    {
        printf("exit\n");
        exit(0);
    }
    if (*input)
        add_history(input);
    tokens = tokenize(input);
    if (!tokens)
    {
        //printf("minishell: syntax error: unclosed quote\n");
        free(input);
        return (NULL);
    }
    if (is_syntax_error(tokens))
    {
        //free everything not just head token
        free_tokens(tokens);
        free(input);
        return NULL;
    }
    else
        printf("syntaxvalid, move to next part\n");
    
    t_token *curr = tokens;
    while (curr)
    {
        printf("Token: type=%d, value='%s'\n", curr->type, curr->value);
        curr = curr->next;
    }
   
    t_ast *ast = parse_tokens(tokens);
    free_tokens(tokens);
    return (ast);
}
void    minishell_loop(t_env *env_list)
{
    t_ast *ast;

    while(1)
    {
        ast = handle_input();
        if (!ast)
            continue ;
        if(ast)
        {
            print_ast(ast, 0);
            execute_ast(ast, &env_list);
            free_ast(ast);
        }
        //to do execute ast
        
    }
}
