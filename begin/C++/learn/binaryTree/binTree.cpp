#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *insert(node *t, int x)
{
    if (t == NULL)
    {
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        if (x < t->data)
        {
            t->left = insert(t->left, x);
        }
        else
        {
            t->right = insert(t->right, x);
        }
    }
}
bool isLeafNode(node *l)
{
    return (l->left == NULL && l->right == NULL);
}
int countLeafNode(node *t)
{
    if (t == NULL)
        return 0;
    if (isLeafNode(t))
        return 1;
    return countLeafNode(t->left) + countLeafNode(t->right);
}

int treeLevel(node *t)
{
    if (t == NULL)
        return -1;
    return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool checkAvl(node *t)
{
    if (t == NULL)
        return true;
    if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
        return false;
    return checkAvl(t->left) && checkAvl(t->right);
}

node *turnRight(node *a)
{
    node *b = a->left;
    node *d = b->right;
    a->left = d;
    b->right = a;
    return b;
}

node *turnLeft(node *a)
{
    node *b = a->right;
    node *c = b->left;
    a->right = c;
    b->left = a;
    return b;
}

node *updateTreeAvl(node *t)
{
    if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
    {
        if (treeLevel(t->left) > treeLevel(t->right))
        {
            node *p = t->left;
            if (treeLevel(p->left) >= treeLevel(p->right))
            {
                t = turnRight(t);
            }
            else
            {
                t->left = turnLeft(t->left);
                t = turnRight(t);
            }
        }
        else
        {
            node *p = t->right;
            if (treeLevel(p->right) >= treeLevel(p->left))
            {
                t = turnLeft(t);
            }
            else
            {
                t->right = turnRight(t->right);
                t = turnLeft(t);
            }
        }
    }
    if (t->left != NULL)
        t->left = updateTreeAvl(t->left);
    if (t->right != NULL)
        t->right = updateTreeAvl(t->right);
    return t;
}

int count(node *t, int x)
{
    if (t == NULL)
        return 0;
    if (t->data == x)
        return 1 + count(t->left, x) + count(t->right, x);
    else if (t->data < x)
        return count(t->right, x);
    return count(t->left, x);
}

void deleteNode(node*t){
    if(t != NULL){
        if(t->left != NULL) deleteNode(t->left);
        if(t->right != NULL) deleteNode(t->right);
        delete(t);
    }
}

node *deleteNumber(node*t, int x){
    if(t != NULL){
        if(t->data == x){
            deleteNode(t->left);
            deleteNode(t->right);
            t = NULL;
        }
        else if( t->data > x) t->left = deleteNumber(t->left, x);
        else t->right = deleteNumber(t->right, x);
    }
    return t;
}

void printTree(node *t)
{
    if (t != NULL)
    {
        printTree(t->left);
        cout << t->data << " ";
        printTree(t->right);
    }
}
int main()
{
    int n, x, temp;
    cin >> n;
    node *t = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        t = insert(t, temp);
    }
    while (!checkAvl(t))
    {
        t = updateTreeAvl(t);
    }
    cin >> x;
    cout << count(t, x);
    return 0;
}