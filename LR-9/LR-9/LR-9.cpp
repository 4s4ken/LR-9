#include<iostream>
#include<Windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;
int main() {   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outputFile("log-file.txt");   
    time_t currentTime = time(0);
    string timeString = ctime(&currentTime);
    int N, randomNum;
    cout << "Введите значение N: " << endl;
input: 
    cin >> N;
    if (!cin)
    {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Ошибка в вводе значения N, попробуйте снова." << endl;
        outputFile << "Ошибка при ввода числа N - " << timeString << endl;
        goto input;
    }
    outputFile << "Входные данные: " << endl << N << " Время ввода значения N: " << timeString << endl;
    int* A = new int[N];
    for (int i = 0;i < N;i++)
        A[i] = i;
    randomNum = rand() % N + 1;
    outputFile << "Выходные данные:" << endl;
    for (int i = 1;i < N+1;i++)
    {
        randomNum = rand() % N + 1;;
    loop:
        if (A[randomNum] != 0)
        {
            getchar();
            cout << "Бочонок под номером " << i<< " имеет номер: " << randomNum;
            time_t currentTime = time(0);
            string timeString = ctime(&currentTime);
            outputFile << randomNum << " Время вывода " << i << "-го числа: " << timeString << endl;
            A[randomNum] = 0;
        }
        else
        {
            randomNum = rand() % (N + 1);
            goto loop;
        }
    }
    cout << endl;
    outputFile.close();
}
