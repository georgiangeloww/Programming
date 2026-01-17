#include <iostream>

void inputArr(int * arr, int n, int i);
void printArr(int * arr, int n, int i);
int sumArr(int * arr, int n, int i);

int main(){
    int arr[5];

    inputArr(arr, 5, 0);
    printArr(arr, 5, 0);
    std::cout << std::endl;


    return 0;
}

void inputArr(int * arr, int n, int i){
    if(i == n){
        return;
    }

    std::cin >> arr[i];
    return inputArr(arr, n, i + 1);
}

void printArr(int * arr, int n, int i){
    if(i == n) return;

    std::cout << arr[i] << " ";
    return printArr(arr, n, i + 1);
}
