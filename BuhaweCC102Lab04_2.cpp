#include <iostream>
#include <iomanip>
#include <cctype>

int main()
{
    char choice{};
    do {
        double sales[5][4] = {0};
        int salesperson{}, product{};
        char insert{};
        double amount{};
    do {
        std::cout << "\nSalesperson (1-4): ";
        std::cin >> salesperson;

        std::cout << "Product (1-5): ";
        std::cin >> product;

        std::cout << "Dollar amount sold: ";
        std::cin >> amount;

            sales[product-1][salesperson-1] += amount;

        std::cout << "Add another entry(y/n)? ";
        std::cin >> insert;
    } while (toupper(insert)=='Y');
         
        std::cout << "\n\t\tSalesperson\n";
        std::cout << "Product\t";

        for (int s = 0; s < 4; s++) {
            std::cout << s + 1 << "\t";
        }
        std::cout << "Total\n";

        double grandTotal {0};

        for (int i = 0; i < 5; i++) {
            double rowTotal {0};
            std::cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                std::cout << std::fixed << std::setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }
            std::cout << rowTotal << std::endl;
                grandTotal += rowTotal;
        }

        std::cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double colTotal {0};
            for (int i = 0; i < 5; i++) {
                colTotal += sales[i][j];
            }
            std::cout << colTotal << "\t";
        }

        std::cout << grandTotal << std::endl;

        std::cout << "\nDo you want to repeat(y/n)? ";
        std::cin >> choice;

    } while(toupper(choice)=='Y');
    return 0;
}