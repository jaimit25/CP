#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isAnagram(string str1, string str2)
	{
		unordered_map<char, int> map;
		int l = str1.length();
		int m = str2.length();

		if (l != m)
		{
			return 0;
		}
		for (int i = 0; i < l; i++)
			map[str1[i]]++;
		for (int i = 0; i < l; i++)
			map[str2[i]]--;

		unordered_map<char, int>::iterator itr;
		for (itr = map.begin(); itr != map.end(); itr++)
		{
			if (itr->second != 0)
				return 0;
		}
		// cout << itr->first << "  " << itr->second << endl;

		return 1;
	}

	vector<vector<string> > Anagrams(vector<string> &string_list)
	{

		unordered_map<string, vector<string> > mp;
		vector<vector<string> > ans;
		for (auto it : string_list)
		{
			string temp = it;
			sort(it.begin(), it.end());
			mp[it].push_back(temp);
		}
		for (auto it : mp)
		{
			ans.push_back(it.second);
		}
		return ans;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<string> string_list(n);
	for (int i = 0; i < n; ++i)
		cin >> string_list[i];
	Solution ob;
	vector<vector<string> > result = ob.Anagrams(string_list);
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}