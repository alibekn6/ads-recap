#include <iostream>
#include <vector>
using namespace std;



vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);


    // a a b a a a b 

    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        // j = 0;

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
//.     if (a == )
        if (s[i] == s[j]) {
            j++; // 
        }

        pi[i] = j;
    }

    return pi;
}





int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<int> pi = prefix_function(s);

    cout << "\nString:          ";
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;

    cout << "Index:           ";
    for (int i = 0; i < s.size(); i++)
        cout << i << " ";
    cout << endl;

    cout << "Prefix function: ";
    for (int i = 0; i < pi.size(); i++)
        cout << pi[i] << " ";
    cout << endl;

    return 0;
}