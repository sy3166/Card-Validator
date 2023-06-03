
#include <bits/stdc++.h>
using namespace std;

bool isString(string &s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccNumber;
    
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;
        
        if (ccNumber == "exit")
            break;
        
        else if (!isString(ccNumber)) {
            cout << "Bad input! ";
            continue;
        }
            
        int len = ccNumber.length();
        int doubble = 0;
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int twice = ((ccNumber[i] - 48) * 2);
            if (twice > 9) {
                twice = (twice / 10) + (twice % 10);
            }
            doubble += twice;
        }
        
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubble += (ccNumber[i] - 48);
        }
        
        cout << (doubble % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        
        continue;        
    }

    return 0;
}