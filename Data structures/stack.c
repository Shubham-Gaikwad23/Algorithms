#include <stdlib.h>
#include <assert.h>

#define FALSE 0;
#define TRUE 1;

typedef struct stack {
    int *stk;
    int top;
    int size;
}stack;


int push(stack *s, int key) {
    if (s->top + 1 == s->size) {
        return FALSE;
    }
    
    s->top = s->top + 1;
    s->stk[s->top] = key;
    return TRUE;
}

int pop(stack *s, int *key) {
    if (s->top == -1) {
        return FALSE;
    }

    *key = s->stk[s->top];
    s->top = s->top - 1;
    return TRUE;
}

void init(stack *s, int size) {
    s->top = -1;
    s->size = size;
    s->stk = malloc(sizeof(int) * size);
}

int main()
{
    stack s;
    int key;
    
    init(&s, 3);
    
    assert(!pop(&s, &key));
    assert(push(&s, 1));
    assert(push(&s, 2));
    assert(push(&s, 3));
    assert(pop(&s, &key) && key == 3);
    assert(pop(&s, &key) && key == 2);
    assert(push(&s, 0));
    assert(push(&s, -1));
    assert(pop(&s, &key) && key == -1);
    assert(pop(&s, &key) && key == 0);
    assert(pop(&s, &key) && key == 1);

    return 0;
}
