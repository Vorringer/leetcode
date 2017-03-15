#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

class Solution 
{
public:
	int numIslands(vector<vector<char> >& grid)
	{
		if (!grid.size()) return 0;
		initialize(grid.size()*grid[0].size());
		int count = -1;
		int result = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				count++;
				if (grid[i][j] == '0')
				{
					a[count] = INT_MAX;
					continue;
				}
				if (i == 0 && j == 0) continue;
				if (j == 0)
				{
					if (grid[i - 1][j] == '1')
					{
						int root1 = findRoot(count);
						int root2 = findRoot(count - grid[i].size());
						unionSet(root1, root2);
					}
				}
				else if (i == 0)
				{
					if (grid[i][j - 1] == '1')
					{
						int root1 = findRoot(count);
						int root2 = findRoot(count - 1);
						unionSet(root1, root2);
					}
				}
				else 
				{
					int root1, root2, root3;
					root1 = findRoot(count);
					if (grid[i - 1][j] == '1')
					{
						root2 = findRoot(count - grid[i].size());
						unionSet(root1, root2);
						root1 = findRoot(root1);
					}
					if (grid[i][j - 1] == '1')
					{
						root3 = findRoot(count - 1);
						unionSet(root1, root3);
					}
				}
			}
		}
		for (int i = 0; i <= count; i++)
		{
			if (a[i] < 0 && a[i]!=INT_MAX) ++result;
		}
		delete[] a;
		return result;
	}
private:
	int *a;
	int findRoot(int i)
	{
		if (a[i] < 0) return i;
		a[i] = findRoot(a[i]);
		return a[i];
	}
	void initialize(int num)
	{
		a = new int[num];
		memset((char*)a, 0xFF, num*sizeof(int));
	}
	void unionSet(int root1, int root2)
	{
		if (root1 == root2) return;
		if (a[root1]>a[root2])
		{
			a[root2] += a[root1];
			a[root1] = root2;
		}
		else
		{
			a[root1] += a[root2];
			a[root2] = root1;
		}
	}
};
int main()
{
	Solution s;
	vector<vector<char>>v;
	ifstream ifs("data.txt");
	int l, h;
	char ch;
	ifs >> l >> h;
	for (int i = 0; i < l; i++)
	{
		v.push_back({});
		for (int j = 0; j < h; j++)
		{
			ifs >> ch;
			v[i].push_back(ch);
		}
	}
	cout<<s.numIslands(v);
	system("pause");
	return 0;
}