/* Program to implement a doubly linked list. We would need to define the
 * structure, and implement add and delete node functions.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *add(struct node *, int);
struct node *del(struct node *, int);
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
    head = del(head, 1);
    head = del(head, 4);
    head = del(head, 3);
    printf("Modified list: ");
    print_all(head);
    remove_all(head);
    return 0;
}

/* Add a new node to the beginning of the linked list */
struct node *add(struct node *head, int value)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->value = value;
    n->left = NULL;
    n->right = head;
    if (head)
        head->left = n;
    return n;
}

struct node *del(struct node *head, int position)
{
    int i = 1;
    struct node *ptr = head;
    while (ptr && i <= position) {
        if (i == position) {
            if (!ptr->left) {
                head = ptr->right;
                head->left = NULL;
            } else {
                ptr->left->right = ptr->right;
                if (ptr->right)
                    ptr->right->left = ptr->left;
            }
            free(ptr);
            break;
        }
        ptr = ptr->right;
        i++;
    }
    if (i != position)
        printf("Invalid node position passed for deletion!\n");
    return head;
}


void remove_all(struct node *head)
{
    struct node *tmp;
    while (head) {
        tmp = head;
        head = head->right;
        free(tmp);
    }
}

void print_all(struct node *head)
{
    while (head) {
        printf("%d ", head->value);
        head = head->right;
    }
    printf("\n");
}
