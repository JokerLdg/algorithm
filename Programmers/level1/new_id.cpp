#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
#define endl '\n'

string solution(string new_id) {
    string answer;

    // 1. 소문자로 변환
    for (char& ch: new_id) {
        if (ch >= 'A' && ch <= 'Z') {
            ch |= 32;
        }
    }

    // 2. 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    for (char& ch: new_id) {
        if ( (ch >= 'a' && ch <= 'z')
            || (ch >= '0' && ch <= '9')
            || strchr("-_.", ch)) {
            answer += ch;
        }
    }

    // 3. 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    new_id = answer;
    answer.clear();

    for (char &ch: new_id) {
        // answer 맨 뒤가 .이고, ch가 .이면 글자 제외
        if (!answer.empty() && answer.back() == '.' && ch == '.') {
            continue;
        }
        answer += ch;
    }

    // 4. new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (answer.front() == '.') {
        answer.erase(answer.begin());
    }

    if (answer.back() == '.') {
        answer.pop_back();
    }

    // 5. new_id가 빈 문자열이라면, new_id에 "a"를 대입
    if (answer.empty()) {
        answer = "a";
    }

    // 6. new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
    }

    if (answer.back() == '.') {
        answer.pop_back();
    }

    // 7. new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙인다.
    while(answer.size() <= 2) {
        answer += answer.back();
    }

    return answer;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << solution("=.=") << endl;

    return 0;
}