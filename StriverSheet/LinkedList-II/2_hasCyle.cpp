#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define length 10

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

bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *slow = head, *fast = head;
    if (slow->next == NULL && slow != NULL)
        return false;

    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

    } while (fast && slow && fast != slow);

    if (fast == slow)
        return true;
    else
        return false;
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

int main()
{
    ListNode* head = NULL;
    head = AppendLinkedList(1,head);
    head = AppendLinkedList(2,head);
    head = AppendLinkedList(3,head);
    printList(head);

    ListNode*last = getLast(head);
    last->next = head;//has node is pointing towards the first node instead of giving Error

    if(hasCycle(head))cout<<"There is cycle in linked list"<<endl;
    else cout<<"There is No cycle in linked list"<<endl;


    return 0;
}