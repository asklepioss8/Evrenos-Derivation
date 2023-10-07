#include "derivation_scopes.hpp"
#include <iostream>

DerivationScopes::DerivationScopes(std::string inputStr) : inputStr(inputStr)
{
    std::cout << "DerivationScopes constructor called" << std::endl;
    run();
}

DerivationScopes::~DerivationScopes()
{
    std::cout << "DerivationScopes destructor called" << std::endl;
}

void DerivationScopes::run()
{
    std::cout << "DerivationScopes run function called" << std::endl;
    create_derivation_functions();
    sort_derivation_functions();
    fast_forward_derivation_solver();
}

// define create_derivation_functions function. This function creates a vector of derivation_function structs pointers.
// each derivation scope is defined by "$d{" and "}" and the expression between them is the data of the struct.
// the scope of the derivation is the number of "$d{" before plus one.
// the data of the struct is the expression between "$d{" and "}".
// the tokenised_data of the struct is defined later in fast_forward_derivation_solver's subfunction lexical_analysis.
// One of the important thing is after each '@' statement the scope of the derivation is decreased by one.

#pragma(warning(disable: 5040))
void DerivationScopes::create_derivation_functions()
{
    std::cout << "DerivationScopes create_derivation_functions function called" << std::endl;
    size_t len = inputStr.size();
    int scope = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (inputStr[i] == '$' && inputStr[i + 1] == 'd')
        {
            derivation_function* temp = new derivation_function;
            temp->scope = scope;
            
            int counter = 0;
            for (size_t j = i + 3; j < len; j++)
            {
                if (inputStr[j] == '{')
                {
                    counter++;
                }
                else if (inputStr[j] == '}')
                {
                    counter--;
                }
                if (counter < 0)
                {
                    temp->data = inputStr.substr(i + 3, static_cast<size_t>(j - i - 3));
                    derivation_functions.push_back(temp); // push the pointer
                    scope++;
                }
                else if (inputStr[i] == '@' && inputStr[i + 1] == '{')
                {
                    scope--;
                }
            }
        }
    }
}

void DerivationScopes::sort_derivation_functions()
{

}

void DerivationScopes::fast_forward_derivation_solver()
{

}