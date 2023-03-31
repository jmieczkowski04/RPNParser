#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "ParseHelper.h"

bool GReversedOrder = true;
bool GParsingFunction = false;
std::string SwitchNotation(std::string& notation);
void SplitString(std::string& input, std::vector<std::string>& out);

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        if (!strcmp(argv[i], "--pn"))
            GReversedOrder = false;

    std::string notation;
    SwitchNotation(notation);

    std::string promptChar = "> ";

    std::cout << "RPNParser. Parsing using " << notation << " Polish notation. To end type \'exit\'. To switch notation type \'switch\'. To define a function type \'def <name>\'. Variable name is x.\n" << promptChar;

    std::vector<std::string> elements;
    std::string input;

    std::string command;
    std::string functionName;

    do
    {
        std::getline(std::cin, input);
        elements.clear();

        SplitString(input, elements);

        command = elements[0];

        if (command == "switch")
        {
            GReversedOrder = !GReversedOrder;
            std::cout << "Switched notation from " << notation << " to " << SwitchNotation(notation) << "\n" << promptChar;
            continue;
        }
        else if (command == "def" && elements.size() == 2)
        {
            GParsingFunction = true;
            functionName = elements[1];
            std::cout << functionName << "(x) " << promptChar;
            continue;
        }
        else if (command == "exit")
            continue;


        if (!GReversedOrder)
        {
            std::reverse(elements.begin(), elements.end());
        }


        Expression* exp = CreateExpression(elements);
        if (exp)
        {
            exp->Parse(elements);
            if (GParsingFunction)
            {
                GParsingFunction = false;
                GFunctionStore.insert(std::pair<std::string, Expression*>(functionName, exp));
                functionName = "";
                std::cout << promptChar;
            }
            else 
            {
                std::cout << exp->GetValue() << "\n" << promptChar;
                delete exp;
            }
            
        }
        else
        {
            std::cout << "Failed to parse\n" << promptChar;
        }

    } while (command != "exit");

    for (auto& e : GFunctionStore)
    {
        delete e.second;
    }

}

std::string SwitchNotation(std::string& notation)
{
    notation = GReversedOrder ? "Reverse" : "Normal";
    return notation;
}

void SplitString(std::string& input, std::vector<std::string>& out)
{
    std::string element;
    std::istringstream inputStream(input);
    while (std::getline(inputStream, element, ' '))
    {
        out.push_back(element);
    }
}