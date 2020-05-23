#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
vector<string> split(string str, char dlmr) {
    vector<string> internal;
    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, dlmr)) {
        internal.push_back(tmp);
    }
    return internal;
}
int main()
{
  int testCase;
  cin >> testCase;
  string str;
  cin.ignore();
  //getline(cin, str);
  for (int i = 0; i < testCase; i++){
      getline(cin, str);
      //cout << str << endl;
      int count = 0;
      bool check = false;
      bool result = true;
      int err = 10;
      int idx = 0;
      int sum = 0;
     // -의 개수
     for(int j=0; j<str.length(); j++){
       if (str[j] == '-') count++;
     }
     if(count != 3) {
       result = false;
     }
     // 문자가 들어간 경우
     for(int j=0; j<str.length(); j++){
       if(isalpha(str[j])){
         if(str[j] == 'X' || str[j] == '-'){
           result = true;
         }else{
           result = false;
         }
       }
     }
     // 해당하는 숫자가 없는 경우
     if (result == true){
       for(int j=0; j<str.length(); j++){
         if(str[0] == '-'){
           result = false;
           break;
         }
         if(check == true && str[j] == '-'){
           result = false;
           break;
         }
         if(str[j] == '-') {
           check = true;
         }
         if(isdigit(str[j])){
           check = false;
         }
       }
     }
     // 자리수 초과
     if(result == true){
       vector <string> v = split(str, '-');
       if(5 < v[0].length()){
         result = false;
       }
       else if(7 < v[1].length()){
         result = false;
       }
       else if(6 < v[2].length()){
         result = false;
       }
       else if(1 < v[3].length()){
         result = false;
       }
     }
     // checksum
     if (result == true){
       while(1 < err){
         if(isdigit(str[idx])){
           sum += (str[idx] -'0') * err;
           err--;
         }
         idx++;
       }
       int checkSum = (sum/11 + 1) * 11 - sum;
       if( checkSum != str[str.length()-1] - '0'){
          result = false;
       }
       if (checkSum == 10 && str[str.length()-1] == 'X'){
         result = true;
       }
      if(checkSum % 11 == 0 && str[str.length()-1] == '0'){
        result = true;
      }
    }
     cout << result << endl;
  }
 return 0;
}