//Program to perform basic operations in stack in c

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1;
void push(int item);
int pop();
int peek();
int isempty();
int isfull();
void display();

void main()
{
    int choice, item;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display all the top elements\n");
        printf("4.Display all the stack elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to be pushed : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            break;
        case 3:
            printf("\nItem at the top is %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice!\n");
        }
    }
}
void push(int item)
{
    if (isfull())
    {
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}
int pop()
{
    if (isempty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    int item = stack[top];
    top = top - 1;
    return item;
}
int peek()
{
    if (isempty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top];
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top == MAX)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if (isempty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack elements are :\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
    printf("\n");
}
