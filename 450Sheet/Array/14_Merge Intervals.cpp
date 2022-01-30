#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
	// vector<vector<int>> merge(vector<vector<int>> &intervals)
	// {
	// 	// extra copy of vector to return
	// 	vector<vector<int>> mergedintervals;

	// 	// no element in vector name intervals
	// 	if (intervals.size() == 0)
	// 		return mergedintervals;

	// 	// sorting the vector  o(nlogn)
	// 	sort(intervals.begin(), intervals.end());
	// 	vector<int> tempInterval = intervals[0]; // vector of size "2" ie... [1,3]

	// 	// iterating through interval vector
	// 	// it means item as a whole in vector "it can be [1,3] or [2,6]  and not it[0] for [1,3]"
	// 	// it[0] for [1,3] means we are pointing to 1 in the item
	// 	//it is vector itself
	// 	for (auto it : intervals)
	// 	{
	// 		if (it[0] <= tempInterval[1])
	// 		{
	// 			tempInterval[1] = max(it[1], tempInterval[1]);
	// 		}
	// 		else
	// 		{
	// 			mergedintervals.push_back(tempInterval);
	// 			tempInterval = it;  //re-assign other value to temp interval ie next element in it
	// 		}
	// 	}
	// 	mergedintervals.push_back(tempInterval);
	// 	return mergedintervals;
	// }

	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		vector<vector<int>> mergedIntervals;
		int i = 0;
		if (intervals.size() == 0)
			return mergedIntervals;

		vector<int> tempInterval = intervals[0];

		for (auto it : intervals)
		{

			if (it[0] <= tempInterval[1])
			{
				// it is inside interval
				tempInterval[1] = max(it[1], tempInterval[1]);
			}
			else
			{
				mergedIntervals.push_back(tempInterval);
				tempInterval = it;
			}
		}
		mergedIntervals.push_back(tempInterval);
		return mergedIntervals;
	}
};

int main()
{

	return 0;
}