#include <iostream>
#include <iomanip>

void analyzeGrade(int* grades, int students, int subjects);

int main() {
    int students{};
    std::cout << "Enter number of students: ";
    std::cin >> students;

    int subjects{};
    std::cout << "Enter number of subjects: ";
    std::cin >> subjects;

    int grades[students][subjects];

    for (size_t i = 0; i < students; ++i)
    {
        std::cout << "\nEnter subject/s for Student " << i+1 << ": \n";
        for (size_t j = 0; j < subjects; ++j)
        {
            std::cout << "Subject " << j+1 <<": ";
            std::cin >> grades[i][j];
        }
        
    }
    
    analyzeGrade(&grades[0][0], students, subjects);

    return 0;
}

void analyzeGrade(int* grades, int students, int subjects) {
    std::cout << "\n======= GRADE MATRIX =======\n";
    std::cout << "Student\t\t";
        for (size_t j = 0; j < subjects; ++j)
        {
            std::cout << "Subject " << j + 1 << '\t';
        }
    std::cout << "Average\n";

    int highest{0}, highestCount{0};
    int highestStudent[students * subjects];
    int highestSubject[students * subjects];
    
    for (size_t i = 0; i < students; ++i)
    {
        double sum{0};
        std::cout << "Student " << i+1 << '\t';
        for (size_t j = 0; j < subjects; ++j)
        {
            int studentGrade = *(grades + i * subjects + j);
            std::cout << '\t' << studentGrade << '\t';
            sum += studentGrade;

            if (studentGrade > highest)
            {
                highest = studentGrade;
                highestStudent[0] = i+1;
                highestSubject[0] = j+1;
                highestCount = 1;
            }
            else if (studentGrade == highest)
            {
                highestStudent[highestCount] = i+1;
                highestSubject[highestCount] = j+1;
                highestCount++;
            }
        }
        double average = sum/subjects;
        std::cout << "\t" << std::fixed << std::setprecision(2) << average << std::endl;
    }
    std::cout << "\n====== DISPLAY HIGHEST GRADE ========\n";
     for (size_t i = 0; i < highestCount; ++i) {
         std::cout << "Student " << highestStudent[i] << ", Subject " << highestSubject[i] << " Grade: " << highest << '\n';
     }             
} 