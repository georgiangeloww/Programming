// name, lastname, kilograms.

# include <iostream>
# include <string>

int main(){
    std::string name, lastname;
    int kg;

    std::cout << "Enter your first name:";
    std::cin >> name;

    std::cout << "Enter your last name:";
    std::cin >> lastname;

    std::cout << "Enter your kilograms:";
    std::cin >> kg;

    std::cout << "Your full name is:" << name << "" << lastname << std::endl;
    std::cout << "Your weight is: " << kg;


    return 0;
}