#include <iostream>
#include <string>


class ValidationLayers
{
public:

    // Constructor and destructor
    ValidationLayers(std::string inputStr);
    ~ValidationLayers();
        
    // Unmoveable and uncopyable
    ValidationLayers(const ValidationLayers&) = delete;
    ValidationLayers& operator=(const ValidationLayers&) = delete;
    ValidationLayers(ValidationLayers&&) = delete;
    ValidationLayers& operator=(ValidationLayers&&) = delete;

    // Public methods
    // -Run function
    void run();

    // -Getters
    // -Setters

private:
    std::string inputStr;

    // q: difference between "[" and "{" in english
    // a: "[" is called "bracket" and "{" is called "brace"



    // Validation Layers
    void remove_white_spaces();
    void validate_parentesis();
    void validate_brackets();
    void validate_braces();
    void validate_angle_brackets();



};

