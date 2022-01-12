#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

int alpha[26];
int solution(vector<string> words) {
    int num = 9;
    int answer = 0;

    for (string word: words) {
        int pow = 1;
        for (int j = word.size()-1; j >= 0; j--) {
            int val = word[j] - 'A'; // 대문자 이므로 A를 빼준다.
            alpha[val] += pow;  // 해당 알파벳 위치에 값을 더한다.
            pow *= 10;
        }
    }

    sort(alpha, alpha+26, greater<>());

    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            break;
        }

        answer += (alpha[i] * num);
        num--;
    }

    return answer;
}

int main() {
    // 단어 수학
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    vector<string> words;
    string s;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> s;
        words.push_back(s);
    }

    cout << solution(words) << endl;

    return 0;
}
