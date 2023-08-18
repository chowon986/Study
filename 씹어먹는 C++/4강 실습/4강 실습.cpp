// 4강 실습

#include <iostream>
#include <stdlib.h>
using namespace std;

class Point 
{
public:
    int x, y;

public:
    Point(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
};

class Geometry 
{
public:
    Geometry() 
    {
        num_points = 0;
    }

    void AddPoint(const Point& point) 
    {
        point_array[num_points++] = new Point(point.x, point.y);
    }

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    void PrintNumMeets();

    double GetDistance(Point* a, Point* b)
    {
        int x = abs(a->x - b->x);
        int y = abs(a->y - b->y);

        return sqrt(pow(x, 2) + pow(y, 2));
    }

private:
    // 점 100 개를 보관하는 배열.
    Point* point_array[100];
    int num_points;
};

void Geometry::PrintDistance()
{
    for (int i = 0; i < num_points - 1; i++)
    {
        for (int j = i + 1; j < num_points; j++)
        {
            std::cout << point_array[i]->x << ", " << point_array[i]->y << " 와 " <<
                point_array[j]->x << ", " << point_array[j]->y << " 사이의 거리 : " << GetDistance(point_array[i], point_array[j]) << '\n';
        }
    }
}

void Geometry::PrintNumMeets()
{
    int cross = num_points;

    for (int i = 0; i < num_points - 1; ++i)
    {
        for (int j = i + 1; j < num_points; ++j)
        {
			int a = point_array[j]->y - point_array[i]->y;
			int b = point_array[i]->x - point_array[j]->x;
			int c = -(a * point_array[i]->x + b * point_array[j]->y);
			for (int k = 0; k < num_points - 1; ++k)
			{
				if (k == i) continue;
				for (int l = k + 1; l < num_points; ++l)
				{
					if (l == j) continue;
					if ((a * point_array[k]->x + b * point_array[k]->y + c) * (a * point_array[l]->x + b * point_array[l]->y + c) <= 0) ++cross;
				}
			}
		}
	}
	std::cout << "Total cross points: " << cross << std::endl;
}

int main()
{
    Point p1(2, 5);
    Point p2(1, 1);

    Geometry geo;
    geo.AddPoint(p1);
    geo.AddPoint(p2);

    geo.PrintDistance();
    geo.PrintNumMeets();
}