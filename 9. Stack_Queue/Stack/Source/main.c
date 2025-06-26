#include <stack.h>

int main()
{
    Stack stack1;

    init(&stack1, 5);

    printf("Push Process...\n");
    for (int i = 1; i <= stack1.size; ++i)
    {
        push(&stack1, i * 5);
    }

    printf("\n");

    printf("Print Elements...\n");

    for (int i = 0; i < stack1.size; ++i)
    {
        printf("Element: %d - Address: %d - Value: %d\n", i + 1, &(stack1.item[i]), stack1.item[i]);
    }

    printf("\n");

    printf("Pop Process...");

    for (int i = 0; i < stack1.size; i++)
    {
        printf("Element: %d - Address: %d - Value: %d\n", i + 1, &(stack1.item[stack1.top]), stack1.item[stack1.top]);
        pop(&stack1);
    }

    return 0;
}