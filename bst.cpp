#include <bits/stdc++.h>

using namespace std;

struct tree_node{
    int data;
    tree_node *left;
    tree_node *right;
}tree;

class bst_tree{

    public:
    tree_node* create_node(int data){
        tree_node *tr;
        tr=(struct tree_node*)malloc(sizeof(tree_node));
        tr->data = data;
        tr->left = NULL;
        tr->right = NULL;

        return tr; 
    }

    tree_node* insert(tree_node* node, int data){
        if(node == NULL){
            return create_node(data);
        }
        if(node !=NULL){
            if(data > node->data){
                node->right = insert(node->right,data);
            }
            else {
                node->left = insert(node->left,data);
            }
        }
        return node;
    }

    void IsExists(bool v){
        if(v)
            cout<< "item exists:\n";
        else
            cout<< "item does not exists:\n";
    }

    bool search(tree_node* node, int data){
        if(node==NULL){
            return false;
        }
        else if(node->data == data){
            return true;
        }
        else if(node->data < data){
            search(node->right, data);
        }
        else{
            search(node->left, data);
        }
    }

    void inorder(struct tree_node* node)
    {
        if(node != NULL){
            inorder(node->left);
            cout << node->data << "\n";
            inorder(node->right);
        }
    }
};

int main() 
{   
    bst_tree *bst =  new bst_tree();
    tree_node* node; 
    node = bst->create_node(20);

    bst->insert(node , 10);
    bst->insert(node , 21);
    bst->insert(node , 24);
    bst->insert(node , 36);
    bst->insert(node , 1);
    
    bst->inorder(node);

    bool result1 = bst->search(node, 12);
    bst->IsExists(result1);
    bool result2 = bst->search(node, 30);
    bst->IsExists(result2);

    return 0; 
}