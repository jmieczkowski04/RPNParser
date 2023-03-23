#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "ParseHelper.h"

bool GReversedOrder = true;
std::string SwitchNotation(std::string& notation);

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        if (!strcmp(argv[i], "--pn"))
            GReversedOrder = false;

    std::string notation;
    SwitchNotation(notation);

    std::string promptChar = "> ";

    std::cout << "RPNParser. Parsing using " << notation << " Polish notation. To end type \'exit\'. To switch notation type \'switch notation\'.\n" << promptChar;

    std::vector<std::string> elements;
    std::string input;
    std::getline(std::cin, input);

    while (input != "exit")
    {
        if (input == "switch notation")
        {
            GReversedOrder = !GReversedOrder;
            std::cout << "Switched notation from " << notation << " to " << SwitchNotation(notation) << "\n" << promptChar;
            std::getline(std::cin, input);
            continue;
        }

        elements.clear();

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
            std::cout << exp->GetValue() << "\n" << promptChar;
            delete exp;
        }
        else
        {
            std::cout << "Failed to parse\n" << promptChar;
        }

        std::getline(std::cin, input);
    }

    

}

std::string SwitchNotation(std::string& notation)
{
    notation = GReversedOrder ? "Reverse" : "Normal";
    return notation;
}