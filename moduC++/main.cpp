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
    // std::string �� const char* �� ȥ���ؼ� ��� �����ϴ�.
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
        " ", std::string("sentence"));
}

// ������::Marine() : ����() ����() {} --> '����'�� �ʱ�ȭ ����Ʈ.
// ��� ���۷����� ���ϰ��� �ް� �Ǹ� �ش� ���ϰ��� ������ ����˴ϴ�.
// C++ �����ε� ��Ģ�� �Ӹ��ӿ� ���� �ϴ� ���� �ſ� �߿��� ���Դϴ�.
// ����� ���۷������� ��� ������ ���ÿ� �ʱ�ȭ�� �Ǿ�� �մϴ�.
// Ŭ������ �����ڿ��� �ʱ�ȭ ����Ʈ�� ����ؼ� �ʱ�ȭ �����־�� �մϴ�.

// static �� �ƴ� ��� �Լ����� ��� ��ü�� ���������� �� ��� �Լ����� ȣ���� �� ������ 
// static �Լ��� ���, ��ü�� ��� �׳� Ŭ���� ��ü���� ȣ���� �� �ְ� �˴ϴ�. 
// (�ʱ�ȭ) int Marine::total_marine_num = 0;
// (Ŭ����)::(static �Լ�)

// ������ �����ε�
// [ implicit casting / explicit casting ]
// int + double �� ��, int �� ������ �ڵ����� double ������ ĳ���� �Ǵ� �Ͱ� ���� ��.
// void* Ÿ���� �ּҸ� Ư�� ����ü ������ Ÿ���� �ּҷ� �ٲ۴ٴ���..
// (static_cast, const_cast, dynamic_cast, reinterpret_cast)
// 
// ��������� �ڱ� �ڽ��� �������� �ʴ� ���� �����ڵ��� ��� �ܺ� �Լ��� �����ϴ� ���� ��Ģ, �ݴ�� �ڱ�
// �ڽ��� �����ϴ� ���� �����ڵ�( -= += ) �� ��� ��� �Լ��� �����ϴ� ���� ��Ģ !
// �ڱ� �ڽ��� �����ϴ� ���� �����ڴ� ��� �Լ���, �ƴ� �ֵ��� �ܺ� �Լ��� �����սô�!
// ���� ������( ++ -- )�� ��� �Լ��� �����ε� �ϴ� ���� �����ϴ�.

// wrapper Ŭ���� : Ÿ�� ��ȯ ������ (�⺻ �ڷ������� ��ü�μ� �ٷ��. wrap �Ͽ� ����Ѵ� !)

// ���۷����� �����ϴ� �Լ�

//class ����� {
//};
// 6 ���� special �Լ�
// 
// �����();	                         - default creator
// ~�����();                         - d tor
// �����(const �����&);             - copy creator
// �����& operator=(const �����&);  - copy assignment
// �����(�����&&);                  - moveconstructor && -> r-value reference
// �����& operator=(�����&&);       - move assignment operator

// friend �� ���ǵ� Ŭ������ �Լ����� ���� Ŭ������ private �� ���ǵ� ������ �Լ��鿡 ������ �� �ֽ��ϴ�.
// ���� �������� �ִ��� ������ !
// Wrapper Ŭ���� : �⺻ �ڷ������� ��ü�ν� �ٷ��� �� �� ( class INT )

// ���� ���� ����(++x)�� ��� ���� �ٲ� �ڱ� �ڽ� �� �����ؾ� �ϰ�, 
// ���� ���� ����(x++)�� ��� ���� �ٲ�� ������ ��ü �� �����ؾ� �ȴ�.

// ĳ���� ( implicit / explicit)
// c++ �⺻ ���� ĳ���� : static_cast  const_cast  dynamic_cast  reinterpret_cast

// �� �� for���� ������� ������ �� ����������. �׷� �� ���� ��� ��� �Լ��� �̿�����.

// C++ ���ø�(template) ����
// Ŭ���� ���ø��� �Լ� ���ø�
// ���ø� �ν��Ͻ�ȭ�� ���ø� Ư��ȭ
// �Լ� ��ü(Functor)  if (!comp(cont[i], cont[j]))
// Ÿ���� �ƴ� ���ø� ����  template <typename T, int num>
// ����Ʈ ���ø� ����  template <typename T, int num = 5>

// ���ø� �ĸ����� �� template <typename T, typename... Types>