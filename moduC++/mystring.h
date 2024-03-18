class STRING {
    int string_len;     // ���ڿ� ����
    char* sp;           // ���ڿ� �����͸� ����Ű�� ������
    int memory_capacity;// ���� �Ҵ�� �뷮
public:
    // �Ͻ��� ��ȯ�� �������� ���ϰ� explicit
    explicit STRING(int capacity);

    STRING(char c);
    STRING(const char* cp);
    STRING(const STRING& other);
    ~STRING();

    void print() const;
    void println() const;

    int getlen() const; // ���� ��� ������ ���� �ٲ��� �ʴ´ٸ� �Լ��� �� ����� �����ϼ���.
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