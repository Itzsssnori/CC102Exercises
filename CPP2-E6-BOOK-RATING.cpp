#include <iostream>
#include <string>
#include <iomanip>

struct book {
    std::string barcode{};
    std::string title{};
    int year{};
    int rating{};
};

int main()
{
    char choice{};
    do {
        std::cout << "\nInput number of books to rate: ";
        int num{};
        std::cin >> num;

        book books[num];

        bool isUnique{};
        for(size_t i = 0; i < num; ++i)
        {
            std::string code{};
            std::cout << "\n--- Book " << i + 1 << " ---\n";

            do {
                isUnique = false;
                std::cout << "Book's Barcode: ";
                std::getline(std::cin >> std::ws, code);
                for (size_t j = 0; j < i; ++j)
                {
                    if (books[j].barcode == code)
                    {
                        isUnique = true;
                        break;
                    }
                }
                if (isUnique)
                {
                    std::cout << "Entered barcode already exists. Please try another.\n";
                }
            } while(isUnique);
           books[i].barcode = code;

           std::cout << "Book's Title: ";
           std::getline(std::cin >> std::ws, books[i].title);

           std::cout << "Year Published: ";
           std::cin >> books[i].year;
        
           int rate{};
           do {
                std::cout << "Book's Rating(0-5): ";
                std::cin >> rate;

                if (rate < 0 || rate > 5) {
                    std::cout << "Invalid rating. Enter review rate 0-5.\n";
                }
           } while(rate < 0 || rate > 5);
           books[i].rating = rate;
        }

            std::cout << std::endl << std::string(85, '-') << std::endl;
            std::cout << std::left << std::setw(17) << "Barcode"
            << std::setw(40) << "Title" << std::setw(8) << "Year"
            << std::setw(8) << "Rating" << std::setw(12) << "Category" << std::endl;
            std::cout << std::string(85, '-') << std::endl;


        for(size_t i = 0; i < num; ++i)
        {
            std::string category{};
            switch(books[i].rating)
            {
                case 0: category = "No Rating."; 
                break;

                case 1: category = "Poor.";
                break;

                case 2: category = "Fair.";
                break;

                case 3: category = "Good.";
                break;

                case 4: category = "Very Good!";
                break;

                case 5: category = "Excellent!";
                break;
            }
            std::cout << std::left << std::setw(17) << books[i].barcode
            << std::setw(40) << books[i].title << std::setw(8) << books[i].year
            << std::setw(8) << books[i].rating << std::setw(12) << category << std::endl;
            }

            std::cout << std::string(85, '-') << std::endl;

        std::cout << "Do you want to repeat(y/n)? ";
        std::cin >> choice;
    } while(std::toupper(choice)=='Y');
    

    return 0;
}