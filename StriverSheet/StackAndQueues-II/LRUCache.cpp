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
    ListNode *next, *prev;
    // Constructor
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next)
    {

        this->val = x;
        this->next = next;
    }
} * head;

class LRUCache
{
public:
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
        temp->prev = NULL;
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
            temp->prev = hd;
            return head_node;
        }
        return head_node;
    }

    LRUCache(int capacity)
    {
        // consructor
    }

    int get(int key)
    {
        // get element from the cache
    }

    void put(int key, int value)
    {
        // put element into the doubly linked list
    }
};

int main()
{

    ListNode *head = NULL;
    LRUCache cache(2);

    head = cache.AppendLinkedList(1, head);
    head = cache.AppendLinkedList(2, head);
    head = cache.AppendLinkedList(3, head);
    head = cache.AppendLinkedList(4, head);
    cache.printList(head);

    return 0;
}