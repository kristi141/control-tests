/*RU
В магазине существует n касс, но как всегда работают из них всего 2. 
Известно, что в магазин планируют прийти k клиентов, для каждого из клиентов 
известно два значения m - время его прихода в магазин, t - время, за которое 
его  обслужат на кассе. (По счастливой случайности благодаря большим данным 
клиенты еще и даны в порядке прихода)

Вам необходимо для каждого клиента вывести время, за которое он сможет 
покинуть магазин, совершив покупку.

При решении задачи обязательно необходимо использовать структуру(-ы)

ENG
There are n cash registers in the store, but as always, only 2 of them are
 working. It is known that k customers are planning to come to the store, 
 for each of the customers two values ​​are known: m - the time of his arrival 
 at the store, t - the time during which he will be served at the checkout. 
 (Fortuitously, thanks to big data clients are also given in order of arrival)

You need to display for each client the time during which he can
leave the store after making a purchase.

When solving a problem, it is necessary to use the structure(s)*/

#include <iostream>
using namespace std;

struct Shop {
	int windows[2]{ 0, 0 };
	int* clients;

	int getMinIndex() {
		int index = 0;
		for (int i = 0; i < 2; i++) {
			if (windows[i] < windows[index]) {
				index = i;
			}
		}
		return index;
	};

	void serve(int number, int came, int time) {
		int index = getMinIndex();

		clients[number] = time + max(0, windows[index] - came);

		windows[index] += time;
	};
};

int main() {
	int k; 
	Shop shop; 

	cin >> k;

	shop.clients = new int[k];

	for (int i = 0; i < k; i++) {
		int m, t; 

		cin >> m >> t;

		shop.serve(i, m, t);
	}

	for (int i = 0; i < k; i++) {
		cout << shop.clients[i] << " ";
	}

	return 0;
}