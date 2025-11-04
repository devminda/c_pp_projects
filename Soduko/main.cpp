#include "sudoku.h"

int main()
{
    std::cout << "Mini Sudoku Solution" << std::endl;
    Sudoku m2; // false = standard 9x9
    m2.read_data("mini_sudoku.dat");
    std::cout << "Initial Puzzle:\n";
    m2.print();

    if (m2.solve()) {
        std::cout << "Solved Puzzle:" << std::endl;;
        m2.print();
    }
    else {
        std::cout << "No solution found." << std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Large Sudoku Solution" << std::endl;
    Sudoku m1(false); // false = standard 9x9
    m1.read_data("sudoku.dat");
    std::cout << "Initial Puzzle:\n";
    m1.print();

    if (m1.solve()) {
        std::cout << "Solved Puzzle:" << std::endl;;
        m1.print();
    }
    else {
        std::cout << "No solution found." << std::endl;
    }



    return 0;

}



