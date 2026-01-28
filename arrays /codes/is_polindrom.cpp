#include <iostream>

int main(){

    int n;
    std::cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) std::cin >> arr[i];

    bool is_polindrom = 1;
    for(int i = 0; i < n / 2; i++){
        if(arr[i] != arr[n - 1 - i]){
            is_polindrom = 0;
            std::cout << "NO";
            break;
        }
    }

    if(is_polindrom){
        std::cout << "YES";
    }
    
    return 0;
}