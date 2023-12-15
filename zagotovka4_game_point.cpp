#include <iostream>
#include <ctime>

using namespace std;

int a = 2; // Количество карт игрока
int b = 2; // Количество карт компьютера
int sumGamer = 0; // Сумма карт игрока
int sumProgramm = 0; // Сумма карт компьютера
int totalG = 0; // Общий счет игрока
int totalC = 0; // Общий счет компьютера
bool game = true; // Переменная окончания игры

int gamerCard[10]{ 3,3,3,3,8 }; // Массив для хранения номера карт игрока
char gamermas[10]{ 3,3,6,4,3,4,6,6,3,5 }; // Массив для хранения мастей карт игрока
int CPUCard[10]{ 3,3,3,3,8 }; // Массив для хранения номера карт компьютера
char CPUmas[10]{ 4,5,5,3,6,3,4,4,4,3 }; // Массив для хранения мастей карт игрока

void Card(int arr[], char brr[],int n) { // функция для создания карт, n - определяет их количество
    for (int i = 0; i < n; i++) { // Карты создаются построчно, каждый цикл отвечает за свою строчку карты, количество итераций равно количеству карт
        cout << "#####\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с верхней мастью
        cout << "# "<< brr[i] << " #\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с номером карты
        if (arr[i] == 10) {
            cout << "# " << arr[i] << "#\t";
        }
        else {
            cout << "# " << arr[i] << " #\t";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) { // цикл с нижней мастью
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
        sum += arr[i]; // Значение каждой новой карты суммируются с предыдущими
    }
    return sum;
}

void CompMot() { // Автоматический ход компьютера
    
    while (Sum(CPUCard, b) < 21) {
        system("cls");
        cout << "Motion gamer: " << endl; // Отрисовка последнего хода игрока
        Card(gamerCard, gamermas, a);
        sumGamer = Sum(gamerCard, a);
        cout << "Summa card = " << sumGamer << endl << endl;
        
        cout << "Motion programm: " << endl; // Ход компьютера
        Card(CPUCard, CPUmas, b);
        sumProgramm = Sum(CPUCard, b);
        cout << "Summa card = " << sumProgramm << endl;

        if (Sum(CPUCard, b) < 13) { // Если сумма первых двух карт меньше 13, компьютер берет еще 1 карту
            b += 1;
        }
        else {
            break;
        }
    }
}

void Result() { // Функция подсчета счета и определения итогового результата игры
    if (sumProgramm > sumGamer && sumProgramm <= 21) { // Список всех возможных условий
        cout << "Vinner: Programma!" << endl;
        totalC += 1;
    }
    else if (sumProgramm < sumGamer && sumGamer <= 21) {
        cout << "Vinner: Gamer!" << endl;
        totalG += 1;
    }
    else if (sumProgramm == sumGamer) {
        cout << "Draw!" << endl;
    }
    else if (sumGamer <= 21 && sumProgramm > 21) {
        cout << "Vinner: Gamer!" << endl;
        totalG += 1;
    }
    else if (sumGamer > 21 && sumProgramm <= 21) {
        cout << "Vinner: Programm!" << endl;
        totalC += 1;
    }
    else if (sumGamer > 21 && sumProgramm > 21) {
        cout << "Draw!" << endl;
    }
}

int main() {
    while (game == true) {
        a = 2; // Возвращаем количество карт игроков к стартовому значению
        b = 2;
        int more = 0; // Переменная отвечает за взятие новой карты или передачи хода
        //cout << "Input range card: "; // запрашиваем количество карт
        //cin >> a;
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

        Result();
 
        cout << "Score: " << "Gamer: " << totalG << " Programma: " << totalC << endl << endl;
        cout << "More raund? 1 - yas, 0 - no ";
        cin >> game;
    }
	return 0;
}