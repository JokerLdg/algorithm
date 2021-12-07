#include <bits/stdc++.h>

using namespace std;

// 잃어버린 괄호 문제
/*
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
 */

#define endl "\n"

int main() {

    string s;
    int result = 0;
    string num;
    bool isminus = false;

    cin >> s;

    // - 가 오면 그뒤에 오는 숫자들을 전부 빼준다.
    for (int i=0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.size()) {
            if (isminus) {
                result -= stoi(num);
                num = "";
            } else {
                result += stoi(num);
                num = "";
            }
        } else {
            num += s[i];
        }

        if (s[i] == '-') {
            isminus = true;
        }

    }

    cout << result << endl;

    return 0;
}
