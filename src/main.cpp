// if theere is a charavter between "$" and "{" it is a special token
// the expression between "$d{" and "}" get derived respect to the variable between "@{" and "}"
// the expression between "$i{" and "}" get integrated respect to the variable between "@{" and "}"

// if there is a character between "@" and "{" it is a special token
// if the expression is "$i{" and there is a token 'i between "@" and "{" then the expression is a indefinite integral
// if the expression is "$i{" and there is a token 'd' between "@" and "{" then the expression is a definite integral 


#include "validation_layers.hpp"
#include "derivation_scopes.hpp"

int main()
{


    
    std::string testStr = "$d{(((((x^var1+2*x)*3)/4sin(x*($d{sin(var1)}@n{y})))-5))*6+{[7*x*ln(x)*8]/9}}@n{x}";
    ValidationLayers testValidation(testStr);

    for (auto& i : testValidation.get_inputStr())
    {
        std::cout << i;
    }

    DerivationScopes testDerivation(testStr);

    for (const auto& i : testDerivation.get_derivation_functions())
    {
        std::cout << *(*i).data() << std::endl;
    }


    return 0;
}