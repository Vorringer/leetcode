#include<iostream>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		bool data[10001] = { false };
		int count = 0;
		for (int i = 2; i<n; i++)
		{
			if (data[i]) continue;
			for (int j = 2; j <= n / i; j++)
			{
				data[j*i] = true;
			}
		}
		for (int i = 2; i < n; i++)
			if (!data[i]) cout << i << " ";
		return count;
	}
};
int main()
{
	Solution solve;
	solve.countPrimes(10000);
	system("pause");
}