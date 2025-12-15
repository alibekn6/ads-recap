// rabin karp algo


#include <iostream>
#include <map>
#include <vector>

using namespace std;


int get_hash(string s) {
    int p = 29; // prime
    int p_pow = 1;
    int hash = 0;

    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * p_pow;
        p_pow *= p;
    }

    return hash;
}

// Given an array of n strings, find all pairs of identical strings.

int main () {

    int n;
    cin >> n;

    vector<string> strings(n);


    map<int, vector<int>> hash_map;



    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        int h = get_hash(strings[i]);
        hash_map[h].push_back(i);
    }


    cout << "Identical string pairs:" << endl;
    for (auto& pair : hash_map) {
        vector<int>& indices = pair.second;
        // All strings with same hash are potentially identical
        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                // Double-check actual strings to avoid hash collisions
                if (strings[indices[i]] == strings[indices[j]]) {
                    cout << indices[i] << " " << indices[j] << endl;
                }
            }
        }
    }


    



    return 0;
}