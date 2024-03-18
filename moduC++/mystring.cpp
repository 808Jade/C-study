#include <iostream>
#include "mystring.h"

using namespace std;

STRING::STRING(int capacity)
{
    sp = new char[capacity];
    string_len = 0;
    memory_capacity = capacity;
    cout << "Capacity : " << capacity << '\n';
}

STRING::STRING(char c)
{
    sp = new char[1];
    sp[0] = c;
    string_len = 1;
    memory_capacity = 1;
}

STRING::STRING(const char* cp)
{
    string_len = strlen(cp);
    sp = new char[string_len];
    memory_capacity = string_len;

    for (int i = 0; i < string_len; ++i) {
        sp[i] = cp[i];
    }
}

STRING::STRING(const STRING& other)
{
    string_len = other.string_len;
    memory_capacity = other.memory_capacity;

    for (int i = 0; i != string_len; ++i)
        sp[i] = other.sp[i];
}

STRING::~STRING() { delete[] sp; }

int STRING::getlen() const { return string_len; }

void STRING::print() const    // << 연산자로 바꾼다?
{
    // cout << sp << '\n';                    * 왜 이렇게 쓰지 않는 것?

    for (int i = 0; i != string_len; ++i)
        cout << sp[i];
}

void STRING::println() const
{
    for (int i = 0; i != string_len; ++i)
        cout << sp[i];
    cout << endl;
}

STRING& STRING::assign(const STRING& other)
{
    if (other.string_len > memory_capacity) {
        delete[] sp;
        sp = new char[other.string_len];
        memory_capacity = other.string_len;
    }

    for (int i = 0; i != other.string_len; ++i)
        sp[i] = other.sp[i];

    string_len = other.string_len;

    return *this;
}

STRING& STRING::assign(const char* cp)
{
    int str_len = strlen(cp);
    if (str_len > memory_capacity) {
        delete[] sp;
        sp = new char[str_len];
        memory_capacity = str_len;
    }
    for (int i = 0; i != str_len; ++i)
        sp[i] = cp[i];

    string_len = str_len;

    return *this;
}

int STRING::capacity() const { return memory_capacity; }

void STRING::reserve(int size)
{
    if (size > memory_capacity) {
        char* prev_string_content = sp;

        sp = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_len; ++i)
            sp[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
}

char STRING::at(int i) const
{
    if (i >= string_len || i < 0)
        return 0;
    else
        return sp[i];
}

STRING& STRING::insert(int loc, const STRING& other)
{
    // 규칙 : loc 의 위치 바로 앞에 문자를 삽입.

    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_len) return *this;

    // 새로 할당해야 할 메모리 크기(string_length + str.string_length) 가 
    // 현재의 memory_capacity 의 두 배 이하라면,
    // 아예 memory_capacity 의 두 배에 달하는 크기를 할당해버리는 기법(?).
    if (string_len + other.string_len > memory_capacity) {
        if (memory_capacity * 2 > string_len + other.string_len)
            memory_capacity *= 2;
        else
            memory_capacity = string_len + other.string_len;

        char* prev_string_content = sp;
        sp = new char[memory_capacity];

        // 일단 insert되는 부분 직전까지의 내용을 복사한다.
        int i;
        for (i = 0; i < loc; ++i)
            sp[i] = prev_string_content[i];

        // 그리고 새롭게 insert되는 문자열을 넣는다.
        for (int j = 0; j != other.string_len; ++j)
            sp[i + j] = other.sp[j];

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
        for (; i < string_len; ++i)
            sp[other.string_len + i] = prev_string_content[i];

        delete[] prev_string_content;

        string_len = string_len + other.string_len;
        return *this;
    }

    // 만약 초과하지 않는 경우 굳이 동적할당을 할 필요가 없다.

    // 효율적으로 insert하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i = string_len - 1; i >= loc; --i)
        sp[i + other.string_len] = sp[i];
    // 그리고 insert 되는 문자 다시 집어넣기
    for (int i = 0; i < other.string_len; ++i)
        sp[i + loc] = other.sp[i];

    string_len = string_len + other.string_len;
    return *this;
}

STRING& STRING::insert(int loc, const char* str)
{
    STRING temp(str);
    return insert(loc, temp);
}

STRING& STRING::insert(int loc, char c)
{
    STRING temp(c);
    return insert(loc, temp);
}

STRING& STRING::erase(int loc, int num)
{
    if (num < 0 || loc<0 || loc>string_len)return *this;

    for (int i = loc + num; i < string_len; ++i)
        sp[i - num] = sp[i];

    string_len -= num;
    return *this;
}

int STRING::find(int find_from, STRING& other) const
{
    int i, j;
    if (other.string_len == 0) return -1;
    for (i = find_from; i <= string_len - other.string_len; ++i) {
        for (j = 0; j < other.string_len; ++j) {
            if (sp[i + j] != other.sp[j])break;
        }

        if (j == other.string_len) return i;
    }

    return -1;
}

int STRING::find(int find_from, const char* cp) const
{
    STRING temp(cp);
    return find(find_from, temp);
}

int STRING::find(int find_from, char c) const
{
    STRING temp(c);
    return find(find_from, temp);
}

int STRING::compare(const STRING& other) const
{
    // std::min, std::max !
    for (int i = 0; i < std::min(string_len, other.string_len); ++i) {
        if (sp[i] > other.sp[i])
            return 1;
        else if (sp[i] < other.sp[i])
            return -1;
    }

    if (string_len == other.string_len) return 0;

    else if (string_len > other.string_len)
        return 1;

    return -1;
}

bool STRING::operator==(STRING& other)
{
    return !compare(other); // other과 같으면 compare에서 0을 리턴한다.
}

char& STRING::operator[](const int index) { return sp[index]; }