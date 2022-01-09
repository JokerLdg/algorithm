#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
#define endl '\n'

vector<string> alphabets = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int solution(string s) {
    for (int i=0, size=alphabets.size(); i < size; i++) {
        s = regex_replace(s, regex(alphabets[i]), numbers[i]);
    }

    return stoi(s);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string alphabet;
    cin >> alphabet;

    cout << solution(alphabet) << endl;

    return 0;
}