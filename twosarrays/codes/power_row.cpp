#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>



int main(){
    int n, m;
    std::cin >> n; 
    std::cin >> m; 

    int** rand_arr = new int* [n];

    for(int i = 0; i < n; i++){
        rand_arr[i] = new int [m];
    }

    srand((unsigned int)time(0));

    int max = 112;
    int min = -12;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rand_arr[i][j] = rand() % (max - min + 1) + min;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            rand_arr[i][j] = pow(i + j, i);
        }
    }

    //test output
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << rand_arr[i][j] << '\t'; 
        }
        std::cout << '\n';
    }

    if(rand_arr != nullptr){
        for(int j = 0; j < m; j++){
            delete[] rand_arr[j];
            rand_arr[j] = nullptr;
        }
        delete[] rand_arr;
        rand_arr = nullptr;
    }

    return 0;
}