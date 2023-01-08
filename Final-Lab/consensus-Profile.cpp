#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<string> seq_name, seq_string;
    map<char, int> symbol_to_index;
    symbol_to_index['A'] = 0;
    symbol_to_index['C'] = 1;
    symbol_to_index['G'] = 2;
    symbol_to_index['T'] = 3;
    vector<string> symbols = {"A", "C", "G", "T"};
    string consensus_string;
    vector<vector<int>> profile_matrix;
    for (int i = 0; i < 4; i++) {
        profile_matrix.push_back(vector<int>());
    }

    // load data
    string line;
    while (getline(cin, line)) {
        if (line[0] == '>') {
            seq_name.push_back(line.substr(1));
        } else {
            seq_string.push_back(line);
        }
    }
    int seq_len = seq_string.size();
    int str_len = seq_string[0].length();

    for (int c = 0; c < str_len; c++) {
        vector<char> position_symbol;
        for (int i = 0; i < seq_len; i++) {
            position_symbol.push_back(seq_string[i][c]);
        }
        char most_common_symbol = *max_element(position_symbol.begin(), position_symbol.end(), [&position_symbol](char a, char b) {
            return count(position_symbol.begin(), position_symbol.end(), a) < count(position_symbol.begin(), position_symbol.end(), b);
        });
        consensus_string += most_common_symbol;
        for (int r = 0; r < 4; r++) {
            profile_matrix[r].push_back(count(position_symbol.begin(), position_symbol.end(), symbols[r][0]));
        }
    }

    cout << consensus_string << endl;
    for (int i = 0; i < 4; i++) {
        cout << symbols[i] << ": ";
        for (int j = 0; j < str_len; j++) {
            cout << profile_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
