#include "validation_layers.hpp"

#include <algorithm>
#include <cctype>

// \generate constructor and destructor
ValidationLayers::ValidationLayers(std::string inputStr) : inputStr(inputStr)
{
    std::cout << "ValidationLayers constructor called" << std::endl;
    run();
}

ValidationLayers::~ValidationLayers()
{
    std::cout << "ValidationLayers destructor called" << std::endl;
}



void ValidationLayers::run()
{
    try
    {
        remove_white_spaces();
        validate_parentesis();
        validate_brackets();
        validate_braces();
        validate_angle_brackets();
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ValidationLayers::remove_white_spaces()
{
    inputStr.erase(std::remove_if(inputStr.begin(), inputStr.end(), [](unsigned char c) { return std::isspace(c); }), inputStr.end());
}

void ValidationLayers::validate_parentesis()
{
    int count = 0;
    for (auto& c : inputStr)
    {
        if (c == '(')
            count++;
        else if (c == ')')
            count--;
    }
    if (count != 0)
        throw std::runtime_error("Parentesis are not balanced");
}

void ValidationLayers::validate_brackets()
{
    int count = 0;
    for (auto& c : inputStr)
    {
        if (c == '[')
            count++;
        else if (c == ']')
            count--;
    }
    if (count != 0)
        throw std::runtime_error("Brackets are not balanced");
}

void ValidationLayers::validate_braces()
{
    int count = 0;
    for (auto& c : inputStr)
    {
        if (c == '{')
            count++;
        else if (c == '}')
            count--;
    }
    if (count != 0)
        throw std::runtime_error("Braces are not balanced");
}

void ValidationLayers::validate_angle_brackets()
{
    int count = 0;
    for (auto& c : inputStr)
    {
        if (c == '<')
            count++;
        else if (c == '>')
            count--;
    }
    if (count != 0)
        throw std::runtime_error("Angle brackets are not balanced");
}

