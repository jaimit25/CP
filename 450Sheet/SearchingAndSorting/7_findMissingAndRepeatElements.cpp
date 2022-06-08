#include <bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution
{
public:
    int *findTwoElement(int *a, int n)
    {
        int *answer = new int[2];
        int i = 0;
        int value = 0;
        int element = 0;

        for (i = 0; i < n; i++)
        {
            value = abs(a[i]);
            element = a[value - 1];
            if (element > 0)
                a[value - 1] = -element;
            else
                answer[0] = value;
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                answer[1] = i + 1;
                break;
            }
        }
        return answer;
    }
};

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    int *ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}