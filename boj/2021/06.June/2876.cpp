#include <iostream>

using namespace std;

int N, A, B;
int grades[100001][6];      // i 번째 책상까지 j 번째 등급의 최대 연속 값을 담는 dp 배열
int maxval, maxidx;

int main(void)
{
    cin >> N;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> A >> B;
        grades[i][A] = grades[i-1][A] + 1;      // 이전 책상까지의 값 + 1
        if(grades[i][A] > maxval)               // 최댓값 갱신
        {
            maxval = grades[i][A];
            maxidx = A;
        }
        if(A != B)                              // A 와 B 값이 같으면 하나만 처리해줘야 함
        {
            grades[i][B] = grades[i-1][B] + 1;  // 다를 경우에는 B 값에 대해서도 똑같은 처리
            if(grades[i][B] > maxval)
            {
                maxval = grades[i][B];
                maxidx = B;
            }
        }
    }
    cout << maxval << " " << maxidx << endl;
}