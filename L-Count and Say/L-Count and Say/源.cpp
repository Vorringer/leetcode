#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	string countAndSay(int n)
	{
		vector<int>value;
		vector<int>count;
		string result = "1";
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < result.size(); j++)
			{
				if (value.empty())
				{
					value.push_back(result[j] - '0');
					count.push_back(1);
				}
				else
				{
					if (value.back() == result[j] - '0')
					{
						count[count.size() - 1]++;
					}
					else
					{
						value.push_back(result[j] - '0');
						count.push_back(1);
					}
				}
			}
			result.clear();
			for (int i = 0; i < value.size(); i++)
			{
				result.push_back(count[i] + '0');
				result.push_back(value[i] + '0');
			}
			count.clear();
			value.clear();
		}
		return result;
	}
};
int main()
{
	Solution solve;
	cout<<solve.countAndSay(5);
	system("pause");
}