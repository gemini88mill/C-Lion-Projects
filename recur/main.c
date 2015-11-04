#include <stdlib.h>
#include <stdio.h>


/*bintree_node - struct creates the node for the tree.
 *
 * every bintree has 3 values, the actual data, and the two child nodes. either going left or right from the parent on
 * the tree. by convention, each node going left or right is set so that if you go left you are hitting a value that is
 * less then the parent, and right is more then the parent.
 *
 *                          20      <-- parent node
 *                         /  \
 *                        15  30    <--children nodes
 *                       /  \   \
 *                      4   17  35  <-- note that all values left and right are lower or higher then the parent but not
 *                                      lower or higher then the grandparent.
 *                      */
struct bintree_node{
    int data;
    struct bintree_node *left;
    struct bintree_node *right;
};




struct bintree_node * create_node(int val);

struct bintree_node *insert_node(struct bintree_node *root, struct bintree_node *node);

int main() {
    printf("hello world");

    int vals_for_nodes[] = {23, 4, 5, 8, 17, 11, 67, 42, 11, 6};
    int *node_ptr = 0;
    int i;

    struct bintree_node *node, *root = NULL;

    for(i = 0; i < 10; i++){
        node = create_node(vals_for_nodes[i]); //creates the node and prepares it to be places in the tree
        root = insert_node(root, node);        //inserts the node created into tree
    }


    return 0;
}

struct bintree_node *insert_node(struct bintree_node *root, struct bintree_node *node) {

    if(root == NULL){ //root is NULL return the node back
        return node;
    }
    else{
        if(node->data > root->data){
            if(root->right != NULL){
                root->right = insert_node(root->right, node);
            }
            else{
                root->right = node;
            }
        }
        else{
            if(root->left != NULL){
                root->left = insert_node(root->left, node);
            }
            else{
                root->left = node;
            }
            return root;
        }
    }


}

struct bintree_node * create_node(int val){
    /*create_node() - sets the node for the incoming val. very similar to linear linked list. but instead of one link
     * here we have two links to two different children. */
    struct bintree_node *temp;

    temp = malloc(sizeof(struct bintree_node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}







