/* Program to implement a function that accepts the head node of a linked
 * list, reverses it and returns the new head node.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *add(struct node *, int);
struct node *reverse(struct node *);
void remove_all(struct node *);
void print_all(struct node *);

int main()
{
    struct node *head = NULL;

    /* Create a linked list by adding nodes */
    head = add(head, 5);
    head = add(head, -5);
    head = add(head, 15);
    head = add(head, 25);
    head = add(head, 51);
    head = add(head, 9);
    head = add(head, 0);

    printf("Original list: ");
    print_all(head);
    head = reverse(head);
    printf("Reversed list: ");
    print_all(head);
    remove_all(head);

    return 0;
}

/* Add a new node to the beginning of the linked list */
struct node *add(struct node *head, int value)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->value = value;
    n->next = head;
    return n;
}

struct node *reverse(struct node *head)
{
    struct node *p, *q, *r;
    if (!head || !head->next)
        return head;
    p = head;
    q = head->next;
    p->next = NULL;
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

void remove_all(struct node *head)
{
    struct node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_all(struct node *head)
{
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
