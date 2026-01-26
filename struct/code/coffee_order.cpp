#include <iostream>
#include <string>
#define endl '\n'
using std::cout;
using std::cin;



struct Coffee{
    std::string name;
    char size;
    int cups;
    double price;
    void input();
    double pricePerDrink();

};


int main(){
    int n;
    cout << "How many orders do you have: " << endl;
    cin >> n;
    Coffee** drinkArr = new Coffee* [n];
    for(int i = 0; i < n; i++){
        drinkArr[i] = new Coffee;
    }
    
    

    for(int i = 0; i < n; i++){
        cout << "The final price for order number " << i + 1 << "is: " << endl;
        cout << drinkArr[i]->pricePerDrink();
    }

    if(drinkArr != nullptr){
        for(int i = 0; i < n; i++){
            delete[] drinkArr[i];
            drinkArr[i] = nullptr;
        }
        delete[] drinkArr;
        drinkArr = nullptr;
    }

    return 0;
}

void Coffee::input(){
    cout << "What drink would like?" << endl;
    cin >> name;

    cout << "In what size do you want the " << name << endl;
    cin >> size;
    
    cout << "How many cups do want from it" << endl;
    cin >> cups;

    cout << "The price for a cup is: " << endl;
    cin >> price;
}

double Coffee::pricePerDrink(){
    return price * cups;
}