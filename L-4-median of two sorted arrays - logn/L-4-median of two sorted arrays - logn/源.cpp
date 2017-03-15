#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		int total = size1 + size2;
		if (total == 0) return 0;
		if (total == 1) return size1 == 0 ? nums2[0] : nums1[0];
		if (total & 1)
			return findKth(nums1, nums2, (size1 + size2) / 2, 0, size1, 0, size2);
		else
			return 0.5*(findKth(nums1, nums2, (size1 + size2) / 2, 0, size1, 0, size2) + findKth(nums1, nums2, (size1 + size2) / 2 -1, 0, size1, 0, size2));
	}
private:
	int findKth(vector<int>& nums1, vector<int>& nums2, int k, int begin1, int end1, int begin2, int end2)
	{
		if (end1 - begin1 > end2 - begin2) return findKth(nums2, nums1, k, begin2, end2, begin1, end1);
		if (end1 - begin1 == 0) return nums2[k + begin2];
		if (k == 0) return min(nums1[begin1], nums2[begin2]);
		int pos1 = min((k - 1) / 2, end1 - begin1 - 1) + begin1;
		int pos2 = k - 1 - pos1 + begin1 + begin2;
		int compare1 = nums1[pos1];
		int compare2 = nums2[pos2];
		if (compare1 == compare2)
			return compare1;
		else if (compare1 < compare2)
			return findKth(nums1, nums2, k - pos1 - 1 + begin1, pos1 + 1, end1, begin2, end2);
		else return findKth(nums1, nums2, k - pos2 - 1 + begin2, begin1, end1, pos2 + 1, end2);
	}
};

int main()
{
	Solution s;
	vector<int>nums1 = { 1,2};
	vector<int>nums2 = {1,2 };
	cout << s.findMedianSortedArrays(nums1, nums2);
	system("pause");
}