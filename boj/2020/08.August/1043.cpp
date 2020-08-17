#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> know;               // 입력으로 주어진, 기존에 알고있던 사람들
vector<vector<int>> party;      // 각 파티에 참여하는 사람들
int parent[51];                 // 모든 사람들을 그룹화시키는 배열
int num, temp;

int find(int idx)               // 해당 사람의 최종 그룹을 반환 (루트 노드)
{
    if(idx != parent[idx]) idx = find(parent[idx]); // 루트노드가 아닐 시 해당 노드의 부모 노드로 재귀 호출
    return idx;
}

void union_(int x, int y)       // 두 사람을 그룹화시킴 (루트 노드를 같게 만듦)
{
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(void)
{
    cin >> n >> m;
    cin >> num;

    for(int i = 0 ; i < num ; i++)
    {
        cin >> temp;
        know.push_back(temp);
    }
    for(int i = 1 ; i <= n ; i++) parent[i] =i;

    for(int i = 0 ; i < m ; i++)                    // 모든 파티들에 대해서 서로 연결시키는 과정
    {
        cin >> temp;
        vector<int> member;
        cin >> num;
        member.push_back(num);
        int prev;
        for(int k = 1 ; k < temp ; k++)             // 각 파티의 멤버들을 같은 그룹으로 묶어놓음
        {
            prev = num;
            cin >> num;
            union_(prev, num);                      // 묶는 과정에서 다른 파티원과도 연결될 수 있음
            member.push_back(num);
        }
        party.push_back(member);
    }
    for(int i = 0 ; i < know.size() ; i++)
    {
        know[i] = find(know[i]);
    }

    for(int i = 0 ; i < m ; i++)                    // 모든 파티들을 돌면서
    {
        bool able = true;
        for(int j = 0 ; j < party[i].size() ; j++)  // 각 파티의 멤버들 중
        {
            int root = find(party[i][j]);
            for(int k = 0 ; k < know.size() ; k++)
            {
                if(root == know[k])                 // 한명이라도 진실을 알고있는 사람과 같은 그룹에 있다면
                {
                    able = false;                   // 해당 파티를 세지 않음
                    break;
                }
            }
            if(able == false) break;
        }
        if(able) ans++;                             // 해당 파티에 아무도 진실을 아는 그룹과 엮여있지 않을 때에만 카운트
    }
    cout << ans << endl;
}