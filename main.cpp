/*
    Gabriel Lazar - 9/8/26
    Grade analysis program
*/

#include <iostream>
#include <vector>

int displayMenu();
void runMenu();
void addGrade();
void displayGrades();
void getAverageGrade();
void getHighestLowest();
void gradesAboveThreshold();

std::vector<double> grades;

int main() {
    runMenu();
    return 0;
}

int displayMenu() {
    int choice;

    std::cout << "Menu:\n---------------------\n"
                 "1. Add a grade\n"
                 "2. Display all grades\n"
                 "3. Calculate average grade\n"
                 "4. Find highest and lowest grade\n"
                 "5. Count grades above threshold\n"
                 "0. Quit\n\n"
                 "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

void runMenu() {
    int choice;
    do {
        choice = displayMenu();


        switch (choice) {
            case 1:
                addGrade();
                break;
            case 2:
                displayGrades();
                break;
            case 3:
                getAverageGrade();
                break;
            case 4:
                getHighestLowest();
                break;
            case 5:
                gradesAboveThreshold();
                break;
            case 0:
                std::cout << "bu-bye!" << std::endl;
                break;
            default:
                std::cout << "What.????" << std::endl;
                break;
        }
    } while (choice != 0);
}

void addGrade() {
    double grade;

    std::cout << "Enter grade in numerical form (IE: 44, 63.4 100.5)\n";
    std::cin >> grade;

    grades.push_back(grade);
}

void displayGrades() {
    if (grades.empty()) {
        std::cout << "There are no grades." << std::endl;
        return;
    }

    std::cout << "Displaying grades...\n";

    for (int i = 0; i < grades.size(); i++) {
        std::cout << "- " << grades[i] << std::endl;
    }
}

void getAverageGrade() {
    if (grades.empty()) {
        std::cout << "There are no grades." << std::endl;
        return;
    }

    double sum = 0.0;

    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }

    double average = sum / grades.size();

    std::cout << "Average grade: " << average << std::endl;
}

void getHighestLowest() {
    if (grades.empty()) {
        std::cout << "There are no grades." << std::endl;
        return;
    }

    double highest = grades[0], lowest = grades[0];
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }

        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }

    std::cout << "Highest grade: " << highest << std::endl;
    std::cout << "Lowest grade: " << lowest << std::endl;
}

void gradesAboveThreshold() {
    if (grades.empty()) {
        std::cout << "There are no grades." << std::endl;
        return;
    }

    double threshold;
    std::cout << "Enter threshold: ";
    std::cin >> threshold;

    std::cout << "Getting grades above " << threshold << "..." << std::endl;

    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > threshold) {
            std::cout << grades[i] << std::endl;
        }
    }
}