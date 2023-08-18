#pragma once

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <stdexcept>


char preparsing_keywords[] = {
	'(',
	')',
	'+',
	'-',
	'*',
	'/',
	'^',
	'{',
	'}'
};

int variable_list_length = 3;
char* variable_list = new(char[3]){
	'x',
	'y',
	'z'
};


// Null terminated array
int  numeric_list_length = 10;
char* numeric_list = new(char[]){
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9' 
};

int function_list_length = 20;
const char** function_list = new(const char*[20]){
	"sin\0",
	"cos\0",
	"tan\0",
	"cot\0",
	"csc\0",
	"sec\0",
	"asin\0",
	"acos\0",
	"atan\0",
	"acot\0",
	"acsc\0",
	"asec\0",
	"sqrt\0",
	"cbrt\0",
	"ln\0",
	"log\0",
	"!\0",
	"rad\0",
	"deg\0",
	"EXP\0",
};


int lparanthesis_check_list_length = 6;
char* lparanthesis_check_list = new(char[6]){
	'+',
	'-',
	'*',
	'/',
	'^',
	')'
};

