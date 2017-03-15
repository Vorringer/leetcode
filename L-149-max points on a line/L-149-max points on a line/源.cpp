#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<sstream>
#include<set>
using namespace std;

struct Point
{
	double x;
	double y;
	Point(double xx, double yy) :x(xx), y(yy){};
};

class Solution {
public:
	int maxPoints(vector<Point>& points)
	{
		unordered_map<double, int> result;
		int dupe = 0;
		int maxPoints = 0;
		int maxLocal = 0;
		for (int i = 0; i < points.size();i++)
		{
			result.clear();
			maxLocal = 0;
			dupe = 0;
			for (int j=i+1; j<points.size(); j++)
			{
				if (points[i].x == points[j].x && points[i].y==points[j].y)
					dupe++;
				else if (points[i].x==points[j].x)
				{
					if (result.find(MAX) == result.end())
						result.insert(make_pair<double, int>((double)MAX, 2));
					else
						result[MAX]++;
					maxLocal = max(maxLocal, result[MAX]);
				}
				else
				{
					double slope = getSlope(points[i], points[j]);
					if (result.find(slope) == result.end())
						result[slope] = 2;
					else
						result[slope]++;
					maxLocal = max(maxLocal, result[slope]);
				}
			}
			maxPoints = max(maxPoints, maxLocal + dupe);
			maxPoints = max(maxPoints, dupe+1);
		}
		return maxPoints;
	}
private:
	static const int MAX = 10000;

	double getSlope(Point p1, Point p2)
	{
		return (p1.y - p2.y)*1.0 / (p1.x - p2.x);
	}
};
int main()
{
	Solution s;
	vector<Point>test = { Point(1.5, 1.5), Point(1, 1), Point(1, 1) ,Point(0,0),Point(0,0),Point(2,3)};
	cout<< s.maxPoints(test);
	system("pause");
}