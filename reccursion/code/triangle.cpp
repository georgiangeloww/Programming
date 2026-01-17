#include <iostream>


void printChar(char ch, int count);
void triangle(int n, char ch, int row);

int main(){

    int n;
    char ch;    
    std::cin >> n;
    std::cin >> ch;

    triangle(n, ch, 1);

    
    return 0;
}


void printChar(char ch, int count){
    if(count == 0) return;

    std::cout << ch << " ";
    return printChar(ch, count - 1);
}

void triangle(int n, char ch, int row){
    if(row > n){
        return;
    }

        printChar(ch, row);
        std::cout << "\n";
        
        return triangle(n, ch, row + 1);
}
