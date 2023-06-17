#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = -1; 
    
    if(s.length() == 1) return s.length();
    for(int x = 1; x <= s.length() / 2; x++) { // x개 단위로 자르는 경우
        int i = 0; 
        int len = s.length();
        while(true) {
            if(i >= s.length()) break;
            string target = s.substr(i, x);
            
            int k = 0; 
            while(i + x < s.length()) {
                string cand = s.substr(i + x, x);
                if(target == cand) i += x; 
                else break;
                k++;
            }
            
            if(k > 0) {
                int digit = to_string(k + 1).length();
                len = len - x * k + digit;
            }
            i += x;
        }
        if(answer == -1 || answer > len) answer = len;
    }
    return answer;
}