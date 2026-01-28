#include <iostream>
#define endl '\n'
using std::cin;
using std::cout;




int main(){
    int n;
    cin >> n;

    int** arr = new int* [n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    int sum_main = 0;
    for(int i = 0; i < n; i++){
        sum_main += arr[i][i];
    }

    int sum_a_d = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            sum_a_d += arr[i][j];
        }
    }

    cout << "The sum of the elements in the main diagonal of the matrix: " << endl;
    cout << sum_main << endl;

    cout << "The sum of the elements above the main diagonal:" << endl;
    cout << sum_a_d << endl;

    for(int i = 0; i < n; i++){
        if(arr[i] != nullptr){
            delete[] arr[i];
            arr[i] = nullptr;
        }
    }
    if(arr != nullptr){
        delete[] arr;
        arr = nullptr;
    }

    return 0;
}