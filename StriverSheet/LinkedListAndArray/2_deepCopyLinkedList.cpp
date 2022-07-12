//solution is incomplete

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
    ListNode *random;
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

ListNode *getPremid(ListNode *head)
{
    ListNode *mid = head, *fast = head;
    ListNode *premid = NULL;
    while (fast->next != NULL)
    {
        premid = mid;
        mid = mid->next;
        fast = fast->next;
        if (fast->next != NULL)
            fast = fast->next;
    }
    return premid;
}
ListNode *getReverseList(ListNode *head)
{
    ListNode *left = NULL;
    ListNode *middle = head;
    ListNode *right;
    while (middle != NULL)
    {
        right = middle->next;
        middle->next = left;
        left = middle;
        middle = right;
    }
    return left;
}

ListNode *copyRandomList(ListNode *head)
{
    ListNode *s = head, *e = head->next;
    ListNode *n;

    while (e != NULL)
    {
        // inserting new node
        n = new ListNode;
        n->val = s->val;
        s->next = n;
        n->next = e;
        // incrementing the pointers
        s = e;
        e = e->next;
    }

    // for the last Node
    n = new ListNode;
    n->val = s->val;
    s->next = n;
    n->next = NULL;

    // linked list is set up now we copy the random pointer
    s = head;
    // e = s->next->next;
    // cout<<s->val<<endl<<e->val<<endl;
    int d = 0;
    while (s != NULL)
    {
        cout << s->val << endl;
        if (d % 2 == 0)
        {
            cout << s->val << " ";
            if (!s->random)
                s->random->next = NULL;
            else
                s->next->random = s->random->next;
        }
        s = s->next;
        d++;
    }

    // ListNode* new_head = head->next;
    // now linked list random pointers are also copied
    // while(e!= NULL){

    //     s = e;
    //     e = e->next;
    //     ->next;
    // }

    printList(head);
    return head;
    // return new_head ? new_head : NULL;
}

int main()
{
    // type Code
    ListNode *head = NULL;
    head = AppendLinkedList(1, head);
    head = AppendLinkedList(2, head);
    head = AppendLinkedList(3, head);
    head = AppendLinkedList(4, head);

    head->random = head->next->next->next;
    // cout<<head->next->next->next->val<<endl;

    head->next->random = head;
    // cout<<head->val<<endl;

    head->next->next->random = NULL;
    // cout<<"NULL"<<endl;

    head->next->next->next->random = head->next;
    // cout<<head->next->val<<endl;

    printList(head);
    ListNode *new_head = copyRandomList(head);
    // printList(new_head);

    return 0;
}