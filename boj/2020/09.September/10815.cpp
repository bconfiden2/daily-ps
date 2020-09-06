#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int numbers[500001];

int check(int target)       // 이진탐색으로 있냐 없냐를 반환해줌
{
    int start = 0;
    int end = n;

    while(start <= end)     // 이진탐색 시작, start 가 end 를 넘어설 때 까지
    {
        int mid = (start + end) / 2;                // 중간 인덱스
        if(numbers[mid] == target) return 1;        // 값을 찾았다면 종료
        if(numbers[mid] < target) start = mid + 1;
        if(numbers[mid] > target) end = mid - 1;
    }

    return 0;
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);             // 이진탐색하기 위해서 정렬

    cin >> m;
    for(int i = 0, temp ; i < m ; i++)
    {
        cin >> temp;
        cout << check(temp) << " ";         // 값을 이진탐색으로 찾음
    }
    cout << endl;
}


/******************************************************************
#ifndef TOPOLOGY_FASTIO_H
#define TOPOLOGY_FASTIO_H
#include <stdio.h>
#include <string.h>
#define __BUFSIZE 2097152
#define __BLANK(c) (c == ' ' \
                    || c == '\n' \
                    || c == '\t' \
                    || c == '\v' \
                    || c == '\f' \
                    || c == '\r')
#define __ENDL(c) (c == '\n')
#define __END(c) (c == '\0')

char __RBUF[__BUFSIZE], __WBUF[__BUFSIZE];
int __RIDX, __NIDX, __WIDX, __END_FLAG;

inline int isEnd()
{
    return __END_FLAG;
}

inline char readChar()
{
    if(__RIDX == __NIDX)
    {
        __NIDX = fread(__RBUF, sizeof(char), __BUFSIZE, stdin);
        if(__NIDX == 0)
        {
            __END_FLAG = 1;
            return 0;
        }
        __RIDX = 0;
    }
    return __RBUF[__RIDX++];
}

inline size_t readString(char* dest, int maxl)
{
    size_t idx = 0;
    char cur;

    if(maxl == 0)
    {
        *dest = 0;
        return 0;
    }

    cur = readChar();
    while(__BLANK(cur))
        cur = readChar();
    while(!__BLANK(cur) && !__END(cur) && idx < (unsigned) maxl)
    {
        *(dest + idx++) = cur;
        cur = readChar();
    }

    *(dest + idx) = 0;
    return idx;
}

inline size_t readLine(char* dest, int maxl)
{
	size_t idx = 0;
	char cur;

	if (maxl == 0)
    {
		*dest = 0;
		return 0;
	}

	cur = readChar();

	while (!__ENDL(cur) && !__END(cur) && idx < (unsigned) maxl)
    {
		*(dest + idx++) = cur;
		cur = readChar();
	}

	*(dest + idx) = 0;

	return idx;
}

inline int readInt()
{
    int res = 0;
    char cur = readChar();
    bool flag = 0;

    while(__BLANK(cur))
        cur = readChar();

    if(cur == '-')
    {
        flag = true;
        cur = readChar();
    }

    while(!__BLANK(cur) && !__END(cur))
    {
        res = 10 * res + cur - '0';
        cur = readChar();
    }

    return flag ? -res : res;
}

inline double readDouble()
{
	return 0;
}

inline int readLL()
{
    long long res = 0;
    char cur = readChar();
    bool flag = 0;

    while(__BLANK(cur))
        cur = readChar();

    if(cur == '-')
    {
        flag = true;
        cur = readChar();
    }

    while(!__BLANK(cur) && !__END(cur))
    {
        res = 10 * res + cur - '0';
        cur = readChar();
    }

    return flag ? -res : res;
}

static inline int uintSize(int n)
{
    int isz = 1;
    if(n < 0) n *= -1;

    while(n >= 10)
    {
        isz++;
        n /= 10;
    }

    return isz;
}

static inline int ullintSize(long long n)
{
    int isz = 1;
    if(n < 0) n *= -1;

    while(n >= 10)
    {
        isz++;
        n /= 10;
    }

    return isz;
}

inline void bflush()
{
    fwrite(__WBUF, sizeof(char), __WIDX, stdout);
    __WIDX = 0;
}

inline void writeChar(char c, bool endl = false)
{
    if(__WIDX == __BUFSIZE)
    {
        bflush();
    }
    __WBUF[__WIDX++] = c;

    if(endl) writeChar('\n');
}

inline void newLine()
{
    writeChar('\n');
}

inline void writeString(const char* s, bool endl = false)
{
    int len = strlen(s);
    if(__WIDX + len >= __BUFSIZE)
    {
        bflush();
    }
    int next = __WIDX + len;

    while(len--) __WBUF[__WIDX + len] = *(s + len);

    __WIDX = next;

    if(endl) newLine();
}

inline void writeInt(int n, bool endl = false)
{
    int isz = uintSize(n);
    if(__WIDX + isz >= __BUFSIZE)
    {
        bflush();
    }
    if(n < 0)
    {
        n *= -1;
        __WBUF[__WIDX++] = '-';
    }
    int next = __WIDX + isz;

    while(isz--)
    {
        __WBUF[__WIDX + isz] = n % 10 + '0';
        n /= 10;
    }
    __WIDX = next;

    if(endl) newLine();
}

inline void writeDouble(double d)
{
	return;
}

inline void writeLL(long long n, bool endl = false)
{
    int isz = uintSize(n);
    if(__WIDX + isz >= __BUFSIZE)
    {
        bflush();
    }
    if(n < 0)
    {
        n *= -1;
        __WBUF[__WIDX++] = '-';
    }
    int next = __WIDX + isz;

    while(isz--)
    {
        __WBUF[__WIDX + isz] = n % 10 + '0';
        n /= 10;
    }
    __WIDX = next;

    if(endl) newLine();
}
#endif

#include <algorithm>

using namespace std;

int a[500003];

int main()
{
    int n = readInt();
    for(int i = 0 ; i < n ; i++)
    {
        a[i] = readInt();
    }
    sort(a, a + n);
    int m = readInt();
    for(int i = 0 ; i < m ; i++)
    {
        writeInt(binary_search(a, a + n, readInt()));
        writeChar(' ');
    }
    newLine();
    bflush();
}
************************************************************************/