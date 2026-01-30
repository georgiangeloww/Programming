#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int** arr = new int* [n];
    for(int j = 0; j < n; j++){
        arr[j] = new int [n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        bool isSame = true;
        for(int j = 0; j < n; j++){
            if(arr[i][j] != arr[j][i]){
                isSame = false;
                break;
            }
        }
        if(isSame) std::cout << "On the index " << i << " the row and the column have same elements!\n";
    }

    if(arr != nullptr){
        for(int i = 0; i < n; i++){
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;
    }

    return 0;
}