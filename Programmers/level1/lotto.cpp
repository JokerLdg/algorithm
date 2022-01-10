#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int Rank(int count) {
    switch (count) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

int HasNumber(const vector<int> &arr, int item) {
    int ss = arr.size();

    for (int i = 0, size = arr.size(); i < size; i++) {
        if (arr[i] == item)
            return i;
    }

    return -1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_count = 0;
    int hit_count = 0;

    for (int lotto: lottos) {
        if (lotto == 0) {
            zero_count++;
        } else {
            if (HasNumber(win_nums, lotto) > -1) {
                hit_count++;
            }
        }
    }

    int best_rank = Rank((hit_count + zero_count));
    int worst_rank = Rank(hit_count);

    answer.push_back(best_rank);
    answer.push_back(worst_rank);

    return answer;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> lottos = {44, 1, 0, 0, 31, 24};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};

    vector<int> answer = solution(lottos, win_nums);

    for (auto rank: answer) {
        cout << rank << " ";
    }

    return 0;
}