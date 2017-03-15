#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int i = 1;
		int j = 1;
		int max = 0;
		int temp;
		int hashmap[128] = {};
		while (j <= s.size())
		{
			temp = hashmap[s[j-1]];
			if (temp >= i ) 
				i = temp + 1;
			hashmap[s[j-1]] = j;
			if (j - i+ 1>max) max = j - i + 1;
			++j;
		}
		return max;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("asdfghas");
	system("pause");
}