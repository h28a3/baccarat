#include<iostream>
#include<vector>
#include <ctime>
using namespace std;

int point(vector<int> hand) {
	int ans = 0;
	for (int i : hand) {
		if (i < 10) {
			ans += i;
		}
	}
	while (ans >= 10) {
		ans -= 10;
	}
	return ans;
}

int main(void) {
	int chip;
	int flag = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand((unsigned int)time(NULL));
	
	cout << "チップを何枚購入しますか?";
	cin >> chip;
	while (flag == 0) {
		vector<int> deck(52);
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 13;j++) {
				deck[13 * i + j] = j + 1;
			}
		}
		int input,bet;
		vector<int> player(2);
		vector<int> banker(2);
		cout << "あなたのチップは" << chip << "枚です．\n";
		cout << "Place your bet.(0:player, 1:banker, 2:draw)";
		cin >> input;
		cout << "何枚賭けますか?";
		cin >> bet;
		for (int i = 0;i < 2;i++) {
			int r = rand() % (52 - 2 * i);
			player[i] = deck[r];
			deck.erase(deck.begin() + r);
			r = rand() % (52 - 2 * i - 1);
			banker[i] = deck[r];
			deck.erase(deck.begin() + r);
		}
		cout << "プレイヤーの手札：" << player[0] << ", " << player[1] << ".\n";
		cout << "バンカーの手札：" << banker[0] << ", " << banker[1] << ".\n";
		int player_point = point(player);
		int banker_point = point(banker);

		if (player_point <= 5) {
			int r = rand() % (48);
			player.push_back(deck[r]);
			deck.erase(deck.begin() + r);
			player_point = point(player);
			cout << "プレイヤーの手札：";
			for (int i = 0;i < 3;i++) {
				cout << player[i];
				if (i < 2) {
					cout << ", ";
				}
			}
			cout << ".\n";

			if ((player_point == 0 || player_point == 1 || player_point == 9) && banker_point <= 3) {
				int r = rand() % (47);
				banker.push_back(deck[r]);
				deck.erase(deck.begin() + r);
				banker_point = point(banker);
				cout << "バンカーの手札：";
				for (int i = 0;i < 3;i++) {
					cout << banker[i];
					if (i < 2) {
						cout << ", ";
					}
				}
				cout << ".\n";
			}
			else if ((player_point == 2 || player_point == 3) && banker_point <= 4) {
				int r = rand() % (47);
				banker.push_back(deck[r]);
				deck.erase(deck.begin() + r);
				banker_point = point(banker);
				cout << "バンカーの手札：";
				for (int i = 0;i < 3;i++) {
					cout << banker[i];
					if (i < 2) {
						cout << ", ";
					}
				}
				cout << ".\n";
			}
			else if ((player_point == 4 || player_point == 5) && banker_point <= 5) {
				int r = rand() % (47);
				banker.push_back(deck[r]);
				deck.erase(deck.begin() + r);
				banker_point = point(banker);
				cout << "バンカーの手札：";
				for (int i = 0;i < 3;i++) {
					cout << banker[i];
					if (i < 2) {
						cout << ", ";
					}
				}
				cout << ".\n";
			}
			else if ((player_point == 6 || player_point == 7) && banker_point <= 6) {
				int r = rand() % (47);
				banker.push_back(deck[r]);
				deck.erase(deck.begin() + r);
				banker_point = point(banker);
				cout << "バンカーの手札：";
				for (int i = 0;i < 3;i++) {
					cout << banker[i];
					if (i < 2) {
						cout << ", ";
					}
				}
				cout << ".\n";
			}
			else if (player_point == 8 && banker_point <= 2) {
				int r = rand() % (47);
				banker.push_back(deck[r]);
				deck.erase(deck.begin() + r);
				banker_point = point(banker);
				cout << "バンカーの手札：";
				for (int i = 0;i < 3;i++) {
					cout << banker[i];
					if (i < 2) {
						cout << ", ";
					}
				}
				cout << ".\n";
			}
		}
		else if (banker_point <= 5) {
			int r = rand() % (48);
			banker.push_back(deck[r]);
			deck.erase(deck.begin() + r);
			banker_point = point(banker);
			cout << "バンカーの手札：";
			for (int i = 0;i < 3;i++) {
				cout << banker[i];
				if (i < 2) {
					cout << ", ";
				}
			}
			cout << ".\n";
		}

		if (player_point > banker_point) {
			cout << "プレイヤーの勝利．\n";
			if (input == 0) {
				chip += bet;
			}
			else {
				chip -= bet;
			}
		}
		else if (player_point < banker_point) {
			cout << "バンカーの勝利．\n";
			if (input == 1) {
				chip += bet;
			}
			else {
				chip -= bet;
			}
		}
		else {
			cout << "引き分け．\n";
			if (input == 2) {
				chip += 8 * bet;
			}
			else {
				chip -= bet;
			}
		}

		cout << "Do you want to continue? (0:continue, 1:end)";
		cin >> flag;
	}
	return 0;
}