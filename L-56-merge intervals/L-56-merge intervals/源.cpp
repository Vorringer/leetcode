#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		vector<Interval>result;
		sort(intervals.begin(), intervals.end(), compare);
		int i = 0;
		int j = 0;
		while (i<intervals.size())
		{
			j = i;
			int start = intervals[i].start;
			int end = intervals[i].end;
			while (j<intervals.size() && intervals[j].start <= intervals[i].end)
			{
				intervals[i].end = intervals[j].end;
				j++;
			}
			i = j + 1;
			result.push_back(Interval(start, end));
		}
		return result;
	}
private:
	bool compare(const Interval& i1, const Interval& i2)
	{
		return i1.start < i2.start;
	}
};