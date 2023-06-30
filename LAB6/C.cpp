#include <iostream>
#include <vector>
#include <list>

using namespace std;


unsigned int hash1(int key, int size) {
    return key % size;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    cin >> N;
    int table_size=10000;
    bool g = true;
    vector<vector<int>> arr(table_size);
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        unsigned int ind = hash1(value, table_size);
        arr[ind].push_back(value);
    }
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        bool flag = false;
        unsigned int ind = hash1(value, table_size);
        for (auto a: arr[ind]) {
            if (a == value){
                flag = true;
                break;
            }
        }
        if (!flag){
            g = false;
            break;

        }
    }
    if (g) cout << "YES";
    else cout << "NO";
    return 0;
}