#include <stdlib.h>
#include <stdio.h>

struct node{
    int key_val;
    struct node *left;
    struct node *right;
};

int fill_tree(int size, int input);

void insert(int value, struct node **leaf);

void destroy(struct node *leaf);

int max(int a, int b);

int height(struct node* node);

int isBalanced(struct node *root);

int main() {

    int input_cases = 0;
    int data_size = 0, i;
    int is_AVL = 0; //1 for AVL, 0 for not AVL

    scanf("%d", &input_cases);

    for (i = 0; i < input_cases; i++) {
        is_AVL = fill_tree(data_size, input_cases);
        //if AVL KEEP, if not REMOVE
        if (is_AVL == 0) {
            printf("Tree %d: REMOVE\n", i + 1);
        } else if (is_AVL == 1) {
            printf("Tree %d: KEEP\n", i + 1);
        } else {
            perror("is_AVL out of bounds");
        }
    }


    return 0;
}

int fill_tree(int size, int input) {
    int value;
    int i = 0;
    int level = 0;

    struct node *root = 0;

    scanf("%d", &size); //number of time to run insert tree.

    while(i < input){
        scanf("%d", &value);
        insert(value, &root);
        printf("%d ", root->key_val);
        i++;

    }
    printf("\n");

    destroy(root);
    return 0;
}

int height(struct node* node)
{
    /* base case tree is empty */
    if(node == NULL)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       height and right heights */
    return 1 + max(height(node->left), height(node->right));
}

int max(int a, int b)
{
    return (a >= b)? a: b;
}

int isBalanced(struct node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if(root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if( abs(lh-rh) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return 1;

    /* If we reach here then tree is not height-balanced */
    return 0;
}

void destroy(struct node *leaf) {
    if( leaf != 0 )
    {
        destroy(leaf->left);
        destroy(leaf->right);
        free( leaf );
    }
}

void insert(int value, struct node **leaf) {
    //catch case
    if (*leaf == 0){
        *leaf = malloc(sizeof(struct node));
        (*leaf)->key_val = value;

        //init childrens
        (*leaf)->left = 0;
        (*leaf)->right = 0;
    } else if (value < (*leaf)->key_val){
        insert(value, &(*leaf)->left);
    } else if (value > (*leaf)->key_val){
        insert(value, &(*leaf)->right);
    }

}

