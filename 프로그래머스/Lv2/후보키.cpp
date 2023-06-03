#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> candidates; // �̹� �˻��� �ĺ�Ű�� ����Ѵ�.

bool isSubset(int target, int previous) {
    return ((target & previous) == previous);
}

bool check_minimality(int target) { // ������ ����� �ĺ�Ű�� ��ġ�� false
    for (int previous : candidates) {
        if (isSubset(target, previous))
            return false;
    }
    return true;
}

bool check_uniqueness(int i, vector<vector<string>> relation) {
    int k = relation[0].size();
    vector<string> combined;

    for (auto v : relation) {
        string temp = "";
        for (int j = 0; j < k; j++)
            if ((i & (1 << j)) != 0) 
                temp += v[j];
        if (find(combined.begin(), combined.end(), temp) != combined.end())
            return false; 
        else
            combined.push_back(temp);
    }
    return true; 
}

int solution(vector<vector<string>> relation) {
    int k = relation[0].size(); // Attribute�� ����
    for (int i = 1; i < (1 << k); i++) {
        if (check_uniqueness(i, relation) && check_minimality(i)) 
            candidates.push_back(i);
    }
    int answer = candidates.size();
    return answer;
}

int main() {
    vector<vector<string>> v = { 
        {"100","ryan","music","2"},
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2"}
    };
    cout << solution(v) << endl;
    return 0;
}