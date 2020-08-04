#include <iostream>

using namespace std;

struct Node         // 노드 구조체 선언
{
    int parent;
    int left;
    int right;
};

Node nodes[27];
char p, r, l;
int n;

void func(int idx, int dir)                 // dir 이 전위, 중위, 후위를 구분해주는 값
{
    if(idx < 0) return;                     // 자식 노드가 비어있을 경우 (.) 재귀 종료

    if(dir == 0) cout << char(idx + 65);    // 루트 노드의 경우는 dir 에 따라 위치가 달라짐
    func(nodes[idx].left, dir);             // 왼쪽 노드로 진입
    if(dir == -1) cout << char(idx + 65);
    func(nodes[idx].right, dir);            // 오른쪽 노드로 진입
    if(dir == 1) cout << char(idx + 65);
}

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p >> l >> r;
        nodes[p-65].left = l - 65;           // 입력 정보를 가지고 노드 간 부모 자식 연결
        nodes[p-65].right = r - 65;
        nodes[l-65].parent = p - 65;
        nodes[r-65].parent = p - 65;
    }
    func(0, 0);                              // 전위
    cout << '\n';
    func(0, -1);                             // 중위
    cout << '\n';
    func(0, 1);                              // 후위
    cout << '\n';
}