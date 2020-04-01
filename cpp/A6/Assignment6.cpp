/*************************************************************
*                                                            *
*  Problem : 시간 계산                                         *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>

using namespace std;

int WorkToSeconds(int, int, int);
void SecondsToWork(int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int employeeNum = 0;
    cin >> employeeNum;

    int sum = 0;

    for(int j = 0 ; j < employeeNum ; j++)
    {
      int H = 0, M = 0, S = 0, h = 0, m = 0, s = 0;
      cin >> H >> M >> S >> h >> m >> s;

      sum += WorkToSeconds(h, m, s) - WorkToSeconds(H, M, S);
    }

    SecondsToWork(sum);
  }

  return 0;
}

int WorkToSeconds(int h, int m, int s)
{
  int sum = 3600 * h + 60 * m + s;
  return sum;
}
void SecondsToWork(int sum)
{
  int day = 0, hour = 0, minute = 0, second = 0;

  day = sum / (3600 * 24);
  sum %= (3600 * 24);

  hour = sum / 3600;
  sum %= 3600;

  minute = sum / 60;
  sum %= 60;

  second = sum;

  cout << day << " " << hour << " " << minute << " " << second << endl;
}
