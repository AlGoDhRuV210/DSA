#include <iostream>
 
const int MAX_SIZE = 500005;
int b[MAX_SIZE];
 
void solve() {
    int n, m;
    std::cin >> n >> m;
 
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
 
    bool is_consecutive = true;
    for (int i = 1; i < m; ++i) {
        if (b[i] != b[i - 1] + 1) {
            is_consecutive = false;
            break;
        }
    }
 
    if (is_consecutive) {
        long long last_element = b[m - 1];
        long long answer = n - last_element + 1;
        std::cout << answer << '
';
    } else {
        std::cout << 1 << '
';
    }
}
 
int main() {
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}