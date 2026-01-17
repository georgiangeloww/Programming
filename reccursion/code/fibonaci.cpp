#include <iostream>

int fib(int n);
int fib_cycle(int n);

int main(){
    int n;
    std::cin >> n;

    std::cout << "The " << n << " number of Fibonaci with reccursive search is: " << fib(n) << std::endl;
    std::cout << "The " << n << " number of Fibonaci with cycle search is: " << fib_cycle(n);

    return 0;
}

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

int fib_cycle(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}