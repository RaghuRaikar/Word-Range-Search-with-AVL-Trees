#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

class Pair
{
    int value;
    int width;
};

BST :: BST()
{
    root = NULL;
}

Node* BST :: find(string val)
{
    return find(root, val);
}

Node* BST :: find(Node* start, string val) //finds a node with the key val
{
    if(start == NULL || start->key == val)
    {
        return start;
    }
    if(val < start->key)
    {
        return find(start->left, val);
    }
    else
    {
        return find(start->right, val);
    }
}

Node* BST :: minNode(Node* start) //gets minimum node in tree of root given
{
    if(start == NULL)
    {
        return NULL;
    }
    if(start->left == NULL)
    {
        return start;
    }
    else
    {
        return minNode(start->left);
    }
}

Node* BST :: maxNode(Node* start) //gets maximum node in tree of root given
{
    if(start == NULL)
    {
        return NULL;
    }
    if(start->right == NULL)
    {
        return start;
    }
    else
    {
        return maxNode(start->right);
    }
}

Node* BST :: deleteKey(string val)
{
    return deleteNode(find(val));
}

Node* BST :: deleteNode(Node* to_delete) //function to delete nodes
{
    if(to_delete == NULL)
    {
        return NULL;
    }
    bool isRoot = (to_delete == root) ? true : false;

    bool isLeftChild = false;
    if(!isRoot)
    {
        isLeftChild = (to_delete->parent->left == to_delete) ? true : false;
    }
    bool isDeleted = false;
    if(to_delete->left == NULL)
    {
        if(isRoot)
        {
            root = to_delete->right;
            if(root != NULL)
            {
                root->parent = NULL;
            }
            else
            {
                if(isLeftChild)
                {
                    to_delete->parent->left = to_delete->right;
                }
                else
                {
                    to_delete->parent->right = to_delete->right;
                }
                if(to_delete->right != NULL)
                {
                    to_delete->right->parent = to_delete->parent;
                }
            }
        }
        isDeleted = true;
    }
    if(!isDeleted && to_delete->right == NULL)
    {
        if(isRoot)
        {
            root = to_delete->left;
            if(root != NULL)
            {
                root->parent = NULL;
            }
        }
        else
        {
            if(isLeftChild)
            {
                to_delete->parent->left = to_delete->left;
            }
            else
            {
                to_delete->parent->right = to_delete->left;
            }
            if(to_delete->left != NULL)
            {
                to_delete->left->parent = to_delete->parent;
            }
        }
        isDeleted = true;
    }
    if(isDeleted)
    {
        to_delete->left = to_delete->right = NULL;
        return to_delete;
    }
    Node* succ = minNode(to_delete->right);
    to_delete->key = succ->key;

    return deleteNode(succ);
}

void BST :: deleteBST()
{
    deleteBST(root);
}

void BST :: deleteBST(Node* start) //deletes given bst
{
    if(start == NULL)
    {
        return;
    }
    deleteBST(start->left);
    deleteBST(start->right);
    delete(start);
}

Node* BST :: lca(Node* r, string i, string j) //will find lca of two strings given even if one of them isn't in tree
{
    if(r == NULL)
    {
        return NULL;
    }
    if(r->key > i && r->key > j)
    {
        return lca(r->left,i,j);
    }
    else if(r->key < i && r->key < j)
    {
        return lca(r->right, i, j);
    }
    else
    {
        return r;
    }
}

void BST :: height(Node* r) // function to update height of each node
{
    if(r != NULL)
    {
        int tree_height = 1;
        if(r->left != NULL)
        {
            tree_height = r->left->height + 1;
        }
        if(r->right != NULL)
        {
            tree_height = max(tree_height,r->right->height +1);
        }

        r->height = tree_height;
    }
}

void BST :: subtree(Node* r) // function to update subtree size of each node
{
    if(r != NULL)
    {
        int size = 0;
        if(r->left != NULL)
        {
            size = r->left->subtree + 1;
        }
        if(r->right != NULL)
        {
            size = size + r->right->subtree + 1;
        }
        r->subtree = size;
    }
}

Node* BST :: rotateRight(Node* r)
{
    Node *rc = r->right;
    r->right = rc->left;
    if(rc->left != NULL)
    {
        rc->left->parent = r;
    }
    rc->left =r;
    rc->parent = r->parent;
    r->parent = rc;
    if(rc->parent != NULL && r->key < rc->parent->key)
    {
        rc->parent->left = rc;
    }
    else
    {
        if(rc->parent != NULL)
        {
            rc->parent->right = rc;
        }
    }
    r = rc;

    height(r->left);
    height(r->right);
    height(r);
    height(r->parent);

    subtree(r->left);
    subtree(r->right);
    subtree(r);
    subtree(r->parent);

    return r;

}

