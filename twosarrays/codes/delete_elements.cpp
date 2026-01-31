#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    
    int newSize = 0;
    for(int i = 0; i < n; i++){
        bool isDuplicate = false;
        for(int j = 0; j < newSize; j++){
            if(arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            arr[newSize] = arr[i];
            newSize++;
        }
    }


    for(int i = 0; i < newSize; i++){
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}