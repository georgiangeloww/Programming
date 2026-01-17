#include <iostream>

void square(int n, char ch, int rows);
void printChar(int n, char ch);

int main(){

    int n;
    char ch;
    std::cin >> n;
    std::cin >> ch;

    square(n, ch, n);
    
    return 0;
}



void printChar(int n, char ch){
    if(n == 0) return;

    std::cout << ch << " ";
    return printChar(n - 1, ch);
}

void square(int n, char ch, int rows){
    if(rows == 0){
        return;
    }

        printChar(n, ch);

        std::cout << "\n";
        return square(n, ch, rows - 1);  
}

