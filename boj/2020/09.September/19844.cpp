#include <iostream>
#include <vector>

using namespace std;

int number;
string temp;
vector<string> lines;
char moum[6] = {'a','e','i','o','u','h'};
char uppe[8] = {'c','j','n','m','t','l','d','s'};

int main(void)
{
    do
    {
        cin >> temp;                                        // 띄어쓰기 단위로 문자열 입력 받음
        lines.push_back(temp);
    } while(getc(stdin) == ' ');

    number = lines.size();                                  // 띄어쓰기로 구분된 단어 갯수 카운트
    for(int w = 0 ; w < lines.size() ; w++)                 // 각 단어별로 다시 검사
    {
        string line = lines[w];
        for(int i = 1 ; i < line.size() - 1 ; i++)
        {
            if(line[i] == '-')                              // 단어 사이에 하이픈이 들어가있으면 구분
            {
                number++;
            }
            else if(line[i] == '\'')                        // 만약 중간에 어퍼스트로피가 있을 경우
            {
                bool mo = false;
                for(int m = 0 ; m < 6 ; m++)                // 바로 뒤의 문자가 모음에 속하는지 검사
                {
                    if(line[i+1] == moum[m]) mo = true;
                }
                if(mo)                                      // 뒤의 문자가 모음일 경우에
                {
                    bool word = false;
                    if(i == 1 || (i > 1 && line[i-2] == '-'))
                    {
                        for(int up = 0 ; up < 8 ; up++)     // 앞의 문자 1개가 주어진 조건에 속해있는지 검사
                        {
                            if(line[i-1] == uppe[up])
                            {
                                word = true;
                                break;
                            }
                        }
                    }
                    if(i == 2 || (i > 2 && line[i-3] == '-'))   // 혹은 앞의 문자 2개가 qu 인지 검사
                    { 
                        if(line[i-2] == 'q' && line[i-1] == 'u') word = true;
                    }
                    if(word) number++;                      // 앞에 온 값들이 조건에 맞고 뒤에도 모음이 왔다면 단어로 구분
                }
            }
        }
    }

    cout << number << endl;
}