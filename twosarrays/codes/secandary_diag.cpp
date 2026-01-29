#include <iostream>
#define endl '\n'
using std::cout;
using std::cin;

int main(){
    int n;
    cin >> n;

    int** arr = new int* [n];

    for(int j = 0; j < n; j++){
        arr[j] = new int [n];
    }



    for(int j = 0; j < n; j++){
        if(arr[j] != nullptr){
            delete[] arr[j];
            arr[j] = nullptr;
        }
    }

    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }

    return 0;
}