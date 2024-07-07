/*RU
В данной задаче вам дается отсортированный список целых чисел. Его надо 
преобразовать в список, отсортированный вкруговую по указанному индексу 
сдвига. Все элементы после указанного индекса сдвигаются вкруговую.

Входные данные:
Сначала дается число n — индекс кругового сдвига массива, затем элементы 
списка.

Пример:

Входные данные:
1)
4 1 2 3 4 5 6 7 8

2)
1 6 7 8 10 

Выходные данные:
1)
5 6 7 8 1 2 3 4

2)
7 8 10 6

ENG
In this problem you are given a sorted list of integers. It's necessary
convert to a list sorted circularly at the specified index
shift All elements after the specified index are shifted in a circular manner.

Input data:
First, the number n is given - the index of the circular shift of the array, 
then the elements list.

Example:

Input data:
1)
4 1 2 3 4 5 6 7 8

2)
1 6 7 8 10

Output:
1)
5 6 7 8 1 2 3 4

2)
7 8 10 6                             */

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

struct List {
    Node* first;
    Node* last;

    List() {
        first = nullptr;
        last = nullptr;
    }

    bool empty() {
        return first == nullptr;
    }

    void pushBack(int value) {
        Node* p = new Node(value);

        if (empty()) {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
    }

    void print() {
        if (empty()) {
            return;
        }

        Node* p = first;

        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    void circularShift(int k) {
        if (empty() || k <= 0) {
            return;
        }

        Node* current = first;
        int len = 1;

        while (current != last) {
            current = current->next;
            len++;
        }

        last->next = first;

        k = k % len;
        int shift = len - k;

        while (shift--) {
            current = current->next;
        }

        first = current->next;
        last = current;
        last->next = nullptr;
    }
};

int main() {
    int n, num;
    List list;
    cin >> n;

    while (cin >> num) {
        if (num == 0) {
            break;
        }
        list.pushBack(num);
    }

    list.circularShift(n);

    list.print();

    return 0;
}