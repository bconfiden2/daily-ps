#include <iostream>
#include <stack>

using namespace std;

string line, answer;

int main(void)
{
    cin >> line;

    stack<char> op;
    for(int i = 0 ; i < line.size() ; i++)
    {
        if(line[i] >= 65) answer.push_back(line[i]); // 문자(피연산자)일 경우 그대로 출력
        else                                         // 연산자일 경우
        {
            switch (line[i])
            {
            case '(':                               // 괄호 열고(우선순위가 가장 높음)
                op.push(line[i]);
                break;
            case ')':                               // 괄호를 닫을때 까지의 남은 연산자들을 전부 출력
                while(op.size() && op.top() != '(')
                {
                    answer += op.top();
                    op.pop();
                }
                op.pop();
                break;
            case '+':
            case '-':
                while(op.size() && op.top() != '(') // 덧셈과 뺄셈은 우선순위가 낮기 때문에 괄호 전까지 전부 출력
                {
                    answer += op.top();
                    op.pop();
                }
                op.push(line[i]);
                break;
            case '*':
            case '/':                               // 곱셈과 나눗셈은 우선순위가 높기 때문에 같은 우선순위를 갖는 연산자들만 출력
                while(op.size() && (op.top() == '*' || op.top() == '/'))
                {
                    answer += op.top();
                    op.pop();
                }
                op.push(line[i]);
                break;
            }
        }
    }
    while(op.size())
    {
        answer += op.top();
        op.pop();
    }
    cout << answer << endl;
}