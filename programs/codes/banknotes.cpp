#include <iostream>

int main (){
    int sum = 0;
    int sum_Copy = 0;
    int fifty_cnt = 0;
    int twenty_cnt = 0;
    int ten_cnt = 0;
    int five_cnt = 0;
    int two_cnt = 0;
    int one_cnt = 0;

    std::cout << "Enter the sum: ";
    std::cin >> sum;
    sum_Copy = sum;

    // sum / 50 != 0 ? sum += (sum % 50) : sum / 25 != 0 ? sum += (sum % 25) : sum / 10 != 0 ? sum += (sum % 10) 
    // : sum / 5 != 0 ? sum += (sum % 5) : sum / 2 != 0 ? sum += (sum % 2) : sum / 1 != 0 ? sum += (sum % 1) : sum = 0;

    if(sum / 50 != 0){
        fifty_cnt += sum / 50;
        sum %= 50;
    }
    if(sum / 20 != 0){
        twenty_cnt += sum / 20;
        sum %= 20;
    }
    if(sum / 10 != 0){
        ten_cnt += sum / 10;
        sum %= 10;
    }
    if(sum / 5 != 0){
        five_cnt += sum / 5;
        sum %= 5;
    }
    if(sum / 2 != 0){
        two_cnt += sum / 2;
        sum %= 2;
    }
    if(sum / 1 != 0){
        one_cnt += sum / 1;
        sum %= 1;
    }
    
    std::cout << sum_Copy << " →  50×" << fifty_cnt<< ", 20×" << twenty_cnt << ", 10×"<< ten_cnt << 
    ", 5×" << five_cnt << ", 2×" << two_cnt << ", 1×"<< one_cnt;


    return 0;
}