#include <iostream>
#include <vector>


#include <stack>
using namespace std;







int main () {

    vector<vector<int>> adj;
    adj.resize(100);


    // [0] -> 1 , 2
    // [1] -> 0,
    // [2] -> 0
    // undirected

    adj[0].push_back(1);
    adj[1].push_back(0);


    adj[0].push_back(2);
    adj[2].push_back(0);



}