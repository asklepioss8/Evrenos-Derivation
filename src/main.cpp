#include "validation_layers.hpp"


int main()
{
    std::string testStr = "(((((x^var1+2*x)*3)/4sin(x*(sin(var1))))-5))*6+{[7*x*ln(x)*8]/9}";
    ValidationLayers test(testStr);

    
    return 0;
}