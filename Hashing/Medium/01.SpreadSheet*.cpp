#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Spreadsheet {
public:
    int **arr;
    int rows;

    Spreadsheet(int rows) {
        this->rows = rows;
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[26]();
        }
    }

    ~Spreadsheet() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void setCell(string cell, int value) {
        if (cell.empty()) return;
        char colChar = cell[0];
        int row = stoi(cell.substr(1)) - 1;
        int col = colChar - 'A';
        if (row >= 0 && row < rows && col >= 0 && col < 26) {
            arr[row][col] = value;
        }
    }

    void resetCell(string cell) {
        if (cell.empty()) return;
        char colChar = cell[0];
        int row = stoi(cell.substr(1)) - 1;
        int col = colChar - 'A';
        if (row >= 0 && row < rows && col >= 0 && col < 26) {
            arr[row][col] = 0;
        }
    }

    int getValue(string formula) {
        string first = "", second = "";
        int i = 1;
        while (i < formula.size() && formula[i] != '+') {
            first.push_back(formula[i]);
            i++;
        }
        i++;
        while (i < formula.size()) {
            second.push_back(formula[i]);
            i++;
        }

        int x = 0, y = 0;

        if (!first.empty()) {
            if (first[0] >= 'A' && first[0] <= 'Z') {
                char colChar = first[0];
                int row = stoi(first.substr(1)) - 1;
                int col = colChar - 'A';
                if (row >= 0 && row < rows && col >= 0 && col < 26) {
                    x = arr[row][col];
                }
            } else {
                try {
                    x = stoi(first);
                } catch (const std::invalid_argument& e) {
                    return 0;
                }
            }
        }

        if (!second.empty()) {
            if (second[0] >= 'A' && second[0] <= 'Z') {
                char colChar = second[0];
                int row = stoi(second.substr(1)) - 1;
                int col = colChar - 'A';
                if (row >= 0 && row < rows && col >= 0 && col < 26) {
                    y = arr[row][col];
                }
            } else {
                try {
                    y = stoi(second);
                } catch (const std::invalid_argument& e) {
                    return 0;
                }
            }
        }

        return x + y;
    }
};


int main(){
    Spreadsheet s(3); // Initialize a spreadsheet with 3 rows
    s.setCell("A1", 5); // Set cell A1 to 5
    s.setCell("B2", 10); // Set cell B2 to 10
    cout << s.getValue("A1+B2") << endl; // Should output 15
    s.resetCell("A1"); // Reset cell A1 to 0
    cout << s.getValue("A1+B2") << endl; // Should output 10
    return 0;
}