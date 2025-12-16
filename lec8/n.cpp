

#include <iostream>
#include <map>
#include <vector>
using namespace std;


int get_hash(string s) {
    int p = 29;
    int p_pow = 1;
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}


// Prefix Hash Array


vector<int> get_h(string s) {
    int n = s.size();

    vector<int> h(n);

    h[0] = s[0];          // First character
    int p = 29;
    int p_pow = 29;       // p^1

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    // abcd 
    

    return h;
}




int main () {

    int n;
    cin >> n;



    vector<string> strings(n);
    map<int, vector<int>> hash_map;  // hash -> indices

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        int h = get_hash(strings[i]);
        hash_map[h].push_back(i);
    }


    cout << "Identical string pairs:" << endl;


    for (auto& pair : hash_map) {
        vector<int>& indices = pair.second;

        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                if (strings[indices[i]] == strings[indices[j]]) {
                    cout << indices[i] << " " << indices[j] << endl;
                }
            }
        }
    }



    return 0;


}