Node* BST :: rotateLeft(Node* r)
{
    Node *rc = r->left;
    r->left = rc->right;
    if(rc->right != NULL)
    {
        rc->right->parent = r;
    }

    rc->right = r;

    rc->parent = r->parent;
    r->parent = rc;
    if(rc->parent != NULL && r->key < rc->parent->key)
    {
        rc->parent->left = rc;
    }
    else
    {
        if(rc->parent != NULL)
        {
            rc->parent->right = rc;
        }
    }
    r = rc;

    height(r->left);
    height(r->right);
    height(r);
    height(r->parent);

    subtree(r->left);
    subtree(r->right);
    subtree(r);
    subtree(r->parent);

    return r;

}

Node* BST :: rotateLeftRight(Node* r)
{
    r->left = rotateRight(r->left);
    return rotateLeft(r);
}

Node* BST :: rotateRightLeft(Node* r)
{
    r->right = rotateLeft(r->right);
    return rotateRight(r);
}

void BST :: insert(string v)
{
    root = insert(root,NULL,v);
}

Node* BST :: insert(Node* n,Node* n2, string value)
{
    if(n == NULL)
    {
        n = new Node(value);
    }
    else if(n->key > value)
    {
        n->left = insert(n->left,n,value);
        int fh = 0;
        int sh = 0;

        if(n->left != NULL)
        {
            fh = n->left->height;
        }
        if(n->right != NULL)
        {
            sh = n->right->height;
        }

        if(abs(fh-sh) == 2)
        {
            if(root->left != NULL && value < n->left->key)
            {
                n = rotateLeft(n);
            }
            else
            {
                n = rotateLeftRight(n);
            }
        }
    }
    else if(n->key < value)
    {
        n->right = insert(n->right,n,value);

        int fh = 0;
        int sh = 0;
        if(n->left != NULL)
        {
            fh = n->left->height;
        }

        if(n->right != NULL)
        {
            sh = n->right->height;
        }

        if(abs(fh-sh) == 2)
        {
            if(n->right != NULL && value < n->right->key)
            {
                n = rotateRightLeft(n);
            }
            else
            {
                n = rotateRight(n);
            }
        }

    }

    height(n);
    subtree(n);

    return n;
}

int BST :: SearchLeft(Node *l, string lb) //searches left side of lca for lower bound
{
    int counter = 0;
    l = l->left;
    while(l != NULL)
    {
        if(l->key == lb)
        {
            counter++;
            if(l->right != NULL)
            {
                counter = counter + l->right->subtree + 1;
                break;
            }
            else
            {
                break;
            }
        }
        if(lb < l->key)
        {
            counter++;
            if(l->right != NULL)
            {
                if(lb < l->right->key)
                {
                    counter = counter + l->right->subtree + 1;
                }
            }
        }
        if(lb < l->key)
        {
            l = l->left;
        }
        else
        {
            l = l->right;
        }
    }
    return counter;
}


int BST :: SearchRight(Node* l, string ub) //searches right side of lca for upper bound
{
    int counter = 0;
    l = l->right;
    while(l != NULL)
    {
        if(l->key == ub)
        {
            counter++;
            if(l->left != NULL)
            {
                counter = counter + l->left->subtree + 1;
                break;
            }
            else
            {
                break;
            }
        }
        if(l->key < ub)
        {
            counter++;
            if(l->left != NULL)
            {
                if(l->left->key < ub)
                {
                    counter = counter + l->left->subtree + 1;
                }
            }
        }
        if(ub < l->key)
        {
            l = l->left;
        }
        else
        {
            l = l->right;
        }
    }
    return counter;
}

int BST :: range(string lb, string ub)
{
    return range(root, lb, ub);
}

int BST :: range(Node* f, string lb, string ub) //finds range queries of two given strings
{
    int returnvalue = 0;
    int ls = 0;
    int rs = 0;
    // if(lb > ub)
    // {
    //     string temp = ub;
    //     ub = lb;
    //     lb = temp;
    // }
    Node *l = lca(f,lb,ub);
    if(l != NULL)
    {
        if(lb <= l->key && l->key <= ub)
        {
            returnvalue++;
        }
        if(l->key != lb)
        {
            ls = SearchLeft(l,lb);
        }
        if(l->key != ub)
        {
            rs = SearchRight(l,ub);
        }
        returnvalue = returnvalue + ls + rs;
    }
    return returnvalue;

}

void BST :: preOrder()
{
    preOrder(root);
}

void BST :: preOrder(Node *r)
{
    if(r != NULL)
    {
        cout << r->key << " " << "SUBTREE " << r->subtree << " " << "HEIGHT " << r->height << endl;
        preOrder(r->left);
        preOrder(r->right);
    }
}


