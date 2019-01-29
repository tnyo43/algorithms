#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SuffixArray {
    int N;
    string S;
    vector<int> rank; // rank[i]:i文字目から始まる文字列の辞書順の順位
    vector<int> lcp; // arrayの1つ後の文字列と一致している文字数
    vector<int> sa; // sa[i]:辞書順でi番目になる文字列の開始位置, rank[sa[i]] = i

    SuffixArray(string S) : S(S) {
        N = S.size();
        vector<int> tmp(N+1), tr(N+1);
        rank = lcp = sa = vector<int>(N+1);
        for (int i = 0; i <= N; ++i) {
            sa[i] = i;
            rank[i] = (i==N)?-1:S[i];
        }
        
        for (int k = 1; k <= N; k<<=1) {
            auto pred_sub = [k, this](int& a, int& b) -> bool {
                return ((a+k <= N)?rank[a+k]:-1)<((b+k <= N)?rank[b+k]:-1);
            };
            auto pred = [pred_sub, k, this](int& a, int& b) -> bool {
                return (rank[a] != rank[b]) ? (rank[a] < rank[b]) : pred_sub(a, b);
            };
            int x = 0;
            if (k != 1) {
               for (int i = 1; i < N+1; ++i) if (rank[sa[i]] != rank[sa[x]]) {
                   sort(sa.begin()+x, sa.begin()+i, pred_sub);
                   x = i;
               }
            }
            sort(sa.begin()+x, sa.end(), pred);
            for (int i = 0; i <= N; ++i) cout << S.substr(sa[i]) << " ";
            cout << endl;
            for (int i = 0; i < N+1; ++i) {
                tmp[sa[i]] = (i==0) ? 0 : tmp[sa[i-1]] + pred(sa[i-1], sa[i]);
            }
            swap(rank, tmp);
        }

        for (int i = 0; i < N+1; ++i)
            tr[sa[i]] = i;

        int h = 0;
        for (int i = 0; i < N; ++i) {
            int j = sa[tr[i]-1];
            cout << i << " " << S.substr(i) << " " << S.substr(j) << " " << h << "\n";
            h = max(0, h-1);
            while (i+h < N && j+h < N && S[j+h] == S[i+h]) h++;
            lcp[tr[i]-1] = h;
        }
    }

    string suffix(int i) {
        return S.substr(sa[i]);
    }
};

string S;

int main() {
//    cin >> S;
    S = "hogeoooge";
    SuffixArray SA(S);
    for (int i = 0; i <= SA.N; ++i) {
        cout << i << " " << SA.sa[i] << " " << SA.lcp[i] << " " << SA.rank[i] << " " << SA.suffix(i) <<"\n";
    }
}