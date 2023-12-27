#include <iostream>

using namespace std;

int main(){
    int n;
    int zeroCout {0};
    cin >> n;

    for(int i = 5; n / i >= 1 ; i *= 5){
        zeroCout += n/i;
    }

    cout << zeroCout << endl;

    return 0;
}