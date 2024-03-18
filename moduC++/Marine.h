class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;                // ���� ü��
    int coord_x, coord_y;  // ���� ��ġ
    bool is_dead;

    const int default_damage;  // �⺻ ���ݷ�

public:
    Marine();              // �⺻ ������
    Marine(int x, int y);  // x, y ��ǥ�� ���� ����
    Marine(int x, int y, int default_damage);

    int attack() const;                    // �������� �����Ѵ�.
    Marine& be_attacked(int damage_earn);  // �Դ� ������
    void move(int x, int y);               // ���ο� ��ġ

    void show_status();  // ���¸� �����ش�.
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};