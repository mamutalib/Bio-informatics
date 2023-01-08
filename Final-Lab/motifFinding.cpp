#include <iostream>
#include <vector>

using namespace std;

vector<int> subs(string string1, string string2) {
    vector<int> loc;
    for (int i = 0; i < string1.length(); i++) {
        if (string2 == string1.substr(i, string2.length())) {
            loc.push_back(i+1);
        }
    }
    return loc;
}

int main() {
    string string1, string2;
    cin >> string1 >> string2;
    vector<int> loc = subs(string1, string2);
    for (int i = 0; i < loc.size(); i++) {
        cout << loc[i] << " ";
    }
    return 0;
}
