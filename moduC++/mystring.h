class STRING {
    int string_len;     // 문자열 길이
    char* sp;           // 문자열 데이터를 가리키는 포인터
    int memory_capacity;// 현재 할당된 용량
public:
    // 암시적 변환을 수행하지 못하게 explicit
    explicit STRING(int capacity);

    STRING(char c);
    STRING(const char* cp);
    STRING(const STRING& other);
    ~STRING();

    void print() const;
    void println() const;

    int getlen() const; // 내부 멤버 변수의 값을 바꾸지 않는다면 함수를 꼭 상수로 정의하세요.
    int capacity() const;
    void reserve(int size);

    STRING& assign(const STRING& other);
    STRING& assign(const char* cp);

    char at(int i) const;

    STRING& insert(int loc, const STRING& other);
    STRING& insert(int loc, const char* cp);
    STRING& insert(int loc, char c);

    STRING& erase(int loc, int num);

    int find(int find_from, STRING& other) const;
    int find(int find_from, const char* cp) const;
    int find(int find_from, char c) const;

    int compare(const STRING& other) const;
    bool operator==(STRING& other);

    char& operator[](const int index);
};