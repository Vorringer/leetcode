#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	
}; 
class Solution {
public:
	int maxPoints(vector<Point>& points) 
	{
		unordered_map<double, int>Map;
		int max = -1;
		int ver = 0;
		for (int i = 0; i < points.size(); i++)
		{
			for (int j = i+1; j < points.size(); j++)
			{
				if (points[i].x == points[j].x)
				{
					if (points[i].y == points[j].y)  continue;
					if (ver == 0) ver = 1;
					else ver++;
					continue;
				}
				double slope = (points[j].y - points[i].y)*1.0 / (points[j].x - points[i].x);
				if (Map[slope] == 0) Map[slope] = 1;
				else Map[slope]++;
				if (Map[slope]>max) max = Map[slope];
			}
		}
		if (ver>max) max = ver;
		if (points.size() == 1) return 1;
		if (max == 0) return 0;
		return (1 + sqrt(1 + 8 * max)) / 2;
	}
};
int main()
{
	Solution solve;
	vector<Point>points = { Point(0, 0), Point(0, 1), Point(0, 2) };
	cout<< solve.maxPoints(points);
	system("pause");
}