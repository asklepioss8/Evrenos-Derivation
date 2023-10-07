#include "validation_layers.hpp"


int main()
{
    std::string testStr = "(((((1+2)*3)/4)-5)*6+{[7*8]/9}";
    ValidationLayers test(testStr);
    
    return 0;
}