#include <iostream>
#include <list>

using namespace std;

int M;
string start;
char input, value;
list<char> dll;
list<char>::iterator cur;                   // 커서 위치는, 이터레이터의 원소와 앞 원소 사이 위치

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> start;
    int N = start.size();
    for(int i = 0 ; i < N ; i++)
    {
        dll.push_back(start[i]);            // 처음 입력받는 문자열을 다 넣어준 뒤
    }
    cur = dll.end();                        // 커서를 맨 뒤로 옮김

    cin >> M;
    for(int i = 0 ; i < M ; i++)
    {
        cin >> input;
        switch (input)
        {
        case 'L':
            if(cur != dll.begin()) cur--;   // 맨 앞이 아닐 경우 커서 왼쪽으로 이동
            break;
        case 'D':
            if(cur != dll.end()) cur++;     // 맨 뒤가 아닐 경우 커서 오른쪽으로 이동
            break;
        case 'B':
            if(cur != dll.begin()) cur = dll.erase(--cur);  // 맨 앞이 아닐 경우, 앞의 원소 삭제 후 위치 갱신
            break;
        default:
            cin >> value;
            dll.insert(cur, value);         // 현재 위치에 원소 추가
            break;
        }
    }

    for(cur = dll.begin() ; cur != dll.end() ; cur++)
    {
        cout << *cur;
    }
    cout << endl;
}