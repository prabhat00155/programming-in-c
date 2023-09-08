/* Program to create a binary search tree.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *lchild;
    struct node *rchild;
};

struct node *add(struct node *, int);
struct node *insert(struct node *, struct node *);
void inorder(struct node *);
void remove_all(struct node *);

int main()
{
    struct node *root = NULL;

    root = add(root, 20);
    root = add(root, -20);
    root = add(root, 20);
    root = add(root, 120);
    root = add(root, 0);
    root = add(root, 2);
    root = add(root, 12);
    root = add(root, 1);
    root = add(root, -112);
    root = add(root, 1200);
    root = add(root, 30);

    printf("BST nodes (inorder):\n");
    inorder(root);
    printf("\n");
    remove_all(root);
    return 0;
}

struct node *add(struct node *root, int value)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->value = value;
    n->lchild = NULL;
    n->rchild = NULL;
    return insert(root, n);
}

struct node *insert(struct node *root, struct node *n)
{
    if (!root)
        return n;
    if (n->value <= root->value)
        root->lchild = insert(root->lchild, n);
    else
        root->rchild = insert(root->rchild, n);
    return root;
}

void inorder(struct node *root)
{
    if (root) {
        inorder(root->lchild);
        printf("%d ", root->value);
        inorder(root->rchild);
    }
}

void remove_all(struct node *root)
{
    if (root) {
        remove_all(root->lchild);
        remove_all(root->rchild);
        free(root);
    }
}
