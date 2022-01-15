#include <iostream>

using namespace std;
#define endl '\n'

int main() {
    // 뒤집기 문제
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    int count = 0;
    cin >> S;

    for (int i=0, size=S.size(); i<size; i++) {
        if (S[i] != S[i+1]) {
            count++;
        }
    }

    cout << count/2 << endl;

    return 0;
}

