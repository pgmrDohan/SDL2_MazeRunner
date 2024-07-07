typedef struct {
  cell *data;
  struct Node *next;
} Node;

typedef struct {
  int size;
  Node *head;
} Stack;

Node *initNode(cell *data) {
  Node *n = malloc(sizeof(Node));

  n->data = data;
  n->next = 0;

  return n;
}

void destroyNode(Node *node) {
  node->next = 0;
  free(node);
}

Stack *initStack() {
  Stack *s = malloc(sizeof(Stack));

  s->head = 0;
  s->size = 0;

  return s;
}

int stackSize(Stack *stack) {
  if (stack == 0) {
    return -1;
  } else {
    return stack->size;
  }
}

int isEmpty(Stack *stack) { return stackSize(stack) == 0; }

void destroyStack(Stack *stack) {
  if (isEmpty(stack)) {
    free(stack);
  } else {
    Node *curr = stack->head;
    while (curr != 0) {
      Node *temp = curr;
      curr = curr->next;

      free(temp);
    }
  }
}

void push(Stack *stack, cell *value) {
  Node *newNode = initNode(value);

  if (isEmpty(stack)) {
    newNode->next = 0;

    stack->head = newNode;
  } else {
    newNode->next = stack->head;
    stack->head = newNode;
  }

  stack->size++;
}

Node *pop(Stack *stack) {
  if (isEmpty(stack)) {
    return 0;
  } else {
    Node *result = stack->head;

    stack->head = stack->head->next;

    stack->size--;

    return result;
  }
}