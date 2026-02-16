#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>

int main()
{
    char choice{};
    do {
    int students{}, quizzes{};
    std::cout << "Enter number of students: ";
    std::cin >> students;
    std::cout << "Enter number of quizzes per student: ";
    std::cin >> quizzes;
    
    std::vector<std::vector<double>> scores(students, std::vector<double>(quizzes));
    std::vector<double> average(students);

    for (int i = 0; i < students; i++)
    {
        double sum {0};
        std::cout << "\nInputting quiz scores for student no. " << i + 1 << ": " << std::endl;
        for (int j = 0; j < quizzes; j++)
        {
            std::cout << "Quiz " << j + 1 << " score: ";
            std::cin >> scores[i] [j];
            sum += scores [i] [j];
        }
        average[i] = sum / quizzes;
    }

    std::cout << "\nStudent\t";
    for (int j = 0; j < quizzes; j++)
    {
        std::cout << "Quiz "<< j + 1 << '\t';
    }
    std::cout << "Average\n";
    
    for (int i = 0; i < students; i++)
    {
        std::cout << i + 1 << '\t';
        for (int j = 0; j < quizzes; j++)
        {
            std::cout << scores[i][j] << '\t';
        }
        std::cout << std::fixed << std::setprecision(2) << average[i] << std::endl;
    }
    std::cout << "Do you want to repeat(y/n)? ";
    std::cin >> choice;
    } while(toupper(choice)=='Y');

    return 0;
}