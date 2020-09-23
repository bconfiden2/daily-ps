#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    string line;
    cin >> line;

    int answer = 0;
    stack<bool> s;
    for(int i = 0 ; i < line.size() - 1 ; i++)  // 뒤에서 하나 전까지 탐색한다
    {
        if(line[i] == '(')
        {
            if(line[i+1] == ')')    // 만약 레이저로 입력된 ( 라면
            {
                answer += s.size(); // 레이저로 현재 스택에 있는 파이프들을 다 잘라주고
                i++;                // 레이저로 닫히는 ) 스킵처리
            }
            else s.push(true);      // 만약 쇠파이프 추가라면 스택에 파이프 추가
        }
        else                // 쇠파이프가 닫힐 경우엔
        {
            answer++;       // 해당 쇠파이프 조각 하나 추가
            s.pop();        // 쇠파이프 제거
        }
    }
    answer += s.size();     // 맨 마지막에 레이저가 왔을 수도 있기 때문에 따로 처리

    cout << answer << endl;
}

/***********************************
#include <stdio.h>
#include <string.h>

int main()
{
    int l = 0, k = 0;
    char r[100000] = {};
    scanf("%s", r);
    int sz = strlen(r);
    
    for(int i = 0 ; i < sz ; i++)
    {
        if(r[i] == '(')
        {
            if(r[i+1] == ')')
            {
                i++;
                l += k;
            }
            else k++;
        }
        else
        {
            l++;
            k--;
        }
    }
    printf("%d\n", l);
}
*************************************/