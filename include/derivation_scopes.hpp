#pragma once
#include <string>
#include <vector>

#pragma pack(push, 1)
struct derivation_function
{
    std::string data;
    std::vector<std::string> tokenised_data;
    bool solved = false;
    std::string solution;
    int scope;
};
#pragma pack(pop)

class DerivationScopes
{
public:
    // Constructor / Destructor
        DerivationScopes(std::string inputStr);
        ~DerivationScopes();

        // Public member functions
        void run();
        const std::vector<derivation_function*>& get_derivation_functions() const { return derivation_functions; }

private:
    
    std::string inputStr {};
    std::vector<derivation_function*> derivation_functions {};

    // Private member variables
    void create_derivation_functions();
    void sort_derivation_functions();
    void fast_forward_derivation_solver();


};