#include <iostream>
#include <stack>

using namespace std;

int idx;
string line, target, answer;                                                // 스택을 사용하지만, 최근 sz 만큼 랜덤액세스가 가능해야 해서 문자열로 함

int main(void)
{
    cin >> line;
    cin >> target;
    int sz = target.size();

    for(int i = 0 ; i < sz - 1 ; i++) answer.push_back(line[i]);            // 검사 조건 따로 넣기 싫어서 아예 시작을 sz-1 부터 함
    for(int i = sz - 1 ; i < line.size() ; i++)
    {
        answer.push_back(line[i]);                                          // 일단 스택(문자열)에 무조건 넣어줌

        if(line[i] == target[sz - 1])                                       // 그런데 만약 폭발문자열의 마지막 문자와 같을 경우에
        {
            for(idx = 0 ; idx < sz ; idx++)                                 // 스택의 최근 sz 만큼과 폭발문자열을 비교해서
            {
                if(answer[answer.size() - sz + idx] != target[idx]) break;
            }
            if(idx == sz)                                                   // 만약 폭발한다면 sz 만큼 스택에서 pop 해서 폭발 처리
            {
                for(int n = 0 ; n < sz ; n++) answer.pop_back();
            }                                                               // 폭발 안한다면, 스택 그대로 유지하면서 다음 끝문자 나올때까지 반복
        }
    }

    cout << (answer.size() ? answer : "FRULA") << endl;
}