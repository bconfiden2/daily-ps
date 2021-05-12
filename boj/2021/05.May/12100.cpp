#include <iostream>
#include <vector>

using namespace std;

int N, answer;
unsigned short temp;
vector<vector<unsigned short>> board;

void print(vector<vector<unsigned short>> arr)
{
    cout << "-------------------" << endl;
    for(int r = 0 ; r < N ; r++)
    {
        for(int c = 0 ; c < N ; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

vector<vector<unsigned short>> move(vector<vector<unsigned short>> arr, int flag)
{
    if(flag == 1)       // 상
    {
        for(int c = 0 ; c < N ; c++)
        {
            int reduced = 0;
            int nextPosition = 0;
            bool visited[N];
            for(int i = 0 ; i < N ; i++) visited[i] = false;
            for(int r = 0 ; r < N ; r++)
            {
                if(visited[r]) continue;
                if(r == N-1)
                {
                    if(arr[r][c] == 0) reduced++;
                    else arr[nextPosition][c] = arr[r][c];
                }
                else if(arr[r][c] == 0)
                {
                    visited[r] = true;
                    reduced++;
                }
                else
                {
                    visited[r] = true;
                    int next = r + 1;
                    while(arr[next][c] == 0 && next < N-1)
                    {
                        visited[next] = true;
                        next++;
                        reduced++;
                    }

                    arr[nextPosition][c] = arr[r][c];
                    if(arr[r][c] == arr[next][c])
                    {
                        arr[nextPosition][c] *=  2;
                        reduced++;
                        visited[next] = true;
                        r = next;
                    }
                    nextPosition++;
                }
            }
            for(int r = 0 ; r < reduced ; r++)
            {
                arr[N-1-r][c] = 0;
            }
        }
    }
    else if(flag == 2)  // 하
    {
        for(int c = 0 ; c < N ; c++)
        {
            int reduced = 0;
            int nextPosition = N-1;
            bool visited[N];
            for(int i = 0 ; i < N ; i++) visited[i] = false;
            for(int r = N-1 ; r >= 0 ; r--)
            {
                if(visited[r]) continue;
                if(r == 0)
                {
                    if(arr[0][c] == 0) reduced++;
                    else arr[nextPosition][c] = arr[0][c];
                }
                else if(arr[r][c] == 0)
                {
                    visited[r] = true;
                    reduced++;
                }
                else
                {
                    visited[r] = true;
                    int next = r - 1;
                    while(arr[next][c] == 0 && next > 1)
                    {
                        visited[next] = true;
                        next--;
                        reduced++;
                    }
                    arr[nextPosition][c] = arr[r][c];
                    if(arr[r][c] == arr[next][c])
                    {
                        arr[nextPosition][c] *= 2;
                        reduced++;
                        visited[next] = true;
                        r = next;
                    }
                    nextPosition--;
                }
            }
            for(int r = 0 ; r < reduced ; r++)
            {
                arr[r][c] = 0;
            }
        }
    }
    else if(flag == 3)  // 좌
    {
        for(int r = 0 ; r < N ; r++)
        {
            int reduced = 0;
            int nextPosition = 0;
            bool visited[N];
            for(int i = 0 ; i < N ; i++) visited[i] = false;
            for(int c = 0 ; c < N ; c++)
            {
                if(visited[c]) continue;
                if(c == N-1)
                {
                    if(arr[r][c] == 0) reduced++;
                    else arr[r][nextPosition] = arr[r][c];
                }
                else if(arr[r][c] == 0)
                {
                    visited[c] = true;
                    reduced++;
                }
                else
                {
                    visited[c] = true;
                    int next = c + 1;
                    while(arr[r][next] == 0 && next < N-1)
                    {
                        visited[next] = true;
                        next++;
                        reduced++;
                    }
                    arr[r][nextPosition] = arr[r][c];
                    if(arr[r][c] == arr[r][next])
                    {
                        arr[r][nextPosition] *= 2;
                        reduced++;
                        visited[next] = true;
                        c = next;
                    }
                    nextPosition++;
                }
            }
            for(int c = 0 ; c < reduced ; c++)
            {
                arr[r][N-1-c] = 0;
            }
        }
    }
    else                // 우
    {
        for(int r = 0 ; r < N ; r++)
        {
            int reduced = 0;
            int nextPosition = N-1;
            bool visited[N];
            for(int i = 0 ; i < N ; i++) visited[i] = false;
            for(int c = N-1 ; c >= 0 ; c--)
            {
                if(visited[c]) continue;
                if(c == 0)
                {
                    if(arr[r][0] == 0) reduced++;
                    else arr[r][nextPosition] = arr[r][0];
                }
                else if(arr[r][c] == 0)
                {
                    visited[c] = true;
                    reduced++;
                }
                else
                {
                    visited[c] = true;
                    int next = c - 1;
                    while(arr[r][next] == 0 && next > 1)
                    {
                        visited[next] = true;
                        next--;
                        reduced++;
                    }
                    arr[r][nextPosition] = arr[r][c];
                    if(arr[r][c] == arr[r][next])
                    {
                        arr[r][nextPosition] *= 2;
                        reduced++;
                        visited[next] = true;
                        c = next;
                    }
                    nextPosition--;
                }
            }
            for(int c = 0 ; c < reduced ; c++)
            {
                arr[r][c] = 0;
            }
        }
    }
    // print(arr);
    return arr;
}

int bruteforce(vector<vector<unsigned short>> arr, int depth)
{
    if(depth >= 5)
    {
        int maxi = 0;
        for(int r = 0 ; r < N ; r++)
        {
            for(int c = 0 ; c < N ; c++)
            {
                if(arr[r][c] > maxi) maxi = arr[r][c];
            }
        }
        return maxi;
    }
    int maxret = 0;
    for(int i = 1 ; i <= 4; i++)
    {
        int temp = bruteforce(move(arr, i), depth + 1);
        if(temp > maxret) maxret = temp;
    }
    return maxret;
}

int main(void)
{
    cin >> N;
    for(int r = 0 ; r < N ; r++)
    {
        vector<unsigned short> a;
        for(int c = 0 ; c < N ; c++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        board.push_back(a);
    }
    
    // move(move(move(move(move(board, 1), 4), 3),2),1);
    
    cout << bruteforce(board, 0) << endl;
}