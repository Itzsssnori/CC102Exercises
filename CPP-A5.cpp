#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ofstream writeFile("original.txt");
    
    if (!writeFile.is_open())
    {
        std::cerr << "Error: Failed to create original.txt\n";
        return 1;
    }
    
    writeFile << "One\n";
    writeFile << "Two\n";
    writeFile << "Three\n";
    writeFile << "Four\n";
    writeFile << "Five\n";
    writeFile << "Six\n";

    writeFile.close();
    
    std::cout << "File original.txt was created successfully.\n";

    std::ifstream readFile("original.txt");

    if (!readFile.is_open())
    {
        std::cerr << "Error: Failed to open original.txt\n";
        return 1;
    }

    std::vector<std::string> words{};
    std::string line{};

    while(std::getline(readFile, line))
    {
        words.push_back(line);
    }

    readFile.close();

    std::sort(words.begin(), words.end());

    std::ofstream sortedFile("sorted.txt");

    if (!sortedFile.is_open())
    {
        std::cerr << "Error: Failed to create sorted.txt\n";
        return 1;
    }

    for (const std::string& word : words)
    {
        sortedFile << word << '\n';
    }

    sortedFile.close();

    std::cout << "File sorted.txt was created successfully.\n";

    return 0;
}