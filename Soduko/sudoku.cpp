#include "sudoku.h"



Sudoku::Sudoku() {
    mini = true;
    nRows = 6;
    nCols = 6;


    data = new double* [nRows];
    for (int i = 0; i < nRows; ++i) {
        data[i] = new double[nCols];
    }
}

Sudoku::Sudoku(bool m) {
    mini = m;
    if (mini) {
	    nRows = 6;
	    nCols = 6;

    }
    else {
        nRows = 9;
        nCols = 9;
    }

    data = new double* [nRows];
    for (int i = 0; i < nRows; ++i) {
        data[i] = new double[nCols];
    }
}


void Sudoku::print() {
	for (int i = 0;i < nRows; i++)
		for (int j = 0;j < nCols;j++)
			std::cout << data[i][j] << ((j == nCols - 1) ? "\n" : "\t");


}

void Sudoku::set_data(int i, int j, int num) {
    data[i][j] = num;
}
void Sudoku::read_data(const std::string& filename) {
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // Allocate memory for the grid
    data = new double* [nRows];
    for (int i = 0; i < nRows; ++i)
        data[i] = new double[nCols];

    std::string token;
    int row = 0, col = 0;

    while (infile >> token) {
        if (token == "X") {
            data[row][col] = 0.0;
        }
        else {
            data[row][col] = std::atof(token.c_str()); //Used Chatgpt to get this result
        }

        col++;
        if (col == nCols) {
            col = 0;
            row++;
        }
    }

    infile.close();
}

bool Sudoku::is_valid(int i, int j, int num){
    //Check Row
    for (int a = 0; a < nCols; a++) {
        if (data[i][a] == num) {
            return false;
        }
    }

    //Check Column
    for (int b = 0; b < nRows; b++) {
        if (data[b][j] == num) {
            return false;
        }
    }

    // Check box
    int box_i, box_j, limit_i,limit_j;
    if (mini) {
        box_i = (i / 2)*2;
        box_j = (j / 3)*3;
        limit_i = 2 + box_i;
        limit_j = 3 + box_j;
    }
    else {
        box_i = (i / 3) * 3;
        box_j = (j / 3) * 3;
        limit_i = 3 + box_i;
        limit_j = 3 + box_j;
    }
    for (int x=box_i;x<limit_i; x++) {
        for (int y=box_j; y<limit_j; y++) {
            if (data[x][y] == num) {
                return false;
            }
        }
    }
    return true;    
}

bool Sudoku::solve() {
    int max_num;
    if (mini) {
        max_num = 7;
    }
    else {
        max_num = 10;
    }
    for (int i = 0; i < nRows; i++) {
        for (int j = 0;j < nCols;j++) {
            if (data[i][j] == 0) {
                for (int num = 1;num < max_num;num++) {
                    if (is_valid(i, j, num)) {
                        set_data(i,j,num);
                        if (solve()) {
                            return true;
                        }
                        set_data(i,j,0);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

//Got help from Co-pilot ( nullptr is something I didn't know)
Sudoku::~Sudoku() {
    if (data != nullptr) {
        for (int i = 0;i < nRows;i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}