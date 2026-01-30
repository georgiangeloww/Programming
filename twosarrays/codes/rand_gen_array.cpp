#include <iostream>

int main(){
    int n, m;

    int** rand_arr = new int* [n];

    for(int j = 0; j < m; j++){
        rand_arr[j] = new int [m];
    }



    if(rand_arr != nullptr){
        for(int j = 0; j < m; j++){
            delete[] rand_arr[j];
            rand_arr = nullptr;
        }
        delete[] rand_arr;
        rand_arr = nullptr;
    }
}