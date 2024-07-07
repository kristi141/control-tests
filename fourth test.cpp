/*RU
Для того чтобы понять, списана ли задача, преподаватели решили адаптировать 
“механизм степеней доверия” из теории доверительных P2P сетей. Он работает 
следующим способом: в классе есть n студентов, некоторые из которых хорошо 
общаются между собой, следовательно с большей вероятностью могут взять решение 
друг у друга (“решить задачу по своему товарищу”) или сесть решать задачу 
вместе.
 
Известно, что есть m студентов, которые чаще всего первыми решают задачи – 
обозначим их степень доверия за 1, любой другой студент имеет степень доверия 
x, если он находится на расстоянии 1 от минимум двух других узлов со степенью 
доверия x-1. У студента всегда остаётся только одна наилучшая (наименьшая) 
степень доверия.

Ваша задача – написать алгоритм, который определяет,  какую наилучшую 
(минимальную) степень доверия имеет каждый студент. Если студент – одиночка 
(не может получить никакую степень доверия), то считаем что его степень 
доверия -1 

Формат входных данных  
В первой строке дано значение n – число студентов в классе
Далее дана “матрица общения” студентов – неориентированная невзвешенная 
матрица смежности, размер n на n, без петель
В следующей строке указано число m – количество студентов со степенью доверия 1
В последней строке входных данных даны номера этих студентов через пробел

В качестве выходных данных выведите n чисел – степени доверия для каждого из 
студентов

Входные данные:
1)
5
0 1 0 0 0
1 0 0 0 0
0 0 0 1 1
0 0 1 0 1
0 0 1 1 0
2
2 4

2)
7
0 1 0 0 1 0 0
1 0 1 0 0 0 0
0 1 0 1 0 0 1
0 0 1 0 0 1 1
1 0 0 0 0 1 0
0 0 0 1 1 0 1
0 0 1 1 0 1 0
3

3)
10
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1 0 0
0 1 1 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 1 0
0 0 0 0 1 1 0 0 0 1
0 0 0 0 0 1 1 0 0 1
0 0 0 0 0 0 0 1 1 0
4
1 2 3 4

Выходные данные:
1)
1 1 -1 1 -1

2)
-1 -1 1 1 1 2 2

3)
1 1 1 1 2 2 2 3 3 4

Возможно в коде ниже имеется небольшая ошибка

ENG
In order to understand whether the task was written off, the teachers decided 
to adapt “mechanism of degrees of trust” from the theory of trusted P2P 
networks. It works in the following way: there are n students in the class, 
some of whom are good communicate with each other, therefore they are more 
likely to make a decision from each other (“solve the problem according to 
your friend”) or sit down to solve the problem together.

It is known that there are m students who are most often the first to solve problems -
let's denote their degree of trust as 1, any other student has a degree of trust
x if it is at distance 1 from at least two other nodes with degree
trust x-1. The student always has only one best (smallest)
degree of trust.

Your task is to write an algorithm that determines which is the best
Each student has a (minimum) degree of trust. If the student is a loner
(cannot receive any degree of trust), then we consider that its degree
trust -1

Input format
The first line contains the value n - the number of students in the class
The following is the “communication matrix” of students – unoriented, 
unweighted adjacency matrix, size n by n, no loops
The next line contains the number m - the number of students with confidence 
level 1 The last line of the input contains the numbers of these students 
separated by a space

As output, print n numbers – degrees of confidence for each of
students

Input data:
1)
5
0 1 0 0 0
1 0 0 0 0
0 0 0 1 1
0 0 1 0 1
0 0 1 1 0
2
2 4

2)
7
0 1 0 0 1 0 0
1 0 1 0 0 0 0
0 1 0 1 0 0 1
0 0 1 0 0 1 1
1 0 0 0 0 1 0
0 0 0 1 1 0 1
0 0 1 1 0 1 0
3

3)
10
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1 0 0
0 1 1 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 1 0
0 0 0 0 1 1 0 0 0 1
0 0 0 0 0 1 1 0 0 1
0 0 0 0 0 0 0 1 1 0
4
1 2 3 4

Output:
1)
1 1 -1 1 -1

2)
-1 -1 1 1 1 2 2

3)
1 1 1 1 2 2 2 3 3 4

There may be a small error in the code below */

#include <iostream>
#include <vector>
using namespace std;

vector<int> computeTrustDegrees(int n, const vector<vector<int>>& adjacencyMatrix, int m, const vector<int>& trustedStudents) {
    vector<int> trustDegrees(n, -1);

    for (int student : trustedStudents) {
        trustDegrees[student] = 1;
    }

    for (int x = 2; x <= n; x++) {
        for (int student = 0; student < n; student++) {
            int count = 0;
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (adjacencyMatrix[student][neighbor] && trustDegrees[neighbor] == x - 1) {
                    count++;
                }
            }
            if (count >= 2 && trustDegrees[student] == -1) {
                trustDegrees[student] = x;
            }
        }
    }

    return trustDegrees;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int m;
    cin >> m;

    vector<int> trustedStudents(m);
    for (int i = 0; i < m; i++) {
        cin >> trustedStudents[i];
    }

    vector<int> trustDegrees = computeTrustDegrees(n, adjacencyMatrix, m, trustedStudents);

    for (int degree : trustDegrees) {
        cout << degree << " ";
    }
    cout << endl;

    return 0;
}
