/*Program to calculate the area of a circle and a square whose measurements are inputs from the user,
2 functions will be called to preform this task

Author: Louis K  Date: 13/02/2024 */

#include <stdio.h>


//Function signatures
int circleArea(int);
int squareArea(int);

int main()
{
    int length;
    int radius;
    int area_circle;
    int area_square;

    //Prompt and get user input
    printf("please enter the length of the square(cm):\n");
    scanf("%d", &length);

    printf("please enter the radius of the circle(cm)\n");
    scanf("%d", &radius);

    //Call functions
    area_circle = circleArea(radius);
    area_square = squareArea(length);

    //Print answers
    printf("Area of square = %dcm\n", area_square);

    printf("Area of circle = %dcm\n", area_circle);

    return 0;
}

//Circle function
int circleArea(radius)
{
    int answer1;

    answer1 = 3.14 * (radius * radius);

    return answer1;
}

//Square function
int squareArea(length)
{
    int answer2;

    answer2 = length * length;

    return answer2;
}