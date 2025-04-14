#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include "src/Utils.hpp"





int main()
{
	
	
	string inputFileName = "./data.txt";
	
	
    unsigned int n;
    double* w = nullptr;
    double* r = nullptr;
	double S;

    if (!ImportVectors(inputFileName, n,S, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful: "<< " w= "<< ArrayToString(n, w)<< " r= "<< ArrayToString(n, r)<< endl;

    double dotProduct = DotProduct(n, w, r);
	

    string outputFileName = "./result.txt";
	
    if (!ExportResult(outputFileName, n,S, w, r, dotProduct))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    
    return 0;
}

