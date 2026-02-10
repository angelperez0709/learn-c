#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}
void clear_memory(node_t **head)
{
    node_t *current = (*head);
    node_t *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}

void print_memory(node_t *head, char *momento)
{
    printf("\n--- Estado de la memoria (%s) ---\n", momento);

    if (head == NULL)
    {
        printf("El puntero 'head' apunta a: NULL (0x0)\n");
        printf("La lista está vacía y es segura.\n");
    }
    else
    {
        printf("El puntero 'head' apunta a la dirección: %p\n", (void *)head);

        node_t *current = head;
        int i = 0;
        while (current != NULL)
        {
            printf("  Nodo %d [%p] -> valor: %d, siguiente: %p\n",
                   i++, (void *)current, current->val, (void *)current->next);
            current = current->next;
        }
    }
    printf("-------------------------------------------\n");
}
int push(node_t *head, int val)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void remove_by_value(node_t **head, int val)
{
    node_t *current = (*head);
    node_t *prev = NULL;
    
    if (current == NULL)
    {
        return;
    }

    if(current->val == val){
        *head = (*head)->next;
        free(current);
        return;
    }

    while (current != NULL && current->val != val)
    {
        prev = current;
        current = current->next;
    }

     if (current == NULL)
    {
        return;
    }
    


    prev->next = current->next;
    free(current);
}

int main()
{
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    print_list(head);
    print_memory(head, "Antes de limpiar");
    //clear_memory(&head);
    remove_by_value(&head,2);
    print_memory(head, "Despues de limpiar");
}