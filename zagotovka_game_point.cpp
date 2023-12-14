#include <iostream>
#include <ctime>

using namespace std;

void GamerCard(int n) { // функция для создания карт, n - определяет их количество
    for (int i = 0; i < n; i++) {
        cout << "#####\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#   #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#   #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#   #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#####\t";
    }
    cout << endl;
}

int main() {
    int more = 0;
    int a = 0;
    cout << "Input range card: "; // запрашиваем количество карт
    cin >> a;
    system("cls");
    while (true) {
        GamerCard(a);
        cout << "More - 1, Myself - 2" << endl; // предлагаем взять еще карту
        cin >> more;

        if (more == 1) {
            a += 1;
        }
        system("cls");
    }
	return 0;
}