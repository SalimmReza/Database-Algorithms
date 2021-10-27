#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char output)
{
    if(top >= SIZE-1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top+1;
        stack[top] = output;///array r o no position e jeita thake oita output hiseb e ber hobe
    }
}

char pop()
{
    char output;

    if(top <0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();///return null value.
        exit(1);
    }
    else
    {
        output= stack[top];
        top = top-1;
        return(output);
    }
}

int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if(symbol == '^')
    {
        return(3);
    }
    else if(symbol == '*' || symbol == '/')
    {
        return(2);
    }
    else if(symbol == '+' || symbol == '-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i=0, j=0;
    char output;
    char x;

    push('(');                               /// push '(' onto stack
    strcat(infix_exp,")");                   ///add ')' to infix expression ///2 ta string ek sathe add kore.

    output=infix_exp[i];         /// initialize before loop

    while(output!= '\0')        /// run loop till end of infix expression
    {
        if(output== '(')
        {
            push(output);
        }
        else if( isdigit(output) || isalpha(output))
        {
            postfix_exp[j] = output;              ///add operand symbol to postfix expr
            j++;
        }
        else if(is_operator(output) == 1)        /// means plus minus gun vaag ^ ///==1 means upore ase mane return 1.
        {
            x=pop();                           ///stack's top is popped for checking
            while(is_operator(x) == 1 && precedence(x)>= precedence(output))
            {
                postfix_exp[j] = x;                  ///so pop all higher precendence operator and
                j++;
                x = pop();                       ///stack's new top is popped
            }
            push(x);                  ///if not matched, the top is pushed back to stack

            push(output);                 /// push current operator symbol onto stack
        }
        else if(output== ')')         /// if current symbol is ')' then
        {
            x = pop();                   /// pop and keep popping until
            while(x != '(')                ///'(' encounterd
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            /* if current symbol is neither operand not '(' nor ')' and nor
            operator */
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;

        output= infix_exp[i]; ///go to next symbol of infix expression
    } /// while loop ends here
    if(top>0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0';
}

int main()
{

    char infix[SIZE], postfix[SIZE];
    printf("\nEnter Infix expression : ");
    gets(infix);

    InfixToPostfix(infix,postfix);
    printf("Postfix Expression: ");
    puts(postfix);                      ///print postfix expression
    char *e;
    e=postfix;
    int n1,n2,n3,num;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            case '^':
            {
                n3 = n2 ^ n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }

    return 0;
}

