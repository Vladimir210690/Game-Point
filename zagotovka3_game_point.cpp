#include <iostream>
#include <ctime>

using namespace std;

int a = 0; // Количество карт игрока
int b = 2; // Количество карт компьютера
int sumGamer = 0;
int sumProgramm = 0;

int gamerCard[10]{3,7,4,6,8};
char gamermas[10]{ 3,5,6,4,3,4,6,6,3,5};
int CPUCard[10]{6,6,7,9,8};
char CPUmas[10]{ 4,5,5,3,6,3,4,4,4,3 };

void Card(int arr[], char brr[],int n) { // функция для создания карт, n - определяет их количество
    for (int i = 0; i < n; i++) {
        cout << "#####\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "# "<< brr[i] << " #\t";
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
        cout << "# " << brr[i] << " #\t";
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
    
    while (Sum(CPUCard, b) < 21) {
        system("cls");
        cout << "Motion gamer: " << endl;
        Card(gamerCard, gamermas, a);
        sumGamer = Sum(gamerCard, a);
        cout << "Summa card = " << sumGamer << endl << endl;
        

        cout << "Motion programm: " << endl;
        Card(CPUCard, CPUmas, b);
        sumProgramm = Sum(CPUCard, b);
        cout << "Summa card = " << sumProgramm << endl;
        if (Sum(CPUCard, b) < 13) {
            b += 1;

            Card(CPUCard, CPUmas, b);
        }
        else {
            break;
        }
        if (Sum(CPUCard, b) >= 21) {
            break;
        }
    }
}

int main() {
    int more = 0;
   
    cout << "Input range card: "; // запрашиваем количество карт
    cin >> a;
    system("cls");
    
    while (true) {
       
        Card(gamerCard, gamermas, a);
        cout << "Summa card = " << Sum(gamerCard, a) << endl;

        cout << "More - 1, Myself - 2" << endl; // предлагаем взять еще карту
        cin >> more;
        cout << endl << endl;
        if (more == 1) { // добавление еще одной карты в колоду
            a += 1;
        }
        if (Sum(gamerCard, a) >= 21 || more == 2) {
            break;
        }
        system("cls");
    }
  
    cout << "My motion" << endl;
    CompMot();
    cout << endl;

    if (sumProgramm > sumGamer && sumProgramm <= 21) {
        cout << "Vinner: Programma!" << endl;
    }
    else if (sumProgramm < sumGamer && sumGamer <= 21) {
        cout << "Vinner: Gamer!" << endl;
    }
	return 0;
}