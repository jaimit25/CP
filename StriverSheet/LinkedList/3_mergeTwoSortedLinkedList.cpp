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
    if(h == NULL) cout<<"NULL"<<endl;
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *resultant;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->val > list2->val)
        swap(list1, list2);
    resultant = list1; // it will store head of the first element/ListNode

    while (list1 != NULL && list2 != NULL)
    {

        ListNode *temp = NULL;
        while (list1 != NULL && list1->val <= list2->val)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }

    return resultant;
}

int main()
{

    // Input Format :
    // l1 = {3,7,10}, l2 = {1,2,5,8,10}

    // Output :
    // {1,2,3,5,7,8,10,10}

    ListNode *head1 = NULL, *head2 = NULL;
    head1 = AppendLinkedList(3, head1);
    head1 = AppendLinkedList(7, head1);
    head1 = AppendLinkedList(10, head1);
    printList(head1);
    head2 = AppendLinkedList(1, head2);
    head2 = AppendLinkedList(2, head2);
    head2 = AppendLinkedList(5, head2);
    head2 = AppendLinkedList(8, head2);
    head2 = AppendLinkedList(10, head2);
    printList(head2);

    ListNode *headSorted = mergeTwoLists(head1, head2);
    printList(headSorted);

    return 0;
}