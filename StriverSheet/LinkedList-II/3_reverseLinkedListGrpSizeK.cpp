#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    // Constructor
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next)
    {

        this->val = x;
        this->next = next;
    }
} * head;

void printList(ListNode *h)
{
    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}

ListNode *AppendLinkedList(int value, ListNode *hd)
{
    ListNode *head_node = hd;
    ListNode *temp = new ListNode;
    temp->val = value;
    temp->next = NULL;
    if (head_node == NULL)
    {
        // NO NODES IN THE LINKED LIST
        return temp;
    }
    else
    {
        // NODES ARE ALREADY THERE IN THE LINKED LIST
        while (hd->next != NULL)
            hd = hd->next;
        // pointer hd is pointing at the last node of the linked list
        hd->next = temp;
        return head_node;
    }
    return head_node;
}

ListNode *removeElement(ListNode *head, int n)
{
    ListNode *hd = head;
    ListNode *p = NULL;
    while (hd != NULL && hd->val != n)
    {
        p = hd;
        hd = hd->next;
    }
    if (hd != NULL)
    {
        // element found and hd is pointing to that element
        p->next = hd->next;
    }
    return head;
}

int getMiddle(int l, int h)
{
    if ((l + h) % 2 == 0)
        return (l + h) / 2;
    else
        return ((l + h) / 2) + 1;
}
ListNode *getMiddleNode(ListNode *hd)
{
    ListNode *middle = hd;
    ListNode *fast = hd;
    while (fast->next != NULL)
    {
        middle = middle->next;
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    return middle;
}
int getSize(ListNode *head)
{
    ListNode *hd = head;
    int size = 0;
    while (hd != NULL)
    {
        hd = hd->next;
        size++;
    }
    return size;
}

int getindex(ListNode *head, int element)
{
    int index = 0;
    while (head->val != element && head != NULL)
    {
        head = head->next;
        if (head == NULL)
            break;
        index++;
    }
    if (head == NULL)
        return -1;
    else
        return index;
}

ListNode *getLast(ListNode *head)
{
    ListNode *hd = head;
    while (hd->next != NULL)
    {
        hd = hd->next;
    }
    return hd;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    int size = getSize(head);
    int R = size / k;
    // cout << "No of times we can reverse the list : " << R << endl;

    // variables to be used;
    ListNode *p_n = NULL;
    ListNode *s = NULL;
    ListNode *temp_head = head;
    ListNode *e = head, *t = e->next, *ter = head;
    int flag = 1;
    int i = k; // we will use i to align it to terminating pointer

    while (R > 0)
    {
        // Align ter (terminating pointer) to the current location
        if (R > 0)
        {
            while (i)
            {
                ter = ter->next;
                i--;
            }
        }

        // reverse the nodes;
        while (t != ter)
        {
            e->next = s;
            s = e;
            e = t;
            t = t->next;
        }
        if (p_n != NULL){
            // cout << "previous node currently is ("<< R<<") : " << p_n->val << endl;
            p_n->next  = e;
        }


        // reversing the last element after t == ter
        e->next = s;
        R--;

        // changing the head value
        if (flag)
        {
            flag = 0;
            head = e;
        }

        // connecting the broken linked list in the reverse order
        temp_head->next = ter;



        //SETTING UP VARIABLES FOR NEXT GROUP TO REVERSE
        // linked grp 1 is reversed
        p_n = temp_head;
        temp_head = temp_head->next; //  temp_head now is pointing at ter or t;

        // cout << "p_n : " << p_n->val << endl;
        // cout << "temp_head : " << temp_head->val << endl;
        if(R == 0) break;

        // initializing variables for next iteration group to reverse
        s = NULL;
        e = ter;
        t = e->next;

        i = k;
    }

    return head;
}

int main()
{
    ListNode *head = NULL;
    head = AppendLinkedList(1, head);
    head = AppendLinkedList(2, head);
    head = AppendLinkedList(3, head);
    head = AppendLinkedList(4, head);
    head = AppendLinkedList(5, head);
    int k = 2;
    printList(head);
    head = reverseKGroup(head, k);
    printList(head);

    return 0;
}