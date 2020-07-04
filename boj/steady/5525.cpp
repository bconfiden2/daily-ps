#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n, m, num = 0;
    cin >> n >> m;
    string line;
    cin >> line;
    int temp = 0;
    for(int i = 0 ; i < m - 2 ; i++)
    {
        if(line[i] == 'I' && line[i+1] == 'O' && line[i+2] == 'I')     // IOI 패턴이 나올 때 마다
        {
            temp++;                                                    // 패턴이 한번 나왔다고 표시
            if(temp == n)                                              // 패턴이 내가 찾으려는 P(n) 까지 도달했으면
            {
                num++;                                                 // 카운트 1 추가
                temp--;                                                // 다음 반복되는 패턴을 위해 IOI 패턴 1 감소
            }
        }
        else if((line[i] == 'I' && line[i+1] == 'I') || (line[i] == 'O' && line[i+1] == 'O')) // 중간에 끊길 시
        {
            temp = 0;                                                                         // IOI 패턴 초기화
        }
    }
    cout << num << '\n';
}