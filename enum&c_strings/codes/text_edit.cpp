#include <iostream>
#include <cstring>
#define endl '\n'
using std::cin;
using std::cout;


enum MenuOption{
    PRINTASCII,
    TOGGLECASE,
    CASESENSITIVE,
    COUNTDIGITS,
    DIGITSTOCHAR
};

int main(){
    cout << "Choose an option:" << endl;
    cout << "0 -> print ASCII code" << endl;
    cout << "1 -> Make the uppercase to lowercase and vice versa" << endl;
    cout << " -> Convert lowercase into uppercase or upper into lower" << endl;
    cout << " -> Count the digits in text" << endl;
    cout << " -> Convert symbol in digit" << endl; 

    int option;
    cin >> option;

    char txt[] = {"This is the best Party!"};

    switch(MenuOption (option)){
        case PRINTASCII: {
            int ch;
            cin >> ch;
            if (ch >= 32 && ch <= 126) { 
                cout << (char)ch << endl;
            }
        }break;
        case TOGGLECASE: {
            for (int i = 0; txt[i] != '\0'; i++) {
                if(txt[i] >= 'A' && txt[i] <= 'Z'){
                    txt[i] += ' '; 
                }
                else if(txt[i] >= 'a' && txt[i] <= 'z'){
                    txt[i] -= ' ';
                }
                cout << txt[i];
            }
        }break;
        case CASESENSITIVE:{
            for(int i = 0; txt[i] != '\0'; i++){
                
            }
        }break;
        case COUNTDIGITS:
        case DIGITSTOCHAR:
        default: std::cout << "Invalid input";
    }

    return 0;
}