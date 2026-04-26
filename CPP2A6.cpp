#include <iostream>
#include <fstream>
#include <string>

bool isPrimeNumber (int n)
{
    if (n < 2) 
        return false;
    
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;
    
    for (int i = 3; i * i <= n; i+=2)
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}

int countPrimeNumInFile (const std::string& fileName)
{
    std::ifstream file(fileName);

    if (!file)
    {
        std::cerr << "Error: File " << fileName << " could not be open.\n";
        return -1;
    }

    int count{};
    int num{};

    while(file >> num)
    {
        if (isPrimeNumber(num))
            count++;
    }

    return count;
}

int main()
{
    int result = countPrimeNumInFile("NUMS.TXT");
    if (result >= 0)
        std::cout << "The number of prime numbers in the file is: " << result << std::endl;

    return 0;
}