#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>>result;
		bool used[1000] = { false };
		vector<int>data;
		map<int, bool>check;
		map<int, int>dup;
		for (int i = 0; i < nums.size(); i++)
		{
			if (dup.find(nums[i]) == dup.end())
				dup[nums[i]] = 1;
			else dup[nums[i]]++;
		}
			for (int i = 0; i<nums.size(); i++)
			{
				if (check.find(nums[i]) != check.end()) continue;
				used[i] = true;
				check[nums[i]] = true;
				dup[nums[i]]--;
				int prev = INT_MIN;
				for (int j = i + 1; j<nums.size(); j++)
				{
					if (nums[j] == prev) continue;
					if (!(nums[j] <= -nums[i] - nums[j]) || used[j]) continue;
					prev = nums[j];
					used[j] = true;
					dup[nums[j]]--;
					if (dup[-nums[i] - nums[j]]>0)
					{
						data.push_back(nums[i]);
						data.push_back(nums[j]);
						data.push_back(-nums[i] - nums[j]);
						result.push_back(data);
						data.clear();
					}
					used[j] = false;
					dup[nums[j]]++;
				}
				used[i] = false;
				dup[nums[i]]++;
			}
			return result;
	}
};
int main()
{
	vector<int>data = { -1, 0, 1, 2, -1, -4 };
	Solution solve;
	vector<vector<int>>result = solve.threeSum(data);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}