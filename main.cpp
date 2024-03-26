// Program: Tic Tac Toe with Numbers
// Author:  Name: Yousef Osama    Section: not determined   ID: 20230591
// Version: 1.0
// Date: 03-03-2023

#include <bits/stdc++.h>

using namespace std;

void valid(const set<int>& s) {
    bool flag = false;
    cout << "[";
    for (int i: s) {
        if (flag) cout << ", ";
        flag = true;
        cout << i;
    }
    cout << "]\n";
}

int grid[3][3];

void display() {
    cout << "    1   2   3 \n";
    cout << "  +---+---+---+\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " |";
        for (int j = 0; j < 3; j++) {
            cout << ' ';
            if (grid[i][j] == 0)
                cout << ' ';
            else
                cout << grid[i][j];
            cout << " |";
        }
        cout << '\n';
        cout << "  +---+---+---+\n";
    }
}

bool empty(int &row, int &col) {
    if (row < 1 || row > 3 || col < 1 || col > 3) return false;
    row--;
    col--;
    if (grid[row][col] == 0) {
        return true;
    }
    return false;
}

bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // 3 in a row
            if (j + 2 < 3) {
                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15)
                    return true;
            }
            // 3 in a column
            if (i + 2 < 3) {
                if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15)
                    return true;
            }
            // 3 in a diagonal
            if (i + 2 < 3 && j + 2 < 3) {
                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15)
                    return true;
            }
            if (i + 2 < 3 && j - 2 >= 0) {
                if (grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2] == 15)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    set<int> odd;
    set<int> even;
    for (int i = 1; i <= 9; i++) {
        if (i % 2)
            odd.insert(i);
        else
            even.insert(i);
    }
    int turn = 1;
    bool winner = false;
    while (!odd.empty() && !even.empty()) {
        try {
            display();
            cout << "Player " << turn << ", please select a number from: ";
            set<int> &s = turn == 1 ? odd : even;
            valid(s);
            int select;
            while (!(cin >> select) || s.find(select) == s.end()) {
                throw exception();
            }
            cout << "Player " << turn << ", please select a square(a row and a column)\n";
            int row, col;
            while (!(cin >> row >> col) || !empty(row, col)) {
                throw exception();
            }
            s.erase(select);
            grid[row][col] = select;
            if (checkWinner()) {
                cout << "Player " << turn << " wins!\n";
                winner = true;
                break;
            }
            turn = 3 - turn;
        } catch (...) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore();
        }
    }
    if (!winner) {
        cout << "It's a draw!\n";
    }
}
