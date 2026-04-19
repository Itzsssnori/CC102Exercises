#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ofstream writeFile("color.txt");

    if (!writeFile.is_open())
    {
        std::cerr << "Error: Failed to create color.txt\n";
        return 1;
    }

    writeFile << "Blue\n";
    writeFile << "Red\n";
    writeFile << "Green\n";
    writeFile << "Purple\n";
    writeFile << "Yellow\n";

    writeFile.close();
    std::cout << "The file color.txt was written successfully.\n";

    std::ifstream readFile("color.txt");

    if (!readFile.is_open())
    {
        std::cerr << "Error: Failed to open color.txt for reading.\n";
        return 1;
    }

    std::ofstream copyFile("color_copy.txt");

    if (!copyFile.is_open())
    {
        std::cerr << "Error: Failed to create color_copy.txt\n";
        readFile.close();
        return 1;
    }

    std::string line{};

    while(std::getline(readFile, line))
    {
        copyFile << line << '\n';
    }

    copyFile.close();
    readFile.close();

    std::cout << "The file color_copy.txt was created successfully.\n";
    
    return 0;
}