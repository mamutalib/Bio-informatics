#include <bits/stdc++.h>
using namespace std;


int main() {
    string ls = "AGCT", rs="ATGCT";
    int row = ls.size()+1;
    int col = rs.size()+1;

    int data[row][col];
    for(int i = 0; i<row; i++){
        for (int j = 0; j<col; j++) {
            data[i][j] = 0; 
        }
    }

    int match = 1, misMatch = -1, gap = -2; 
    int lef_adj = 0, up_adj = 0, dia_adj = 0;
    for(int i = 1; i<row; i++) {
        for (int j = 1; j<col; j++) {
            lef_adj = data[i-1][j]+gap;
            if(lef_adj<0) {
                lef_adj = 0;
            }
            up_adj = data[i][j-1] + gap;
            if(up_adj<0) {
                up_adj = 0;
            }
            if (ls[i-1] == rs[j-1]) {
                dia_adj = data[i-1][j-1]+match;
            }
            else {
                dia_adj = data[i-1][j-1]+misMatch;
            }
            data[i][j] = max(lef_adj, up_adj);
            data[i][j] = max(dia_adj, data[i][j]);
        }
    }

    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }


    return 0; 
}