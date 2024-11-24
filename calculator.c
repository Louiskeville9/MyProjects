/* Simple calculator program*/


#include <stdio.h>

//Function signature
float calculator(float, float, char);


int main()
{
    //Variables
    float num1;
    float num2;
    char oper;
    float answer = 0;

    //Prompt user
    printf("Please enter a simple math problem below:\n");

    //Get inputs
    scanf("%f %c %f", &num1, &oper, &num2);

    //Call calculator function passing user input
    answer = calculator(num1, num2, oper);

    //Print answer
    printf("Answer: %.2f", answer);

    return 0;
}

//Calculator function
float calculator(float num1, float num2, char oper)
{
    //Variables
    float answer1 = 0;

    //Switch statement to handle arithmetic logic
    switch(oper)
    {
        //Addition
        case '+':
        {
            answer1 = num1 + num2;

            break;
        }

        //Subtraction
        case '-':
        {
            answer1 = num1 - num2;

            break;
        }

        //Division
        case '/':
        {
            answer1 = num1 / num2;

            break;
        }

        //Remainder
        case '%':
        {
            answer1 = fmod(num1, num2); //Return float remainder

            break;
        }

        //Multiplication
        case '*':
        case 'x':
        {
            answer1 = num1 * num2;

            break;
        }

        //If operator not recognized
        default:
        {
            printf("\n\n\n.........Invalid operator please restart.........\n\n\n");

            return 0;
        }

    }

    //Return answer to main
    return answer1;
}
