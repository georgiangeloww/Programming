#include <iostream>

void inputArr(int * arr, int n, int i);
void printArr(int * arr, int n, int i);
int sumArr(int * arr, int n, int i);

int main(){
    int n;
    std::cin >> n;
    
    int* arr = new int[n];

    inputArr(arr, n, 0);
    printArr(arr, n, 0);
    std::cout << std::endl;
    std::cout << sumArr(arr, n, 0);
    

    if(arr != nullptr){
        delete[]arr;
    }
    arr = nullptr;

    return 0;
}

void inputArr(int * arr, int n, int i){
    if(i == n) return;

    std::cin >> arr[i];
    return inputArr(arr, n, i + 1);
}

void printArr(int * arr, int n, int i){
    if(i == n) return;

    std::cout << arr[i] << " ";
    return printArr(arr, n, i + 1);
}

int sumArr(int* arr, int n, int i){
    if(i == n) return 0;

    return arr[i] + sumArr(arr, n, i + 1);
}