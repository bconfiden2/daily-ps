/*************************************************************
*                                                            *
*  Problem : 수직/수평 선분의 교차
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/

#include <iostream>
using namespace std;

void Swap(int*, int*);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int hx1, hy1, hx2, hy2;
    int vx1, vy1, vx2, vy2;

    int vertical = 0;
    int horizontal = 0;

    int result = 0;

    cin >> hx1 >> hy1 >> hx2 >> hy2;
    cin >> vx1 >> vy1 >> vx2 >> vy2;

    if(hx1 == hx2) // 1번 선분이 수직, 2번 선분이 수평 일때
    {
      Swap(&hx1, &vx1);
      Swap(&hy1, &vy1);
      Swap(&hx2, &vx2);
      Swap(&hy2, &vy2);  // 1번 선분을 수평, 2번 선분을 수직으로 만든다.
    }
    if(hx1 > hx2)
    {
      Swap(&hx1, &hx2);  // 수평선분 왼쪽 점이 1번점에 들어가게
    }
    if(vy1 > vy2)
    {
      Swap(&vy1, &vy2);  // 수직선분 아랫 점이 1번점에 들어가게
    }

    horizontal = hy1;
    vertical = vx1;

    if((hx1 <= vertical && hx2 >= vertical) && (vy1 <= horizontal && vy2 >= horizontal))
    {
      if((hx1 == vertical || hx2 == vertical) || (vy1 == horizontal || vy2 == horizontal))
      {
        result = 2;
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      result = 0;
    }

    //cout << hx1 << " " << hy1 << " " << hx2 << " " << hy2 << endl;
    //cout << vx1 << " " << vy1 << " " << vx2 << " " << vy2 << endl;
    cout << result << endl;
  }
}

void Swap(int* a, int* b)
{
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}
