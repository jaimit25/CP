#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void printv(vvi v)
{
    for (auto it : v)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]," << endl;
    }
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
         
    vector<vector<int> > ans;

    int i = 0;
    if (intervals.size() == 0)
        return ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
   
    for (int i = 0; i < n; i++)
    {
        if (temp[1] >= intervals[i][0])
        {
            // lies in interval
            temp[1] = max(intervals[i][1], temp[1]);
        }
        else
        {
            // does not lies in interval
            ans.push_back(temp);

            temp = intervals[i];
            // or
            // temp.clear();
            // temp.push_back(intervals[i][0]);
            // temp.push_back(intervals[i][1]);
        }
    }
    ans.push_back(temp);
    return ans;
}

int main()
{
    // type Code
    vvi inter = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    inter = merge(inter);
    printv(inter);

    return 0;
}