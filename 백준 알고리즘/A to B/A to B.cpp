#include <iostream>
#include <string>

using namespace std;

int A, B;
int cnt = 1;
string s;

int main() {
    cin >> A >> B;
    s = to_string(B);

    while (true) {
        if (s[s.length() - 1] == '1') { //1로 끝날 때
            cnt++;
            s = s.substr(0, s.length() - 1);
            B = stoi(s);
        }
        else if (!(B % 2)) {
            cnt++;
            B /= 2;
            s = to_string(B);
        }
        else if (B % 2) {
            cnt = -1;
            break;
        }

        if (A == B) break;
        else if (A > B) {
            cnt = -1;
            break;
        }
    }
    cout << cnt;

}