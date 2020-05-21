#include "cstring"
#include "MyISBN.h"

#include <iostream>

// constructors
MyISBN::MyISBN ()
{
  isbn[0] = '\0';
}

MyISBN::MyISBN (char isbn_number[])
{
  strcpy(isbn, isbn_number);
}

// utility functions
bool MyISBN::isCorrectNumber()
{
  if (isSyntaxValid() && isCheckSumValid())
  {
    return true;
  }
  else
  {
    return false;
  }
}

// private functions
bool MyISBN::isSyntaxValid()
{
  int i = 0;

  // 입력받은 스트링에서 국가번호만 짤라냄
  int countryLength = 0;
  // 처음 나오는 '-' 전까지 국가번호에 집어넣을건데
  while(isbn[i] != '-')
  {
    // 국가번호갯수가 5 이상인 상황인데 입력값이 들어왔다는 뜻이니 거짓
    if(countryLength >= 5) return false;
    // 입력되어진 문자가 숫자가 아닐 경우 거짓 (문자 '-' 는 조건문에서 걸러짐)
    if(isbn[i] < 48 || isbn[i] > 57) return false;
    // 국가번호에 하나씩 넣어줌
    country[countryLength++] = isbn[i++];
  }
  // 만약 국가번호에 아무것도 없었으면 거짓
  if(countryLength == 0) return false;
  // 국가번호 담는 문자열에 마지막은 널값
  country[countryLength] = '\0';
  // '-' 제외시키기 위해 인덱스 1 증가
  i++;

  // 같은 방법으로 출판사 번호를 저장
  int publisherLength = 0;
  while(isbn[i] != '-')
  {
    //std::cout << i << std::endl;
    if(publisherLength >= 7) return false;

    if(isbn[i] < 48 || isbn[i] > 57) return false;

    publisher[publisherLength++] = isbn[i++];
  }

  if(publisherLength == 0) return false;

  publisher[publisherLength] = '\0';

  i++;

  // 같은 방법으로 책 번호 저장
  int bookLength = 0;
  while(isbn[i] != '-')
  {
    //std::cout << i << std::endl;
    if(bookLength >= 6) return false;

    if(isbn[i] < 48 || isbn[i] > 57) return false;

    book[bookLength++] = isbn[i++];
  }

  if(bookLength == 0) return false;

  book[bookLength] = '\0';

  i++;

  // 만약 맨 마지막으로 들어온 값이 0~9 사이일 경우
  if(isbn[i] >= 48 && isbn[i] <= 57)
  {
    // 체크썸에 값 넣어주고
    checkSum = isbn[i];
  }
  // X 일 경우에도 넣어줌
  else if (isbn[i] == 88) {
    checkSum = 'X';
  }
  // 나머지는 거짓
  else
  {
    return false;
  }
  i++;

  //                    국가   출판사  책   쳌썸
  // 정상적인 ISBN 번호라면 @@@ - @@@ - @@@ - @ 형식으로 나올 것이기 떄문에
  // 만약 체크썸 다음에 입력된 값이 있으면 거짓
  if(isbn[i] != '\0') return false;

  // 모두 무사통과시 참
  return true;
}

bool MyISBN::isCheckSumValid()
{
  int digit = 10;
  int sum = 0;
  int i;

  // 국가번호 자릿수마다 각 자리숫자를 곱함 (10, 9, 8, 7, ...)
  i = 0;
  while(country[i] != '\0')
  {
    sum += digit-- * (country[i++]-48);
  }

  // 출판사 자릿수마다 각 자릿수를 곱함
  i = 0;
  while(publisher[i] != '\0')
  {
    // 만약 전체 9자리를 넘어가면 종료
    if(digit == 1) break;

    sum += digit-- * (publisher[i++] - 48);
  }

  // 책 자릿수
  i = 0;
  while(book[i] != '\0')
  {
    if(digit == 1) break;

    sum += digit-- * (book[i++] - 48);
  }

  int count = 0;
  // 전체 합이 11 배수 될때까지 count 증가
  while(((sum + count) % 11) != 0)
  {
    count++;
  }

  // count 가 체크썸 값이 됨

  // count 가 10일 땐 입력받았던 체크썸이 X 라면 트루
  if(count == 10)
  {
    if(checkSum == 88)
    {
      return true;
    }
  }
  // 0~9는 count 가 체크썸과 값이 같아야 참
  else if(count == (checkSum - 48))
  {
    return true;
  }
  // 아니면 거짓
  return false;
}
