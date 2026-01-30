#include <iostream>

int main(){
    int n = 3;
    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> arr[i][j];
        }
    }


    int ind = 0;
    int max = arr[0][0];
    for(int j = 1; j < n; j++){
        if(arr[0][j] > max){
            max = arr[0][j];
            ind = j;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i][ind];
    }
    std::cout << "Sum of the el on colomn " << ind << " with the biggest element " << max << " is:\n" << sum;


    return 0;
}