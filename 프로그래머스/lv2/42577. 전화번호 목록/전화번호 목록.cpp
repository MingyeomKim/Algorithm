#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isAHeadOfB(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(b[i] != a[i]) return false;
    }
    return true;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());  // 사전순 정렬
    
    int n = phone_book.size(); 
    for(int i= 1; i < n; i++){
        string a = phone_book[i - 1], b = phone_book[i]; 
        if(isAHeadOfB(a, b)) return false; 
    }
    return true;
}

/*
 접두어
 하나의 문자열을 다른 문자열과 비교한다.
*/