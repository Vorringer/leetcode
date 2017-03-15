#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct data
{
	data(){};
	data(int v) :val(v), used(false){};
	int val;
	bool used;
};
class Solution {
public:

	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
	{
		vector<vector<int>>result;
		vector<int>temp;
		vector<data>can;
		for (int i = 0; i < candidates.size(); i++)
			can.push_back(data(candidates[i]));
		DFS(can, target, result,temp);
		return result;
	}
private:

	void DFS(vector<data>& candidates, int target, vector<vector<int> >&result, vector<int>&temp)
	{
		if (target == 0)
		{
			result.push_back(temp);
			return;
		}
		map<int, bool>visited;
		for (int i = 0; i < candidates.size(); i++)
		{
			if (!candidates[i].used && candidates[i].val <= target && !visited[candidates[i].val])
			{
				if (!temp.empty() && temp.back() > candidates[i].val) continue;
				temp.push_back(candidates[i].val);
				candidates[i].used = true;
				DFS(candidates, target - candidates[i].val, result, temp);
				candidates[i].used = false;
				if (!temp.empty())temp.pop_back();
				visited[candidates[i].val] = true;
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