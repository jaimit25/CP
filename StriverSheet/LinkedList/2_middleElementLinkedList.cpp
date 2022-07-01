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

int AppendLinkedList(int value, ListNode *hd)
{

    ListNode *temp = new ListNode;
    temp->val = value;
    temp->next = NULL;

    if (hd == NULL)
    {
        // NO NODES IN THE LINKED LIST
        head = temp;
        // hd = temp;
        return 1;
    }
    else
    {
        // NODES ARE ALREADY THERE IN THE LINKED LIST
        while (hd->next != NULL)
            hd = hd->next;

        // pointer hd is pointing at the last node of the linked list
        hd->next = temp;
        return 1;
    }
    return 0;
}

ListNode *middleNode(ListNode *hd)
{

    ListNode *middle = hd;
    ListNode *fast = hd;


    while(fast->next != NULL){
        middle = middle->next;
        fast = fast->next;
        if(fast->next != NULL) fast = fast->next;
    }

   return middle;
}

int main()
{
    AppendLinkedList(1, head);
    AppendLinkedList(2, head);
    AppendLinkedList(3, head);
    AppendLinkedList(4, head);
    AppendLinkedList(5, head);
    printList(head);
    ListNode *m = middleNode(head);
    printList(m);
    return 0;
}