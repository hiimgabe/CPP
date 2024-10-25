/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:25:35 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 12:48:07 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	sandr(std::string filename, std::string& original, std::string& search, std::string& replace)
{
	int			i = 0;
	int			search_length = search.length();
	std::string	res = "";
	std::ofstream	sandr_file;
	std::string		replace_name = filename + ".replace";
	

	if (search.empty())
		res = original;
	else
	{
		while (i < original.length())
		{
			if (original.substr(i, search_length) == search)
			{
				res += replace;
				i += search_length;
			}
			else
			{
				res += original[i];
				i++;
			}
		}
	}
	sandr_file.open(replace_name.c_str());
	if (sandr_file.fail())
		throw std::runtime_error("Failed to create the outfile.");
	sandr_file << res;
	sandr_file.close();
}

std::string	read_content(std::string str)
{
	std::ifstream	file;
	std::string		buffer;
	std::string		content;

	file.open(str.c_str());
	if (file.fail()) 
		throw std::runtime_error("Couldn't open the file.");
	while (std::getline(file, buffer))
		content.append(buffer + '\n');
	file.close();
	return (content);
}

void	input_instructions()
{
	std::cout << "./sandr <filename> <s1> <s2>" << std::endl;
	throw std::invalid_argument("Invalid arguments.");
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 4)
			input_instructions();
		std::string file = read_content(argv[1]);
		std::string search = argv[2];
		std::string replace = argv[3];
		sandr(argv[1], file, search, replace);
		std::cout << ".replace file created successfully" << std::endl;
		return (EXIT_SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	
}