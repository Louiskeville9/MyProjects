#include <stdio.h>

int calculator(int, int, char);

int main()
{
    int num1;
    int num2;
    char oper;
    int answer = 0;

    printf("Please enter a simple math problem below:\n");

    scanf("%d %c %d", &num1, &oper, &num2);

    answer = calculator(num1, num2, oper);

    printf("Answer: %d", answer);

    return 0;
}

int calculator(int num1, int num2, char oper)
{
    int answer1 = 0;

    switch(oper)
    {
        case '+':
        {
            answer1 = num1 + num2;

            break;
        }

        case '-':
        {
            answer1 = num1 - num2;

            break;
        }

        case '/':
        case '%':
        {
            answer1 = num1 / num2;

            break;
        }

        case '*':
        case 'x':
        {
            answer1 = num1 * num2;

            break;
        }

        default:
        {
            printf("\n\n\n.........Invalid operator please restart.........\n\n\n");

            return 0;
        }

    }

    return answer1;
}