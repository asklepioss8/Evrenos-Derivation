#include "config.hpp"


// lets consider out input equation is following,
// f(x) = sqrt(tan(tan(tan(x^2))))+ln(x^2)*log{5}(x^2)-2*x

// THE VALIDATION LAYERS ARE
// 1- Space elimination
// 2- Parenthesis pair validate
// 3- Missing Multiplication placement 
// 4- Preparsing

char* space_elimination_validation_v1(char* str)
{
	// calculate the lenght of input array
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len++;

	// calculate the lenght of new array
	int new_lenght = len;
	int counter = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ' ')
		{
			new_lenght--;
		}
	}

	// create the new array with appropriate lenght
	char* new_array = new(char[new_lenght]);

	// fill the new array without spaces 
	// the new array is also zero terminating
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != ' ')
		{
			new_array[counter] = str[i];
			counter++;
		}
	}

	// delete the old array
	delete[] str;
	return new_array;
}

_NODISCARD void space_elimination_validation_v2(std::string& str)
{
	std::erase_if(str, [](char i) {return i == ' '; });
}


bool parenthesis_layer_validation_v1(char* str)
{
	int check = 0;
	int counter = 0;

	// validate each lparenthesis has pair 
	while (str[counter] != '\0')
	{
		if (str[counter] == '(')
		{
			check++;
		}
		else if (str[counter] == ')')
		{
			check--;
		}
		if (check < 0)
		{
			return false;
		}
		counter++;
	}

	if (check == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool parenthesis_layer_validation_v2(std::string &str)
{
	int check = 0;
	int len = static_cast<int>(str.length());

	for (int i = 0; i < len ; ++i)
	{
		if (str[i] == '(')
		{
			check++;
		}
		else if (str[i] == ')')
		{
			check--;
		}
		if (check < 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<char*> preparsing(char* str)
{

	// calculate the lenght of input array
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len++;

	// for appropriate parsing that not include any of preparsing kw
	// start previous from -1 and add 1 on calculating lenght
	std::vector<char*> fragments;
	int previous = -1;
	
	for (int i = 0; i < len - 1; ++i)
	{
		for (char j : preparsing_keywords)
		{
			if (str[i] == j)
			{
				int temp_length = i - previous;
				if (temp_length != 0)
				{
					char* temp_str = new(char[temp_length + 1]); // +1 for null termination
					for (int k = 0; k < temp_length + 1; ++k)
					{
						temp_str[k] = str[previous + k + 1];
					}
					temp_str[temp_length] = '\0';
					fragments.push_back(temp_str);
					// we cant delete temp_str (?);
				}
				previous = i;
				break;
			}
		}
	}

	// handle the last item
	int last_item_lenght = len - previous;
	char* last_item = new(char[last_item_lenght]);
	for (int i = 0; i < last_item_lenght; ++i)
	{
		last_item[i] = str[previous + i + 1];
	}
	fragments.push_back(last_item);

	return fragments;
}


/* MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS */
std::vector<std::pair<char*, int>> preparsing_extended(char* str)
{
	std::pair<char*, int> temp_pair;

	// calculate the lenght of input array
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len++;

	// for appropriate parsing that not include any of preparsing kw
	// start previous from -1 and add 1 on calculating lenght
	std::vector<std::pair<char*, int>> fragments;
	int previous = -1;
	/* MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS */

	for (int i = 0; i < len - 1; ++i)
	{
		for (char j : preparsing_keywords)
		{
			if (str[i] == j)
			{
				int temp_length = i - previous - 1;
				if (temp_length != 0)
				{
					char* temp_str = new(char[temp_length]);
					for (int k = 0; k < temp_length + 1; ++k)
					{
						temp_str[k] = str[previous + k + 1];
					}

					temp_pair.first = temp_str;
					temp_pair.second = temp_length + 1;
					fragments.push_back(temp_pair);
					// we cant delete temp_str (?);
				}
				previous = i;
				break;
			}
		}
	}
	/* MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS */

	// handle the last item
	int last_item_lenght = len - previous - 1 ;
	char* last_item = new(char[last_item_lenght]);
	for (int i = 0; i < last_item_lenght; ++i)
	{
		last_item[i] = str[previous + i + 1];
	}
	temp_pair.first = last_item;
	temp_pair.second = last_item_lenght;
	fragments.push_back(temp_pair);

	return fragments;
}

bool is_numeric_helper(char c)
{
	for (int i = 0; i < numeric_list_length; ++i)
	{
		if (c == numeric_list[i])
		{
			return true;
		}
	}
	return false;
}

bool has_numeric_helper(char* str, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < numeric_list_length; ++j)
		{
			if (str[len] == numeric_list[j])
			{
				return true;
			}
		}
		len++;
	}
	return false;
}

bool last_character_flag_hh(char c)
{
	for (int i = 0; i < lparanthesis_check_list_length; ++i)
	{
		if (c == lparanthesis_check_list[i])
		{
			return false;
		}
	}
	return true;
}

bool check_has_rparenthesis_hh(char* str, int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '(')
		{
			return true;
		}
	}
	return false;
}


// eðer listede varsa yerleþitirmesin
bool check_rparenthesis_substr_hh(char* str)
{
	int counter = 0;
	for (int i = 0; i < function_list_length; ++i)
	{
		while (str[counter] != '\0' && function_list[i][counter] != '\0')
		{
			if (str[counter] != function_list[i][counter])
			{
				return true;
			}

			// MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS 
			// MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS 
			// MALICIOUS MALICIOUS MALICIOUS MALICIOUS MALICIOUS 
			if (str[counter] == '\0' && function_list[i][counter] == '\0')
			{
				return false;
			}
			counter++;
		}
	}
}

int determine_cutpoints_helper(char* str, char before, int current_pos, int len)
{
	// Eðer left parantezin arkasýna bir operatör gelmez ise
	if (before == ')' && last_character_flag_hh(str[0]))
	{
		//return current_pos;
	}

	// Eðer right parantezin öncesinde bir operatör yok ise
	if (check_has_rparenthesis_hh(str, len))
	{
		bool check = check_rparenthesis_substr_hh(str);
		std::cout << check ;
	}

	// Eðer bir sayý deðiþken veya fonksiyondan ikisi yanyana ise
	// 
	return NULL;
}

// Needs null terminating string
// DEPENDS ON preparsing
// THE ALGORITHM IS lets consider zeros are represents non numeric entities _0__0__00
// we have to place nultiplication like _*0*__*0*__*0*0
// OR PREPARSING_EXTENDED_EXTENDED
void missing_multiplication_placement_validate(char* str)
{
	std::vector<char*> fragments = preparsing(str);
	bool has_numeric;
	int* cutpoints = nullptr;
	int element_length;
	char before = '\0';
	int current_pos = 0;

	for (char* i : fragments)
	{
		std::cout << i;
		// ELEMENT LENGTH
		element_length = 0;
		while (i[element_length] != '\0')
		{
			element_length++;
		}

		// HAS_NUMERIC_ELEMENT
		has_numeric = has_numeric_helper(i, element_length);

		if (has_numeric)
		{
			std::cout << '\t' << determine_cutpoints_helper(i, before, current_pos, element_length) << '\n';
		}


		before = i[element_length - 1];
		current_pos += element_length;
	}
	std::cout << "done" << '\n';
}

// STRONGLY DEPENDS ON missing_multiplication_placement_validate
void check_all_kw_are_valid(std::vector<char*>& vec)
{
	for (char* i : vec)
	{
		std::cout << i << '\n';
		// TODO CHECK NUMBERS
		for (int j = 0; j < numeric_list_length; ++j)
		{
			if (*i == numeric_list[j])
			{
				std::cout << "NUMERIC!" << i << '\n';

			}
		}


		// TODO CHECK VARIABLES
		

		// TODO CHECK FUNCTIONS

	}

}



