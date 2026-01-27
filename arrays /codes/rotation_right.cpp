#include <iostream>

int main(){
    
    int n = 0;
    std::cin >> n;
    int r = 0;
    std::cin >> r;

    int arr[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int newArr[n];
    for(int i = 0; i < n; i++){
        newArr[i] = 0;
    }


    if(r > n){
        r = r % n;
    }

    for(int i = 0; i < n; i++){
        if(r >= i){
            newArr[i + r] = arr[i];
        }
        else{
            newArr[i - (r + 1)] = arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << newArr[i] << " ";
    }

    return 0;
}