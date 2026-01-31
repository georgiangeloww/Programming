#include <iostream>


int main(){
    int n;
    std::cin >> n;
    int arr[n];
    int p, q;
    std::cin >> p;
    std::cin >> q;

    if(n > 100){
        std::cout << "Invalid input!";
        return 1;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        if(arr[i] % 2 == 0 && i % 2 != 0 && i >= p && i <= q) cnt++;
    }

    std::cout << "The count of even elements with odd index in the interval bitween: " << p << " and " << q << " is: " << cnt;


    return 0;
}