#include <iostream>
#include <cstdlib>
#include <ctime>
#define endl '\n'
using std::cout;
using std::cout;




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

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    cout << "Spiral row: ";
    while(top <= bottom && left <= right){
        for(int j = left; j <= right; j++){
            cout << rand_arr[top][j] << ' ';
        }
        top++;

        for(int i = top; i <= bottom; i++){
            cout << rand_arr[i][right] << ' ';
        }
        right--;

        if(top <= bottom){
            for(int j = right; j >= left; j--){
                cout << rand_arr[bottom][j] << ' ';
            }
            bottom --;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                cout << rand_arr[i][left] << ' ';
            }
            left++;
        }
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