#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

    int n = 5;
    int arr[n];


    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    //algoritm of Fisher-Yates for shuffling
    srand((unsigned) time(0));
    int temp = 0;
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i = 0; i < n; i++){
        std::cout << arr[i] << ' ';
    }



    return 0;
}