#include<string>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	string largestNumber(vector<int>& nums)
	{
		string result = "";
		//priority_queue<int, vector<int>, compare> heap;
		sort(nums.begin(), nums.end(), compare);
		char temp[20];
		
		for (int i = nums.size()-1; i >=0;i--)
		{
			int top = nums[i];
			if (top == 0 && result.size() == 1 && result[0] == '0')
			{
				continue;
			}
			sprintf_s(temp, "%d", top);
			string s = temp;
			result += s;
		}
		return result;
	}
private:

		static bool compare(int a, int b)
		{
			char tempA[20];
			char tempB[20];
			sprintf_s(tempA, "%d", a);
			sprintf_s(tempB, "%d", b);
			int sizeA = strlen(tempA);
			int sizeB = strlen(tempB);
			int size = min(sizeA, sizeB);
			int i = 0;
			while (i<size && tempA[i] == tempB[i]) ++i;
			if (i == size)
			{
				if (sizeA == sizeB) return false;
				if (sizeA>sizeB)
				{
					memcpy((char*)tempA + sizeA, tempB, size + 1);
					int j = 0;
					while (j<sizeA)
					{
						if (tempA[j] == tempA[j + size])
						{
							++j;
						}
						else
						{
							return tempA[j + size] < tempA[j];
						}
					}
					return false;
				}
				else
				{
					memcpy(tempB + sizeB, tempA, size + 1);
					int j = 0;
					while (j<sizeB)
					{
						if (tempB[j] == tempB[j + size])
						{
							++j;
							continue;
						}
						return tempB[j + size] > tempB[j];
					}
					return false;
				}
			}
			return tempA[i] < tempB[i];
		}
};

int main()
{
	Solution s;
	vector<int>test = { 0,0};
	cout<< s.largestNumber(test);
	system("pause");
}