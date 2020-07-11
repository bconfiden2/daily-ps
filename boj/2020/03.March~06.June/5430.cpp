#include <iostream>
using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    for(int tc = 0 ; tc < t; tc++)
    {
        int n, idx = 0, arr[100001];                                // arr 은 정수 배열
        char p[100001], temp;                                       // p 는 입력받을 함수 문자열
        cin >> p >> n >> temp;                                      // 함수문자열 -> 배열갯수 -> '[' 까지 입력
        for(int i = 0, data ; i < n ; i++)
        {
            cin >> arr[i] >> temp;                                  // 정수 입력받아서 배열에 넣고 ',' 까지 입력받음
        }                                                           // (마지막은 ',' 대신 ']')
        if(n == 0) cin >> temp;                                     // 0 일 경우는 ']' 닫는것 처리해줘야함
        int from = 0, to = n - 1, size = n, dir = 1, able = 1;      // from 이 시작점, to 가 끝점, dir 은 순방향/역방향인지
        while(p[idx] != '\0')
        {
            if(p[idx] == 'R')                                       // 만약 함수가 R 이라면
            {
                int temp = from;         
                from = to;                                          // 시작점과 끝점을 바꿔줌 (정수배열을 뒤집기)
                to = temp;
                dir *= -1;                                          // 뒤집어줬으니 방향도 반대방향이라고 표시해줌
            }
            else                                                    // 함수가 D 라면
            {
                if(size == 0)
                {
                    able = 0;                                       // 하나를 빼야되는데 사이즈가 0 이면 에러 처리
                    break;   
                }
                from += dir;                                        // 정상적일 경우는 하나 지워줌
                size--;
            }
            idx++;
        }
        if(able)                                                    // 함수 모두 처리 후 정상처리의 경우
        {
            if(n == 0 || size == 0)                                 // n 혹은 최종 사이즈가 0 이면 [] 만 출력
            {
                cout << "[]" << '\n';
            }
            else
            {
                cout << '[';
                for(int i = from ; i != to ; i += dir)              // 정수 배열 출력
                {                                                   // 단 from 과 to 의 인덱싱에 주의할 것
                    cout << arr[i]<< ',';
                }
                cout << arr[to] << ']' << '\n';
            }
        }
        else cout << "error" << '\n';                               // 비정상 처리는 에러 출력
    }
}