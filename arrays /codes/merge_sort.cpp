#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int* a = new int[n];
    int* b = new int[m];
    int* c = new int[n + m];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0, k = 0;

    // докато и двата имат елементи
    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // ако останат елементи в първия
    while(i < n) {
        c[k++] = a[i++];
    }

    // ако останат елементи във втория
    while(j < m) {
        c[k++] = b[j++];
    }

    for(int t = 0; t < n + m; t++) {
        cout << c[t] << " ";
    }
    
    delete[] a;
    delete[] b;
    delete[] c;
}
