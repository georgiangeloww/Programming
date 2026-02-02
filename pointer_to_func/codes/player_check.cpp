#include <iostream> 
#define endl '\n'
using std::cin;
using std::cout;

typedef bool(*predicate)(int);

bool isProScore(int score);
int* findProGame(int* scores, int n, predicate fp);


int main(){
    int n;
    cin >> n;

    int* scores = new int[n];


    for(int i = 0; i < n; i++){
        cin >> *(scores + i);
    }

    predicate fp = isProScore;
    int* proGamePtr = findProGame(scores, n, fp);


    int index = proGamePtr - scores;
    if(proGamePtr != nullptr){
        cout << "Points of the game:" << endl;
        cout << *proGamePtr << endl;
        cout << "Index of the game: " << endl;
        cout << index << endl;
    }
    else{
        cout << "No pro games found." << endl;
    }

    if(scores != nullptr){
        delete[] scores;
        scores = nullptr;
    }
    return 0;
}

bool isProScore(int score){
    return score >= 100;
}

int* findProGame(int* scores, int n, predicate fp){
    int* start = scores;
    int* end = scores + n;
    
    while(start < end){
        if(fp(*start)){
            return start;
        }
        start++;
    }
    return nullptr;
}
