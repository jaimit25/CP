#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // smaller and equal elements will be pushed into the stack
    stack<int> st;
    vector<int> val;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int map[10000];
    for (int i = n2 - 1; i >= 0; i--)
    {
        // cout << i << endl;
        if (st.empty())
        {
            map[nums2[i]] = -1;
            st.push(nums2[i]);
            val.push_back(-1);
        }
        else
        {
            // when stack is not empty there can be two conditions
            if (st.top() < nums2[i])
            {
                // we need to remove elements from the top
                while (!st.empty() && st.top() < nums2[i])
                {
                    // cout << "popped the element : " << st.top() << endl;
                    st.pop();
                }
                if (st.empty())
                {
                    map[nums2[i]] = -1;
                    st.push(nums2[i]);
                    val.push_back(-1);
                }
                else
                {
                    map[nums2[i]] = st.top();
                    val.push_back(st.top());
                    st.push(nums2[i]);
                }
            }
            else
            {
                // stack top is bigger so this is the greatest element
                map[nums2[i]] = st.top();
                val.push_back(st.top());
                st.push(nums2[i]);
            }
        }
    }
    nums2.clear();
    reverse(val.begin(), val.end());
    for (int i = 0; i < n1; i++)
    {
        nums2.push_back(map[nums1[i]]);
    }

    return nums2;
}

int main()
{
    vector<int> v1 = {4, 1, 2};
    vector<int> v2 = {3, 4, 1, 2};
    v1 = nextGreaterElement(v1, v2);
    for (auto it : v1)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}