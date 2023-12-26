#include <iostream>

using namespace std;



int main(){
    unsigned long long int n {0};
    unsigned long long int result {1};

    cin >> n;

    for(unsigned long long int i = 0; i < n; i++){
        result *= 2;
        result %= 1000000007;
    }

    cout << result << endl;

    return 0;
}