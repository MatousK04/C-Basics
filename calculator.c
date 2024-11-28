#include<stdio.h>
int main()
{
    float num1;
    float num2;
    char oper;
    float answer = 0;
    printf("Welcome to the calculator, ask me anything!!\n");
    scanf("%f",&num1);
    scanf("%c",&oper);
    scanf("%f",&num2);
    switch(oper)
    {
        case '+':
        {
            answer = num1 + num2;
            printf("The answer to %.1f + %.1f is %.0f\n",num1,num2,answer);
            break;
        }
        case '-':
        {
            answer = num1 - num2;
            printf("The answer to %.1f - %.1f is %.0f\n",num1,num2,answer);
            break; //end of case
        }
        case '*':
        case 'x':
        case 'X':
        {
            answer = num1 * num2;
            printf("The answer to %.1f x %.1f is %.0f\n",num1,num2,answer);
            break; //end of case
        }
        case '/':
        {
            answer = num1 / num2;
            printf("The answer to %.1f divide by %.0f is %.1f\n",num1,num2,answer);
            break;
        } //end of case
        default:
        {
            printf("Incorrect operator inputted!");
        }
        



    } // end of switch

    return 0;
}