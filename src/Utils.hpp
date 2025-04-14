#pragma once


#include <iostream>

using namespace std;



// ImportVectors reads the input vectors from file for dot product
// filePath: path name of the input file
// n: resulting size of the vectors
// v1: resulting vector1
// v2: resulting vector2
// return the result of the reading, true is success, false is error
bool ImportVectors(const string& inputFilePath,
                   unsigned int& n,
				   double& S,
                   double*& w,
                   double*& r);

// DotProduct performs the dot product between two vectors
// n: size of the vectors
// v1: the first vector
// v2: the second vector
// return the resulting dot product
double DotProduct(const unsigned int& n,
                        const double* const& w,
                        const double* const& r);

// ExportResult export the result obtained in file
// outputFilePath: path name of the output file
// v1: vector1
// v2: vector2
// dotProduct: the dot product
// return the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
                  const unsigned int& n,
				  double& S,
                  const double* const& w,
                  const double* const& r,
                  double& dotProduct);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const unsigned int& n,
                     const double* const& v);

