#include <iostream>
#include <string>

#define INF 9999999

using namespace std;

int main() {
    system("chcp 1251");

    bool isWorking = true;

    while (isWorking) {
        int size;

        char in;
        bool metka = true;

        while (metka) {
            cout << "Введите размер матрицы смежности: ";
            if ((cin >> in).good() && isdigit(in)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                size = in - '0';
                metka = false;
            }
        }

        int** array = new int* [size];
        int* selected = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = new int[size];
            selected[i] = false;
        }

        cout << "Введите матрицу смежности построчно" << endl;

        for (int i = 0; i < size; i++) {
            cout << i << ": ";

            for (int j = 0; j < size; j++) {
                cin >> array[i][j];
            }
        }

        int no_edge = 0;
        selected[0] = true;
        int x, y;

        cout << "Ребро" << " : " << "Вес" << endl;

        while (no_edge < size - 1) {
            int min = INF;
            x = 0;
            y = 0;

            for (int i = 0; i < size; i++) {
                if (selected[i]) {
                    for (int j = 0; j < size; j++) {
                        if (!selected[j] && array[i][j]) {
                            if (min > array[i][j]) {
                                min = array[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            cout << x << " - " << y << " :  " << array[x][y] << endl;

            selected[y] = true;
            no_edge++;
        }

        for (int i = 0; i < size; i++) {
            delete[] array[i];
        }

        delete[] array;
        delete[] selected;
    
        char answ;

        cout << "Продолжить работу? (Y/N)" << endl;
        cin >> answ;

        if (answ == 'N' || answ == 'n') {
            isWorking = false;
        }

        else if (answ == 'Y' || answ == 'y') {
            system("cls");

            continue;
        }

        else {
            continue;
        }
    }

    return 0;
}