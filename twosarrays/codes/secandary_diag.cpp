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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }


    int sum_sec_d = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - i - 1; j < n - i; j++){
            sum_sec_d += arr[i][j];
        }
    }

    int a_sec_d = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            a_sec_d += arr[i][j];
        }
    }

        int b_sec_d = 0;
    for(int i = 1; i < n; i++){
        for(int j = n - 1; j > n - i - 1; j--){
            b_sec_d += arr[i][j];
        }
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