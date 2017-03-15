#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:

	vector<vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>>result;
		vector<int>temp;
		DFS(candidates, target, result, temp);
		return result;
	}
private:

	void DFS(vector<int>& candidates, int target, vector<vector<int> >&result, vector<int>&temp)
	{
		if (target == 0)
		{
			result.push_back(temp);
			return;
		}
		map<int, bool>visited;
		for (int i = 0; i < candidates.size(); i++)
		{
			if ( candidates[i] <= target && !visited[candidates[i]])
			{
				if (!temp.empty() && temp.back() > candidates[i]) continue;
				temp.push_back(candidates[i]);
				DFS(candidates, target - candidates[i], result, temp);
				if (!temp.empty())temp.pop_back();
				visited[candidates[i]] = true;
			}

		}
	}
};
int main()
{
	Solution solve;
	vector<int>c = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>>result = solve.combinationSum2(c, 8);
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