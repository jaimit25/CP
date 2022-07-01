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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = 0, len2 = 0;
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL)
        {
            len1++;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            len2++;
            p2 = p2->next;
        }
    }
    // cout << "length of list 1 : " << len1 << endl;
    // cout << "length of list 2 : " << len2 << endl;
    int jump;
    ListNode *fast, *slow;
    if (len1 - len2 >= 0)
    {
        // len1 is bigger or list 1 is bigger
        jump = len1 - len2;
        // cout << "no of jump for len1 is : " << jump << endl;
        fast = headA;
        slow = headB;
    }
    else
    {
        // len 2 is bigger or list 2 is bigger
        jump = len2 - len1;
        // cout << "no of jump for len2 is : " << jump << endl;
        fast = headB;
        slow = headA;
    }
    while (jump > 0)
    {
        // cout << "Jump " << endl;
        fast = fast->next;
        jump--;
    }
    // cout<<"fast pointer is at : "<<fast->val<<endl;
    while (fast != NULL)
    {
        if (fast == slow)
            return fast;
        fast = fast->next;
        slow = slow->next;
    }
    return NULL;
}

int main()
{
    ListNode *head1 = NULL, *head2 = NULL;

    // linked list 1

    ListNode *n1 = new ListNode(4);
    head1 = n1;
    ListNode *n2 = new ListNode(1);
    n1->next = n2;

    // Intersection node
    ListNode *in = new ListNode(8);
    n2->next = in;

    // linked list 2
    ListNode *nd1 = new ListNode(5);
    ListNode *nd2 = new ListNode(6);
    ListNode *nd3 = new ListNode(1);
    head2 = nd1;

    nd1->next = nd2;
    nd2->next = nd3;
    nd3->next = in;

    // common nodes between both the linked list 4 ,5
    //       4 -> 1
    //               -> 8 -> 4 -> 5
    //  5 -> 6 -> 1
    ListNode *c1 = new ListNode(4);
    ListNode *c2 = new ListNode(5);
    in->next = c1; // here 8 is intersection (in) node
    c1->next = c2; // c1 and c2 node are 4 and 5

    printList(head1);
    printList(head2);
    ListNode *ans = getIntersectionNode(head1, head2);
    cout << ans->val << endl;

    return 0;
}