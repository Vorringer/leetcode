#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2)
	{
		if (word1.size() == 0 && word2.size() == 0) return 0;
		editDis[0][0] = 0;
		for (int i = 1; i <= word1.size(); i++) editDis[i][0] = i;
		for (int i = 1; i <= word2.size(); i++) editDis[0][i] = i;
		for (int i = 1; i <= word1.size(); i++)
		{
			for (int j = 1; j <= word2.size(); j++)
			{
				editDis[i][j] = min(editDis[i - 1][j] + 1, editDis[i][j - 1] + 1);
				editDis[i][j] = min(editDis[i][j], editDis[i - 1][j - 1] + (word1[i-1] == word2[j-1] ? 0 : 1));
			}
		}
		return editDis[word1.size()][word2.size()];
	}
private:
	int editDis[100][100];
};

int main()
{
	Solution s;
	cout << s.minDistance("a", "b");
	system("pause");
}