#pragma once
#include <array>

std::array<char, 8> charOperators = {'+', '-', '*', '/', '%', '^', '&', '|'};
std::array<std::string, 1> stringOperators = {""};
std::array<std::string, 3> predefinedVariables = {"x", "y", "var1"};
std::array<char, 10> numerics = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
std::array<char, 8> charSeperators = {'(', ')', '[', ']', '{', '}', '<', '>'};

// special tokens between $ and {}
const int dollar_tokens_size = 2;
std::array<char, 2> dollar_tokens = {
    'd',
    'i'
};

// special tokens between @ and {}
const int at_tokens_size = 3;
std::array<char, 3> at_tokens = {
    'n',
    'd',
    'i'
};

/* We might define funciton in a struct to represent its argument count behaviour and other kind of things but this is just a think*/

#include <array>
#include <string>

const std::array<std::string, 34> PredefinedFunctions = {
    "log",
    "sin",
    "cos",
    "tan",
    "cot",
    "sec",
    "csc",
    "asin",
    "acos",
    "atan",
    "acot",
    "asec",
    "acsc",
    "ln",
    "exp",
    "sqrt",
    "cbrt",
    "abs",
    "ceil",
    "floor",
    "round",
    "trunc",
    "min",
    "max",
    "pow",
    "atan2",
    "hypot",
    "fmod",
    "remainder",
    "fdim",
    "fmax",
    "fmin"
};