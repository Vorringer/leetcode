#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		Node** adlist = new Node*[numCourses];
		memset(adlist, 0, numCourses*sizeof(Node*));
		int count = 0;
		int indegree[10000] = { 0 };
		vector<int>result;
		queue<int>q;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			Node* temp = new Node(prerequisites[i].first);
			if (!adlist[prerequisites[i].second]) adlist[prerequisites[i].second] = new Node(prerequisites[i].second);
			temp->next = adlist[prerequisites[i].second]->next;
			indegree[temp->index]++;
			adlist[prerequisites[i].second]->next = temp;
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0) q.push(i);
		}
		while (q.size())
		{
			int index = q.front();
			Node* temp = adlist[index];
			q.pop();
			result.push_back(index);
			count++;
			if (!temp) continue;
			while (temp->next)
			{
				temp = temp->next;
				if (--indegree[temp->index] == 0)
					q.push(temp->index);
			}
		}
		if (count != numCourses) return{};
		return result;
	}
private:
	struct Node
	{
		int index;
		Node* next;
		Node(){};
		Node(int id) :next(NULL), index(id){};
	};
};

int main()
{
	Solution s;
	vector<pair<int, int>>test = { make_pair(1, 0), make_pair(2, 0), make_pair(3, 1), make_pair(3, 2) };
	vector<int>result = s.findOrder(4, test);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	system("pause");
}