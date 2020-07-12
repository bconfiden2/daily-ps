#include <iostream>
#include <stack>
using namespace std;

int n;
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    stack<int> s;                       // 입력값 받을 스택
    stack<int> ans;                     // 답 출력용 스택
    for(int i = 0, data ; i < n ; i++)
    {
        cin >> data;
        s.push(data);
    }

    stack<int> temp;                    // 오른쪽부터 큰 수들을 저장할 스택
    while(!s.empty())                   // 입력값들을 다 처리할때 까지
    {
        if(temp.empty())                // if 나보다 큰 수가 없어서 다 비워졌다면
        {
            ans.push(-1);               // 현재 위치의 답은 -1
            temp.push(s.top());         // 자기 자신을 가장 큰 값으로 스택에 저장
        }
        else                            // else 값이 있을 경우엔
        {
            if(s.top() < temp.top())        // if 그 값이 나보다 클 경우
            {
                ans.push(temp.top());       // 현재 위치의 답이 해당 값
                temp.push(s.top());         // 나보다 앞에 있는 수 보다 내가 클 수도 있으니 일단은 저장
            }
            else                            // else 그 값이 나보다 작을 경우
            {
                temp.pop();                 // 해당 값은 쓸모없어지기 때문에 버리고
                continue;                   // 현재 위치 답 구할때까지 반복
            }
        }
        s.pop();                        // 다음 위치(앞 인덱스)로!
    }

    while(!ans.empty())                 // 답 출력
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << '\n';
}
