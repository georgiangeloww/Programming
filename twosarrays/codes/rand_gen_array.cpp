#include <iostream>
#include <cstdlib>
#include <ctime>



int main(){
    int n, m;

    int** rand_arr = new int* [n];

    for(int j = 0; j < m; j++){
        rand_arr[j] = new int [m];
    }

    srand((unsigned int)time(0));

    int max = 112;
    int min = -12;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rand_arr[i][j] = rand() % (max - min + 1) + min;
        }
    }


    if(rand_arr != nullptr){
        for(int j = 0; j < m; j++){
            delete[] rand_arr[j];
            rand_arr = nullptr;
        }
        delete[] rand_arr;
        rand_arr = nullptr;
    }

    return 0;
}