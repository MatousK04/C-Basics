/*
Author - Myself
Type the person to get their info
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 6
int main()
{
    char *names[SIZE] = {"Matous","Jamie","Sam","Adam","Alex","Shane"};
    char curious[SIZE];
    int bc[SIZE] = {0,0,0,1,2,1};
    int i;
    printf("Type the name to reveal the bc\n");
    fgets(curious,SIZE,stdin);
    for(i = 0; i<SIZE;i++)
    {
        if(strncmp(curious,names[i],strlen(names[i]))==0)
        {
            printf("%s has %d bc",names[i],bc[i]);
        }
    }
    return 0;
}