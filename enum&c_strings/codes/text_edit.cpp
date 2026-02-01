#include <iostream>
#include <cstring>
#define endl '\n'
using std::cin;
using std::cout;


enum MenuOption{
    PRINTASCII,
    TOGGLECASE,
    LOWERCASE,
    UPPERCASE,
    COUNTDIGITS,
    DIGITSTOCHAR
};

int main(){
    cout << "Choose an option:" << endl;
    cout << "0 -> Print ASCII code of char" << endl;
    cout << "1 -> Make the uppercase to lowercase and vice versa" << endl;
    cout << "2 -> Make the whole text lowercase" << endl;
    cout << "3 -> Make the whole text uppercase" << endl;
    cout << "4 -> Count the digits in text" << endl;
    cout << " -> Convert symbol in digit" << endl; 

    cout << "Choose option from the given ones:" << endl;
    int option;
    cin >> option;

    char txt[] = {"This is the best Party 115!"};
    cout << txt << endl;


    switch(MenuOption (option)){
        case PRINTASCII: {
            int ch;
            cin >> ch;
            if (ch >= 32 && ch <= 126) { 
                cout << (char)ch << endl;
            }
        }break;
        case TOGGLECASE:{
            for(int i = 0; txt[i] != '\0'; i++){
                if(txt[i] >= 'A' && txt[i] <= 'Z'){
                    txt[i] += ' '; 
                }
                else if(txt[i] >= 'a' && txt[i] <= 'z'){
                    txt[i] -= ' ';
                }
                cout << txt[i];
            }
        }break;
        case LOWERCASE:{
            char* ptr = txt;
            while(*ptr != '\0'){
                if(*ptr >= 'A' && *ptr <= 'Z'){
                    *ptr += ' ';
                }
                ptr++;
            }
        cout << txt << endl;
        }break;
        case UPPERCASE:{
            size_t sz = strlen(txt);
            for(int i = 0; i < sz; i++){
                if(*(txt + i) >= 'a' && *(txt + i) <= 'z'){
                    *(txt + i) -= ' ';
                }
            }
            cout << txt << endl;
        }break;
        case COUNTDIGITS:{
            char* ptr = txt;
            int cnt = 0;
            while(*ptr != '\0'){
                if(*ptr >= '0' && *ptr <= '9'){
                    cnt++;
                }
            ptr++;
            }
            cout << cnt << endl;
        }break;
        case DIGITSTOCHAR:
        default: std::cout << "Invalid input";
    }

    return 0;
}