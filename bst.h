#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

class Node
{
    public:
        string key;
        int height;  //used for rotations
        int subtree; //used for range queries
        Node *left, *right, *parent;

        Node()
        {
            left = right = parent = NULL;
            height = 1;
            subtree = 0;
        }

        Node(string val)
        {
            key = val;
            left = right = parent = NULL;
            height = 1;
            subtree = 0;
        }
};

class BST
{
    private:
        Node *root;
    public:
        BST();
        Node* find(string);
        Node* find(Node*, string);
        Node* minNode(Node*);
        Node* maxNode(Node*);
        Node* deleteKey(string);
        Node* deleteNode(Node*);
        void deleteBST();
        void deleteBST(Node* start);
        Node* lca(Node*, string, string); //finds least common ancestor of two strings
        void height(Node*);
        void subtree(Node*);
        int range(string, string);
        int range(Node*, string, string); //used for range queries
        Node* rotateRight(Node*);
        Node* rotateLeft(Node*);
        void insert(string);
        Node* insert(Node*,Node*, string);
        Node* rotateLeftRight(Node*);
        Node* rotateRightLeft(Node*);
        int SearchLeft(Node*, string); //searches left side of lca for lower bound
        int SearchRight(Node*, string); //searches right side of lca for upper bound
        void preOrder(Node *r);
        void preOrder();
};

#endif

