#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int *array;
};

void push(struct stack * stack, int number){
    stack->array[++stack->top] = number;
}

int pop(struct stack * stack){
    return stack->array[stack->top--];
}

int isEmpty(struct stack * stack){
    return (stack->top == -1 || !stack);
}

int main(int argc, char* argv[]) {
    printf("\n Double Stack Sort : \n");
    int n = argc - 1;

    int *array;
    if((array = (int *)calloc(n, sizeof(int))) == NULL) {
        printf(" Memory error ! \n");
        return 1;
    }

    for(int k = 1; k < n + 1; k++)
    {
        *(array + k - 1) = atoi(argv[k]);
    }


    // Sorting the stuff
    printf("Sorting !!! \n");
    // Init Stacks
    struct stack *stack1;
    struct stack *stack2;
    
    stack1 = (struct stack *)malloc(sizeof(struct stack));
    stack1->top = -1;
    stack1->array = (int *)calloc(n, sizeof(int));
    
    stack2 = (struct stack *)malloc(sizeof(struct stack));
    stack2->top = -1;
    stack2->array = (int *)calloc(n, sizeof(int));

    push(stack1, *array);

    for(int i = 1; i < n; i++) {
        if(stack1->array[stack1->top] >= *(array + i)) {
            push(stack1, *(array + i));
        }
        else {
            while((stack1->array[stack1->top] < *(array + i)) &&
                    !isEmpty(stack1)) {
                push(stack2, pop(stack1));
            }
            push(stack1, *(array + i));
            while(!isEmpty(stack2)) {
                push(stack1, pop(stack2));
            }
        }
    }

    // Result !!!
    printf("Sorted Array !\n");
    for(int i = 0; i < n; i++) {
        *(array + i) = pop(stack1);
        printf(" %d ", *(array + i));
    }
    printf("\n\n");


    return 0;

}
