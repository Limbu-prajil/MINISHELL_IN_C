#include "../includes/minishell.h"
#include "../includes/tokenizer.h"
#include "../includes/parser.h"

static char *handle_input(void)
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
        printf("minishell: syntax error: unclosed quote\n");
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
    /*
    t_token *curr = tokens;
    while (curr)
    {
        printf("Token: type=%d, value='%s'\n", curr->type, curr->value);
        curr = curr->next;
    }
    */
    t_ast *ast = parse_tokens(tokens);
    if (ast)
    {
        print_ast(ast, 0);  // 🖨️ Print the AST structure here
        // (Later you'll execute AST here)
    }
    free_tokens(tokens);
    return (input);
}
void    minishell_loop(void)
{
    char *line;

    while(1)
    {
        line = handle_input();
        if (!line)
            continue ;
        free(line);
    }
}
