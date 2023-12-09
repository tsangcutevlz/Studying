#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

void printList(node *l)
{
    node *p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

node *addElement(node *p, int x)
{
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

node *addHead(node *l, int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = l;
    l = temp;
    return l;
}

node *addTail(node *l, int x)
{
    node *p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    p->next = temp;
    return l;
}

node *addAt(node *l, int k, int x)
{
    node *p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return l;
}

node *deleteHead(node *l)
{
    node *p = l;
    p = p->next;
    delete (l);
    return p;
}

node *deleteTail(node *l)
{
    node *p = l;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    delete (p->next);
    p->next = NULL;
    return l;
}

node *deleteAt(node *l, int k)
{
    node *p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node *temp = p->next;
    p->next = p->next->next;
    delete (temp);
    return l;
}

node *getNode(node *l, int k)
{
    node *p = l;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
    }
    return p;
}

node *convert(node *l, int a, int b)
{
    node *p = l;
    while (p != NULL)
    {
        if (p->data == a)
        {
            p->data = b;
        }
        p = p->next;
    }
    return l;
}

node *deleteBigger(node *l, int k)
{
    node *p = l;
    node *ans = new node;
    while (p != NULL)
    {
        if (p->data <= k)
        {
            ans = createNode(p->data);
            p = p->next;
            break;
        }
        p = p->next;
    }
    while (p != NULL)
    {
        if (p->data <= k)
        {
            ans = addTail(ans, p->data);
        }
        p = p->next;
    }
    return ans;
}

int main()
{
    int n, x, k;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    cin >> k;
    l = deleteBigger(l, getNode(l, k)->data);
    printList(l);
    return 0;
}