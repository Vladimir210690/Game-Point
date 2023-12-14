#include <iostream>
#include <ctime>

using namespace std;

int gamerCard[10]{3,7,4,6,8};
int CPUCard[10]{2,5,3,8,4,9,3,5,1,6,};

void Card(int arr[],int n) { // функция для создания карт, n - определяет их количество
    for (int i = 0; i < n; i++) {
        cout << "#####\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "#   #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 10) {
            cout << "# " << arr[i] << "#\t";
        }
        else {
            cout << "# " << arr[i] << " #\t";
        }
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

int Sum(int arr[], int n) { // Функция суммирования значений карт
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void CompMot() { // Автоматический ход компьютера
    int b = 2; // Количество карт компьютера
    Card(CPUCard, b);
}

int main() {
    int more = 0;
    int a = 0; // Количество карт игрока
   
    cout << "Input range card: "; // запрашиваем количество карт
    cin >> a;
    system("cls");
    while (true) {
       
        Card(gamerCard, a);
        cout << "Summa card = " << Sum(gamerCard, a) << endl;
        cout << "More - 1, Myself - 2" << endl; // предлагаем взять еще карту
        cin >> more;
        cout << endl << endl;
        if (more == 1) { // добавление еще одной карты в колоду
            a += 1;
        }
       /* else if (more == 2) {
            while (true) {
               
                CompMot();
            }
        }*/
        system("cls");
    }
	return 0;
}