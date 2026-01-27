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

    bool is_polindrom = 1;
    int end_i = n - 1;
    for(int i = 0; i < n / 2; i++){
        if(arr[i] != arr[end_i]){
            is_polindrom = 0;
            std::cout << "NO";
            break;
        }
        end_i--;
    }

    if(is_polindrom){
        std::cout << "YES";
    }
    
    return 0;
}