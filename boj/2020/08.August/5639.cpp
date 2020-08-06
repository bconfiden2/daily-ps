#include <iostream>
#include <vector>

using namespace std;

vector<int> data;

void post(int begin, int end)               // begin 은 노드 시작점, end 는 마지막 점 (포함하지 않음)
{
    if(begin >= end)                        // 인덱스 초과 시 그냥 종료
    {
        return;
    }
    if(begin == end - 1)                    // 마지막 노드일 시 출력 후 종료
    {
        cout << data[begin] << '\n';
        return;
    }
    int idx;
    for(idx = begin ; idx < end ; idx++)    // 피봇 idx 를 설정 
    {                                       // 양쪽 서브트리를 나눠주는 값으로 지정 (처음으로 나오는 오른쪽 노드값)
        if(data[idx] > data[begin]) break;
    }
    post(begin + 1, idx);                   // 왼쪽 서브트리 재귀 호출
    post(idx, end);                         // 오른쪽 서브트리 재귀 호출
    cout << data[begin] << '\n';            // 노드값 출력
}

int main(void)
{
    int temp;
    do
    {
        cin >> temp;
        data.push_back(temp);
    } while(getc(stdin) == '\n');                           // 개행이 입력될때마다 값 하나씩 입력해서 data 에 집어넣음
    
    if(data[data.size() - 1] == data[data.size() - 2])      // 입력값이 종료될 때 개행문자가 들어간 뒤 종료되면, getc(stdin) 에서 참으로 확인하여 temp 를 한 번 더 넣게 된다.
    {
        data.pop_back();                                    // 만약 뒤의 두개 값이 같은 값이라면 하나를 지워주는 작업
    }

    post(0, data.size());
}