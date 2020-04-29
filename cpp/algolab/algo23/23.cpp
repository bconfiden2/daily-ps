#include <iostream>
#include <string>
using namespace std;

#define MAX 101

typedef struct _stack {
	char arr[MAX];
	int numOfData;
}Stack;

int check(string Q) {
	Stack* stack;
	int len = 0;

	stack = new Stack;

	stack->numOfData = 0;
  len = Q.length();

	for(int n = 0; n < len ; n++) {
		if (Q[n] == '(' || Q[n] == '[' || Q[n] == '{') {
			stack->arr[stack->numOfData] = Q[n];
			stack->numOfData += 1;
		}
		else if (Q[n] == ')' || Q[n] == ']' || Q[n] == '}') {
			if (stack->numOfData == 0) {
				delete stack;
				return 0;
			}
      else if (Q[n] == '}') {
				if (stack->arr[stack->numOfData - 1] == '{') {
					stack->numOfData -= 1;
				}
        else
          return 0;
			}
			else if (Q[n] == ']') {
				if (stack->arr[stack->numOfData - 1] == '[') {
					stack->numOfData -= 1;
				}
        else
          return 0;
			}
			else {
				if (stack->arr[stack->numOfData - 1] == '(') {
					stack->numOfData -= 1;
				}
        else
          return 0;
			}
		}
	}

	if (stack->numOfData == 0) {
		delete stack;
		return 1;
	}
	else {
    delete stack;
		return 0;
	}
}

int main(void) {
  int testCases = 0;
  cin >> testCases;
  for(int tc = 0 ; tc < testCases ; tc++)
  {
    string line;
    cin >> line;

		cout << check(line) << endl;
  }

  return 0;
}
