#include <iostream>


int main(){

    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int nums;
        std::cin >> nums;

        arr[i] = nums;
    }

    int counter = 0;
    int temp;
    for(int i = 0; i < n - 1; i++){
        if(arr[i + 1] >= arr[i]){
            counter++;
        }
        else{
            if(counter > temp){
                temp = counter;
            }
            counter = 0;
        }
    }
    std::cout << "The longest incereasing sequence is out of " << temp + 1 << " adjacent elements!";

    return 0;
}