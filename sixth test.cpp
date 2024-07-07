/*RU
Вам дана матрица размером n на m. Известно, что она состоит из чисел, 
которые  отсортированы вкруговую по этой матрице.
Имея возможность запросом “? i j” узнавать значение элемента на позиции i j, 
вам необходимо определить, содержит ли эта матрица элемент со значением k и 
вывести его координаты

Формат входных данных
На первой строке числа n и m, далее n строк из m чисел - матрица.
Далее - число k.

ENG
You are given a matrix of size n by m. It is known that it consists of numbers,
which are sorted circularly by this matrix.
Having the ability to request “? i j” find out the value of the element at 
position i j, you need to determine if this matrix contains an element with 
value k and display its coordinates

Input format
On the first line there are numbers n and m, then there are n lines of m 
numbers - a matrix.
Next is the number k.*/

#include <iostream>
#include <vector>
using namespace std;

void binarySearch(const vector<vector<int>>& matrix, int numberToFindCoordinates) {
    int line = matrix.size();
    int number = matrix[0].size();

    int left = 0;
    int right = line * number - 1;
    int middle, middleValue;

    while (left <= right) {
        middle = (left + right) / 2;
        int middleRow = middle / number;
        int middleColumn = middle % number;

        cout << "? " << middleRow + 1 << " " << middleColumn + 1 << endl;
        cout.flush();
        cin >> middleValue;

        int leftValue;
        int leftRow = left / number;
        int leftColumn = left % number;

        cout << "? " << leftRow + 1 << " " << leftColumn + 1 << endl;
        cout.flush();
        cin >> leftValue;

        int rightValue;
        int rightRow = right / number;
        int rightColumn = right % number;

        cout << "? " << rightRow + 1 << " " << rightColumn + 1 << endl;
        cout.flush();
        cin >> rightValue;

        if (leftValue == numberToFindCoordinates) {
            cout << "! " << leftRow + 1 << " " << leftColumn + 1 << endl;
            cout.flush();
            return;
        }

        if (rightValue == numberToFindCoordinates) {
            cout << "! " << rightRow + 1 << " " << rightColumn + 1 << endl;
            cout.flush();
            return;
        }

        if (middleValue == numberToFindCoordinates) {
            cout << "! " << middleRow + 1 << " " << middleColumn + 1 << endl;
            cout.flush();
            return;
        }

        if (rightValue >= middleValue) {
            if (numberToFindCoordinates > middleValue && numberToFindCoordinates <= rightValue) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        else {
            if (numberToFindCoordinates < middleValue && numberToFindCoordinates >= leftValue) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
    }

    cout << "! " << -1 << endl;
    cout.flush();
}

int main() {
    int line, number, numberToFindCoordinates;
    cin >> line >> number >> numberToFindCoordinates;

    vector<vector<int>> matrix(line, vector<int>(number));

    binarySearch(matrix, numberToFindCoordinates);

    return 0;
}