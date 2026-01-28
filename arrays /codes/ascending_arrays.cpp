#include <iostream>

int main(){
   
    int n, m;
    std::cin >> n;
    std::cin >> m;

    int* arr1 = new int[n];
    int* arr2 = new int[m];
    int* arr3 = new int[n + m];

    for(int i = 0; i < n; i++){
        std::cin >> arr1[i];
    }

    for(int i = 0; i < m; i++){
        std::cin >> arr2[i];
    }


    int c = 0;
    int p = 0;
    for(int i = 0; i < n + m; i++){
        if(c == m){
            arr3[i] = arr1[p++];
        }
        else if(p == n){
            arr3[i] = arr2[c++];
        }
        else{
            if(arr1[p] > arr2[c]){
            arr3[i] = arr2[c++];
            }
            else{
                arr3[i] = arr1[p++];
            }
        }
    }
        

    for(int i = 0; i < n + m; i++){
        std::cout << arr3[i] << " ";
    }

    if(arr1 != nullptr){
        delete[] arr1;
        arr1 = nullptr;
    }

    if(arr2 != nullptr){
        delete[] arr2;
        arr2 = nullptr;
    }

    if(arr3 != nullptr){
        delete[] arr3;
        arr3 = nullptr;
    }

    return 0;
}