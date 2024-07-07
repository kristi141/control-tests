/*RU
Приближалось начало нового модуля по программированию, а разработчики 
системы  CodeHedgehog не успевали дописать чекер к задаче ”Нахождение 
минимального пути в графе” (чекер – проверяющая программа для задачи; 
проверяет решение  учащегося, базируясь на имеющихся тестовых данных )

Для написания чекера у вас есть входные данные, которые даны в формате:
в первой строке содержатся три числа: N, S и F (1 ≤ N ≤ 100, 1 ≤ S, F ≤ N), 
где N – количество вершин графа, S – начальная вершина, а F – конечная. 
в следующих N строках вводится по N чисел, не превосходящих 100, – матрица 
смежности графа, где -1 означает отсутствие ребра между вершинами, а любое 
неотрицательное число – наличие ребра данного веса. 
Далее вам дан ответ пользователя в формате:
в первой строке дано значение r –  искомое расстояние или -1, если пути между 
указанными вершинами не существует
в следующей строке через пробел дана последовательность вершин в порядке 
обхода

При работе чекера должны быть учтены следующие варианты:
если путь, найденный пользователем неправилен, чекер должен выводить статус 
“WA” если найденный путь корректен, чекер должен вывести статус “OK”

ENG
The start of a new programming module was approaching, and the developers
CodeHedgehog systems did not have time to add a checker to the task “Finding
minimum path in the graph” (checker – a checking program for a task;
checks the student's solution based on the available test data)

To write a checker you have input data, which is given in the format:
the first line contains three numbers: N, S and F (1 ≤ N ≤ 100, 1 ≤ S, F ≤ N),
where N is the number of vertices of the graph, S is the initial vertex, 
and F is the final vertex. in the next N lines, N numbers not exceeding 100 
are entered - matrix adjacency of the graph, where -1 means there is no edge 
between the vertices, and any a non-negative number – the presence of an 
edge of a given weight.
Next you are given the user's response in the format:
the first line gives the value r - the required distance or -1 if the paths 
between the specified vertices do not exist
the next line contains a space-separated sequence of vertices in order
bypass

When operating the checker, the following options must be taken into account:
if the path found by the user is incorrect, the checker should display a status
“WA” if the found path is correct, the checker should display the status “OK”*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> breadthFirstSearch(vector<vector<int>>& graph,
    int startVertex, int endVertex) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(startVertex);

    visited[startVertex] = true;
    distance[startVertex] = 0;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (vertex == endVertex) {
            break;
        }

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                distance[neighbor] = distance[vertex] + 1;
                parent[neighbor] = vertex;
            }
        }
    }

    if (distance[endVertex] == -1) {
        return vector<int>();
    }

    vector<int> path;
    int currentVertex = endVertex;

    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }

    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int n;
    cin >> n;
    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int edge;
            cin >> edge;

            if (edge == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    startVertex--;
    endVertex--;

    vector<int> path = breadthFirstSearch(graph, startVertex, endVertex);

    vector<vector<int>> adjacency(n, vector<int>(n));

    bool answer = true;
    int r;
    cin >> r;
    if (r == -1 && path.size() == 0) {
        answer = true;
    }
    else if (path.size() != r) {
        answer = false;
    }
    else {
        vector<int> submit(r);
        for (int i = 0; i < r; i++) {
            cin >> submit[i];
        }

        for (int i = 1; i < r; i++) {
            if (adjacency[submit[i - 1]][submit[i]] == 0) {
                answer = false;
                break;
            }
        }
    }

    if (answer) {
        cout << "OK";
    }
    else {
        cout << "WA";
    }

    return 0;
}