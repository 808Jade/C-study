#include <iostream>
#include <string.h>
#include "Marine.h"
#include "mystring.h"
#include "mycomplex.h" 

template <typename String>
std::string StrCat(const String& s) {
    return std::string(s);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    return std::string(s) + StrCat(strs...);
}

int main() {
    // std::string 과 const char* 을 혼합해서 사용 가능하다.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
        " ", std::string("sentence"));
}

// 생성자::Marine() : 여기() 여기() {} --> '여기'는 초기화 리스트.
// 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장됩니다.
// C++ 오버로딩 규칙을 머리속에 숙지 하는 일은 매우 중요한 일입니다.
// 상수와 레퍼런스들은 모두 생성과 동시에 초기화가 되어야 합니다.
// 클래스의 생성자에서 초기화 리스트를 사용해서 초기화 시켜주어야 합니다.

// static 이 아닌 멤버 함수들의 경우 객체를 만들어야지만 각 멤버 함수들을 호출할 수 있지만 
// static 함수의 경우, 객체가 없어도 그냥 클래스 자체에서 호출할 수 있게 됩니다. 
// (초기화) int Marine::total_marine_num = 0;
// (클래스)::(static 함수)

// 연산자 오버로딩
// [ implicit casting / explicit casting ]
// int + double 할 떄, int 형 변수가 자동으로 double 변수로 캐스팅 되는 것과 같은 것.
// void* 타입의 주소를 특정 구조체 포인터 타입의 주소로 바꾼다던지..
// (static_cast, const_cast, dynamic_cast, reinterpret_cast)
// 
// 통상적으로 자기 자신을 리턴하지 않는 이항 연산자들은 모두 외부 함수로 선언하는 것이 원칙, 반대로 자기
// 자신을 리턴하는 이항 연산자들( -= += ) 은 모두 멤버 함수로 선언하는 것이 원칙 !
// 자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의합시다!
// 단항 연산자( ++ -- )는 멤버 함수로 오버로딩 하는 것이 좋습니다.

// wrapper 클래스 : 타입 변환 연산자 (기본 자료형들을 객체로서 다룬다. wrap 하여 사용한다 !)

// 래퍼런스를 리턴하는 함수

//class 사용자 {
//};
// 6 가지 special 함수
// 
// 사용자();	                         - default creator
// ~사용자();                         - d tor
// 사용자(const 사용자&);             - copy creator
// 사용자& operator=(const 사용자&);  - copy assignment
// 사용자(사용자&&);                  - moveconstructor && -> r-value reference
// 사용자& operator=(사용자&&);       - move assignment operator

// friend 로 정의된 클래스나 함수들은 원래 클래스의 private 로 정의된 변수나 함수들에 접근할 수 있습니다.
// 구현 디테일은 최대한 숨기자 !
// Wrapper 클래스 : 기본 자료형들을 객체로써 다루어야 할 때 ( class INT )

// 전위 증감 연산(++x)의 경우 값이 바뀐 자기 자신 을 리턴해야 하고, 
// 후위 증감 연산(x++)의 경우 값이 바뀌기 이전의 객체 를 리턴해야 된다.

// 캐스팅 ( implicit / explicit)
// c++ 기본 제공 캐스팅 : static_cast  const_cast  dynamic_cast  reinterpret_cast

// 몇 중 for문을 사용할지 컴파일 시 정해져야함. 그럴 수 없을 경우 재귀 함수를 이용하자.

// C++ 템플릿(template) 도입
// 클래스 템플릿과 함수 템플릿
// 템플릿 인스턴스화와 템플릿 특수화
// 함수 객체(Functor)  if (!comp(cont[i], cont[j]))
// 타입이 아닌 템플릿 인자  template <typename T, int num>
// 디폴트 템플릿 인자  template <typename T, int num = 5>

// 템플릿 파리미터 팩 template <typename T, typename... Types>