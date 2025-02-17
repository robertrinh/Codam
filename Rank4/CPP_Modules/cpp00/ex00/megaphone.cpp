/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/10 14:35:06 by robertrinh    #+#    #+#                 */
/*   Updated: 2025/02/10 16:31:49 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //input output stream
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (size_t j = 0; j < arg.length(); j++)
				arg[j] = toupper(arg[j]);
			std::cout << arg << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}

//! syntax uitleg
//* << insertion operator, used to send data to std::cout. f.e. std::cout << "hi"
// used to format the data according to its data type and then send it to the cout object

//* :: scope resolution operator, to access members of a namespace
// telling the compiler to use the cout of the std namespace -> std::cout
// std is through <iostream>

//* namespace
// allows you to group related code together to avoid naming conflicts
// you can define a namespace and then not write it down
// under the headers: using namespace std;
// now you can do cout << "hi"; without std::
