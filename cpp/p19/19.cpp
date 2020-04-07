#include <iostream>
using namespace std;

struct Point
{
  int x;
  int y;
};

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int pointNum = 0;
    cin >> pointNum;

    Point* points = (Point*)malloc(sizeof(Point) * pointNum);

    for(int j = 0 ; j < pointNum ; j++)
    {
      cin >> points[j].x >> points[j].y;    // 꼭짓점들 입력
    }

    int signedAreaSize = 0;

    for(int j = 0 ; j < pointNum - 1 ; j++)  // 계산식 처리
    {
      signedAreaSize += (points[j].x + points[j + 1].x) * (points[j + 1].y - points[j].y);
    }
    signedAreaSize += (points[pointNum - 1].x + points[0].x) * (points[0].y - points[pointNum - 1].y);

    int pointsDir = 0;
    if(signedAreaSize > 0) // 시계/반시계 처리
    {
      pointsDir = 1;
    }
    else if(signedAreaSize < 0)
    {
      pointsDir = -1;
    }
    signedAreaSize *= pointsDir;

    free(points);

    cout << signedAreaSize << " " << pointsDir << endl;
  }

  return 0;
}
