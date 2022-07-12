#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printListBottom(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->bottom;
    }
    cout << endl;
}

void printListNext(Node *hd)
{

    while (hd != NULL)
    {
        cout << hd->data << " ";
        hd = hd->next;
    }
    cout << endl;
}

Node *AppendLinkedList(int value, Node *hd)
{
    Node *head_node = hd;
    Node *temp = new Node(0);
    temp->data = value;
    temp->bottom = NULL;
    if (head_node == NULL)
    {
        // NO NODES IN THE LINKED LIST
        return temp;
    }
    else
    {
        // NODES ARE ALREADY THERE IN THE LINKED LIST
        while (hd->bottom != NULL)
            hd = hd->bottom;
        // pointer hd is pointing at the last node of the linked list
        hd->bottom = temp;
        return head_node;
    }
    return head_node;
}

Node *mergeTwoList(Node *l1, Node *l2)
{
    Node *list1 = l1, *list2 = l2;
    Node *dummy = new Node(0);
    Node *p = dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            p->bottom = list1;
            p = list1;
            list1 = list1->bottom;
        }
        else if (list1->data > list2->data)
        {
            p->bottom = list2;
            p = list2;
            list2 = list2->bottom;
        }
    }
    if (list1 == NULL)
    {
        p->bottom = list2;
    }
    else if (list2 == NULL)
    {
        p->bottom = list1;
    }
    return dummy->bottom;
}

Node *flatten(Node *root)
{

    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = mergeTwoList(root, root->next);
    return root;
}

int main(void)
{

    // Node *head1 = NULL, *head2 = NULL;
    // head1 = AppendLinkedList(1, head1);
    // head1 = AppendLinkedList(4, head1);
    // head1 = AppendLinkedList(6, head1);
    // head1 = AppendLinkedList(69, head1);
    // printListBottom(head1);
    // head2 = AppendLinkedList(3, head2);
    // head2 = AppendLinkedList(8, head2);
    // head2 = AppendLinkedList(9, head2);
    // head2 = AppendLinkedList(10, head2);
    // // printListBottom(head2);
    // // head1 = mergeTwoList(head1, head2);
    // printListBottom(head1);


    
    // head1 = flatten(root);
    // int n, m, flag = 1, flag1 = 1;
    // Node *temp = NULL;
    // Node *head = NULL;
    // Node *pre = NULL;
    // Node *tempB = NULL;
    // Node *preB = NULL;
    // cin >> n;
    // int work[n];
    // for (int i = 0; i < n; i++)
    //     cin >> work[i];
    // for (int i = 0; i < n; i++)
    // {
    //     m = work[i];
    //     --m;
    //     int data;
    //     scanf("%d", &data);
    //     temp = new Node(data);
    //     temp->next = NULL;
    //     temp->bottom = NULL;

    //     if (flag)
    //     {
    //         head = temp;
    //         pre = temp;
    //         flag = 0;
    //         flag1 = 1;
    //     }
    //     else
    //     {
    //         pre->next = temp;
    //         pre = temp;
    //         flag1 = 1;
    //     }
    //     for (int j = 0; j < m; j++)
    //     {

    //         int temp_data;
    //         scanf("%d", &temp_data);
    //         tempB = new Node(temp_data);

    //         if (flag1)
    //         {
    //             temp->bottom = tempB;
    //             preB = tempB;
    //             flag1 = 0;
    //         }
    //         else
    //         {
    //             preB->bottom = tempB;
    //             preB = tempB;
    //         }
    //     }
    // }
    // Node *fun = head;
    // Node *fun2 = head;

    // Node *root = flatten(head);
    // printList(root);
    // cout << endl;

    return 0;
}
