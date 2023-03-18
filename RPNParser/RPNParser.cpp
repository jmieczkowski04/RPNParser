#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "ParseHelper.h"

bool GReversedOrder = true;


int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        if (!strcmp(argv[i], "--pn"))
            GReversedOrder = false;

    std::vector<std::string> elements;

    std::string input;
    std::getline(std::cin, input);

    std::string element;
    std::istringstream inputStream(input);
    while (std::getline(inputStream, element, ' '))
    {
        elements.push_back(element);
    }

    if (!GReversedOrder)
    {
        std::reverse(elements.begin(), elements.end());
    }

    
    Expression* exp = CreateExpression(elements);
    if (exp)
    {
        exp->Parse(elements);
        std::cout << exp->GetValue();
    }
    else 
        std::cout << "Failed to parse";

}
