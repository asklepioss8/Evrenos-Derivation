#include "validation_layer.hpp"

// ilk a�amada daha uzun bir soru olamayaca��n� varsayarak 1000 karakterlik
// bir allokasyonla inputumuzu haz�rl�yoruz.
// Bu allokasyon b�t�n elemanlar� null terminating characterlerden olu�an 
// bir allokasyondur. 
// Program�n �al��abilmesi herhangi bir array tipinde (string, dynamic, c 
// style etc.) olarak al�nan inputun dynamic array tipine �evrilip sadece
// son karakteri null terminating character haline getirilmesiyle ba�lar

void print_dynamic_array(char* arr)
{
	int counter = 0;
	while (arr[counter] != '\0')
	{
		std::cout << arr[counter];

		counter++;
	}
	std::cout << std::endl;
}

void print_dynamic_array_and_check_zero_terminating(char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len++;

	for (int i = 0; i < len; ++i)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;

	if (str[len - 1] == '\0')
	{
		std::cout << "Zero-terminating" << std::endl;
	}
	else
	{
		std::cout << "Is not zero-terminating" << std::endl;
	}
}


int main()
{
	// THE INPUT THAT NULL TERMINATES
	char* input_array = new(char[]){ "sqrt( tan( tan(tan(x^2))2x(3y))) + ln(x^2x) (2 + log{5}(x^2) )- 2*x\0" };
	char* new_array;

	//print_dynamic_array_and_check_zero_terminating(input_array);
	new_array = space_elimination_validation_v1(input_array);
	//print_dynamic_array_and_check_zero_terminating(new_array);
	std::cout << new_array << '\n';
	//std::cout << parenthesis_layer_validation_v1(new_array) << std::endl;

	missing_multiplication_placement_validate(new_array);


	return 0;
}














