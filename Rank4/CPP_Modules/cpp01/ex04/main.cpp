/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/21 13:28:44 by qtrinh        #+#    #+#                 */
/*   Updated: 2025/02/21 15:14:19 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string overtake(std::string line, std::string str1, std::string str2)
{
	if (str1.empty())
		return line;
	size_t pos = 0;
	while((pos = line.find(str1, pos)) != std::string::npos)
	{
		line.erase(pos, str1.length());
		line.insert(pos, str2);
		pos += str2.length();
	}
	return line;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "give the right amount of args!" << std::endl;
		std::cerr << "example: ./program_name <filename> str1 str2" << std::endl;
		return 1;
	}

	//* infile
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error: can't open: " << argv[1] << std::endl;
		return 2;	
	}
	
	//* outfile
	std::string new_file = argv[1];
	new_file.append(".replace");
	std::ofstream outputFile(new_file.c_str()); // c_str converts to const char* -> std::ofstream constructor expects this
	if (!outputFile)
	{
		std::cerr << "Error: can't open: " << new_file << std::endl;
		return 2;
	}
	
	//* read every line in the test file to search the occurance
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		line = overtake(line, argv[2], argv[3]);
		outputFile << line << std::endl;
	}
	
	inputFile.close();
	outputFile.close();
	return 0;
}
