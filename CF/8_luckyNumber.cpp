

#include <iostream>
#include <string>

bool isLucky(int number) {
    std::string strNumber = std::to_string(number);
    for (char digit : strNumber) {
        if (digit != '4' && digit != '7') {
            return false;
        }
    }
    return true;
}

bool isAlmostLucky(int number) {
    for (int i = 1; i <= number; ++i) {
        if (number % i == 0 && isLucky(i)) {
            return true;
        }
    }
    return false;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    std::cin >> n;
    
    if (isAlmostLucky(n)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}
