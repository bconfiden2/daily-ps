/*************************************************************
*                                                            *
*  Problem : 부활절날짜계산                                      *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>
using namespace std;

void CalcMonthDate(int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int year = 0;
    cin >> year;

    CalcMonthDate(year);
  }

  return 0;
}

void CalcMonthDate(int y)
{
  int month = 0, date = 0;

  int c = y / 100;  //2번
  int n = y - (y/19) * 19; //3번
  int t = (c-17) / 25; //4번
  int i = (c - (c/4) - (c-t) / 3) + (n * 19 + 15); //5번 6번 7번
  int j = i - (i/30) * 30; //8번
  int k = j - ((j/28) * (1 - j/28) * (29 / (j+1)) * ((21-n) / 11)); // 9번 10번 11번 12번 13번
  int l = (y + (y/4) + j + 2) - c + (c/4); //14번 15번
  int p = l - (l/7) * 7; // 16번
  int q = k - p; //17번

  month = (q+40) / 44 + 3; //18번
  date = (q+28) - ((month/4) * 31); //19번

  cout << month << " " << date << endl;
}
