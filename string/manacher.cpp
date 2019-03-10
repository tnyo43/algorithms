#include <iostream>

using namespace std;

const int MAX = 1e5;

int R[MAX];
string S;

void manacher(string S) {
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
        R[i] = j;
        int k = 1;
        while (i-k >= 0 && i+k < S.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
        i += k; j -= k;
    }
}

int main() {
    cin >> S;
    manacher(S);
    for (int i = 0; i < S.size(); i++)
        cout << S.substr(i-R[i]+1, 2*R[i]-1) << "\n";
}