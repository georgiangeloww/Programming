#include <iostream>

int nextPowerOfTwo(int n);


int main (){
    int a;
    std::cin >> a;

    std::cout << nextPowerOfTwo(a) << '\n';

    return 0;
}

int nextPowerOfTwo(int n){
    int power = 1;
    while(power < n){
        power *= 2;
    } 
    return power;
}