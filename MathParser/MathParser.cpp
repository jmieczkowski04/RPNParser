#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "ParseHelper.h"

int main()
{
    
    std::vector<std::string> elements;

    std::string input;
    std::getline(std::cin, input);

    std::string element;
    std::istringstream inputStream(input);
    while (std::getline(inputStream, element, ' '))
    {
        elements.push_back(element);
    }

    /* we should check if there is no invalid chars, but:
    * 1) math operators are handled
    * 2) stod throws exception
    * so we dont have to do that
    */

    Expression* exp = CreateExpression(elements);
    if (exp)
    {
        exp->Parse(elements);
        std::cout << exp->GetValue();
    }
    else {
        std::cout << "Failed to parse";
    }
    
}
