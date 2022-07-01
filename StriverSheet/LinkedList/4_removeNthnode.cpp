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

ListNode *removeNthIndexElement(ListNode *head, int n)
{
    ListNode *hd = head;
    ListNode *p = NULL;
    int index = 0;
    cout << "n value is : " << n << endl;

    while (index != n)
    {
        p = hd;
        hd = hd->next;
        index++;
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
        return ((l + h) / 2); // on left
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return head;
    ListNode *dummy = new ListNode;
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;
    int i = n;
    while (i)
    {
        fast = fast->next;
        i--;
    }
    // not fast is pointing at the 4th or nth element in the linked list
    // now time to move slow pointer
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // delete dummy;
    // dummy = slow->next;
    slow->next = slow->next->next;
    // delete dummy;
    return dummy->next;
}

int main()
{
    ListNode *head1 = NULL;
    head1 = AppendLinkedList(2, head1);
    head1 = AppendLinkedList(4, head1);
    head1 = AppendLinkedList(1, head1);
    head1 = AppendLinkedList(3, head1);
    head1 = AppendLinkedList(5, head1);
    head1 = AppendLinkedList(6, head1);
    printList(head1);
    removeNthFromEnd(head1, 4);
    printList(head1);

    return 0;
}