#include <iostream>

using namespace std;

int main(){
    long long int t,pileOne, pileTwo;

    cin >> t; 

    while(t>0){
        cin >> pileOne;
        cin >> pileTwo;
        if(pileTwo > pileOne){
            swap(pileOne,pileTwo);
        }
        if(((pileOne+pileTwo) % 3) != 0 || pileOne > 2*pileTwo){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        
        t--;
    }
    return 0;
}