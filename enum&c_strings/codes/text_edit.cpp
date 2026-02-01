#include <iostream>
#include <cstring>
#define endl '\n'
using std::cin;
using std::cout;


enum MenuOption{
    PRINTASCII,
    CASESENSITIVE,
    COUNTDIGITS,
    DIGITSTOCHAR
};

int main(){
    cout << "Choose an option:" << endl;
    cout << "0 -> print ASCII code" << endl;
    cout << "1 -> Convert lowercase into uppercase or upper into lower" << endl;
    cout << "2 -> Count the digits in text" << endl;
    cout << "3-> Convert symbol in digit" << endl; 

    int option;
    cin >> option;

    


    char text[100];


    // std::cin.getline(text, 100);

    


    switch(MenuOption (option)){
        case PRINTASCII: {
            int ch;
            cin >> ch;
            if (ch >= 32 && ch <= 126) { 
                cout << (char)ch << endl;
            }
        }break;
        case CASESENSITIVE:{
            // for(int i = 0; i < n; i++){

            // }
            // if(text[i])
        }break;
        case COUNTDIGITS:
        case DIGITSTOCHAR:
        default: std::cout << "Invalid input";
    }

    return 0;
}