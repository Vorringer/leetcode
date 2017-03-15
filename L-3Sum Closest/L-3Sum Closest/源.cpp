#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		bool used[1000] = { false };
		int closest = INT_MAX;
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
				prev = nums[j];
				used[j] = true;
				dup[nums[j]]--;
				for (int k = target;; k++)
				{
					if (k - target == closest) break;
					if (dup[k - nums[i] - nums[j]] > 0)
					{
						closest = k;
						break;
					}
					if (dup[2 * target - k - nums[i] - nums[j]] > 0)
					{
						closest = 2 * target - closest;
						break;
					}
				}
				used[j] = false;
				dup[nums[j]]++;
			}
			used[i] = false;
			dup[nums[i]]++;
		}
		return closest;
	}
};
int main()
{
	vector<int>data = { -1, 2,1,-4 };
	Solution solve;
	int result = solve.threeSumClosest(data, 1);
	cout << result;
	system("pause");
}