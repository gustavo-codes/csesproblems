#include <iostream>

using namespace std;

int main(){
    unsigned long int t,row,column, result;
    cin >> t;

    while(t>0){
        cin >> row;
        cin >> column;
        if(row>=column){
            if(row%2 == 0){
                result = (row-1)*(row-1) + (row-1) + (row - column) + 1;
            }else{
                result = (row-1)*(row-1) + (column - 1) + 1;
            }
        }else{
            if(column%2 == 0){
                result = (column-1)*(column-1) + (row-1) + 1;
            }else{
                result = (column-1)*(column-1) + (column-1) + (column-row) + 1;
            }
        }
                
        cout << result << endl;
        t--;
    }

    return 0;
}