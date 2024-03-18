#include <iostream>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;

	cout << "\n*** ¼öºóÀÌ Æ®¸® ¤Ð ***\n\n";

	for (int a = 0; a < w - 1; ++a) {
		cout << " ";
	}
	cout << "@" << '\n';

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w - i; ++j)
			cout << " ";
		for (int a = 0; a < i; ++a)
			cout << "*";

		for (int b = 0; b < i - 1; ++b)
			cout << "*";

		cout << '\n';
	}
	for (int a = 0; a < w - 2; ++a)
		cout << " ";

	cout << "|||\n";
}