#include <iostream>
using namespace std;
#include <vector>


vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);

    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}




void kmp(string text, string pattern) {
    string s = pattern + "#" + text;

    int n = s.size();
    int m = pattern.size();

        // ex  : abcabcd.    pattern : bc
        // bc#abcabcd
        //
    vector<int> pi = prefix_function(s); // [0 0 0 0 1 2 0 1 2 0]


    for (int i = m + 1; i < n; i++) {
        if (pi[i] == m) {
            int pos = i - 2 * m;
            cout << "Pattern found at index " << pos << endl;
        }
    }

}


int main () {

    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    cout << endl << "Searching for pattern in text -> " << endl;
    kmp(text, pattern);


    return 0;
}