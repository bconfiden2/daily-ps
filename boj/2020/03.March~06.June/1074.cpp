#include <iostream>

using namespace std;

int check(int row, int col, int size)
{
    if(size == 1) return 0;                     // 하나일때는 그냥 종료
    int value, nextSize = size / 2;             // nextSize 는 이번 배열의 절반 길이
    value = nextSize * nextSize;                // value 는 4등분 지역이 결정되면 해당 지역에 곱해줄 값
    int r, c;                                   // 4등분한 걸 0,1,2,3 으로 했을 때 어느 곳에 위치할지 결정
    for(r = 0 ; r < 2 ; r++)                  
    {
        bool br = false;
        for(c = 0 ; c < 2 ; c++)
        {
            if((nextSize * r <= row && row < nextSize * (r+1)) &&       // 만약 내가 찾고 싶은 지점이
                    (nextSize * c <= col && col < nextSize * (c+1)))    // 해당 지역에 위치했다면
            {
                br = true;                                              // r 과 c 에 해당 지역 매겨놓고
                break;
            }
        }
        if(br) break;
    }                                                                  
    //     이번 호출에서의 값   +   다음 지역 검사 (다음 배열에 맞게 인덱스 조정)
    return value * (r * 2 + c) + check(row - (r * nextSize), col - (c * nextSize), nextSize);
}

int main(void)
{
    int n, r, c;
    cin >> n >> r >> c;
    int temp = 1;
    for(int i = 0 ; i < n ; i++)
    {
        temp *= 2;                              // 배열에 인덱스를 전부 채우는 것이 아니라
    }                                           // 배열을 계속 4등분하여 내가 찾을 곳에 해당하는 부분만 검사
    cout << check(r, c, temp) << '\n';
}