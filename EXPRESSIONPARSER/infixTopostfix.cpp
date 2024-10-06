#include <iostream>
#include <stack>

using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        if ((int(infix[i]) >= 'a' && int(infix[i]) <= 'z') || (int(infix[i]) >= 'A' && int(infix[i]) <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }

        else
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > s.top())
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                    {
                        char temp = s.top();
                        postfix += temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        char temp = s.top();
        postfix += temp;
        s.pop(); 
    }

    return postfix;
}

int main()
{

    string infix_expression, postfix_expression;
    cout << "Enter the infix expression :- ";
    cin >> infix_expression;
    stack<char> stack;
    cout << "INFIX EXPRESSION :- " << infix_expression << endl;
    postfix_expression = InfixToPostfix(stack, infix_expression);
    cout << endl
         << "POSTFIX EXPRESSION: " << postfix_expression;

    return 0;
}