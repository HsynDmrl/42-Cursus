/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <hdemirel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:45 by hdemirel          #+#    #+#             */
/*   Updated: 2024/10/09 13:02:46 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using std::string;

void replaceFile(const string &filename, const string &s1, const string &s2) 
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: " << filename << " could not be opened." << std::endl;
        return;
    }
    
    std::ofstream temp("temp.txt");

    if (!temp.is_open())
    {
        std::cerr << "Error: temp.txt could not be opened." << std::endl;
        return;
    }

    if(file.peek() == -1)
    {
        std::cerr << "Error: " << filename << " is empty." << std::endl;
        return;
    }
    
    string line;

    while (std::getline(file, line))
    {
        size_t pos = line.find(s1);
        while (pos != string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos = line.find(s1, pos + s2.length());
        }
        temp << line << std::endl;
    }

    file.close();
    temp.close();
    
    std::cout << "File " << filename << " has been replaced." << std::endl;
}

int main(void)
{
    string fileName, s1, s2;

    std::cout << "Enter the file name: ";
    std::getline(std::cin, fileName);
    if (std::cin.eof())
    {
        std::cerr << "Error: File name could not be read." << std::endl;
        return 1;
    }
    
    std::cout << "Enter the string to be replaced: ";
    std::getline(std::cin, s1);
    if (std::cin.eof())
    {
        std::cerr << "Error: String1 to be replaced could not be read." << std::endl;
        return 1;
    }
    
    std::cout << "Enter the string to replace: ";
    std::getline(std::cin, s2);
    if (std::cin.eof())
    {
        std::cerr << "Error: String2 to replace could not be read." << std::endl;
        return 1;
    }
    
    replaceFile(fileName, s1, s2);

    return 0;
}
