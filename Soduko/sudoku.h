#ifndef sudoku_h
#define sudoku_h

#include <iostream>
#include <random>

#include <stdio.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>



class Sudoku {
private:
	int nRows;
	int nCols;
	bool mini;
	double** data;
	
public:
	// Constructors
	//Default Constructor
	Sudoku();
	//Parameter Constructor
	Sudoku(bool m);
	
	
	//Getter
	//Setter
	void set_data(int, int, int);
	//Auxiliary functions
	void print();
	void read_data(const std::string& filename);
	bool is_valid(int i, int j, int num);
	bool solve();
	//Destructor
    // Add missing destructor declaration to fix "expected a declaration" error
    ~Sudoku();
};
#endif 