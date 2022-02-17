#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    for (string word, word1, word2; cin >> word; word1 = word2 = "") {
        
        // c++20 for (auto flag {true}; const auto& ch : word)
        auto flag {true};
        for (const auto& ch : word) {
            flag ? word1.append(1, ch) : word2.append(1, ch);
            flag = !flag;
        }
        
        cout << word1 << ' ' << word2 << '\n';
    }
    return 0;
}
