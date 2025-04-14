#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip> 

using namespace std;


bool ImportVectors(const string& inputFilePath,
                   unsigned int& n,
				   double& S,
                    double*& w,
                    double*& r)
{
    // Open File
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	
	// GET S by reading the first line of the file, watching out for the semicomma, which is not the predefined delimiter//
	string name_1;
	string separator_1;
	string line_1;
	getline(file, line_1);
	istringstream convertS(line_1); 
	getline(convertS, name_1, ';');  
	convertS >> S;
	cout<<"S= "<<S<<"	";
	
	// Get n by reading the second line of the file using the same percautions//
	
	string name_2;
	string separator_2;
	string line_2;
	getline(file, line_2);
	istringstream convertN(line_2); 
	getline(convertN, name_2, ';');  
	convertN >> n;
	cout<<"n= "<<n<<endl;
	
	string line_3;
	getline(file, line_3);

    // Get w and r using a different way to deal with the semicomma since we need both the value befor and the value after the delimiter;
	w = new  double[n];
	r = new double[n];
	string separation;
	string line;
	unsigned int index=0;
	
     for (unsigned int i = 0; i < n; ++i)
    {
        std::string line;
        std::getline(file, line);
        std::istringstream convertwr(line);
		char separator; 
		convertwr >> w[i]; 
		convertwr >> separator;  
		convertwr >> r[i];  
    
	
    }

    // Close File
    file.close();

    return true;
}

//performing the dot prodoct between vectors//
double DotProduct(const unsigned int& n,
						
                        const  double* const& w,
                        const double* const& r)
{
    double dotProduct = 0.0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += w[i] * r[i];

    return dotProduct;
}

// printing the results on the output file and on the prompt, including the two vectors and constants//
bool ExportResult(const string& outputFilePath,
                  const unsigned int& n,
				  double& S,
                  const  double* const& w,
                  const  double* const& r,
                  double& dotProduct
				  )
{
    // Open  output File
    ofstream file;
    file.open(outputFilePath);
	

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S= "<<S<<" , "<< "n= "<<n<< endl;
    

    file << "# w"<< endl;
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << w[i];
	file << endl;

    file << "# r "<< endl;
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "") << r[i];
    file << endl;
	
	file << std::fixed << std::setprecision(4);
    file << "# Rate of return of the portfolio:"<< dotProduct<< endl;
	std::cout << std::fixed << std::setprecision(4); 
	cout<< "rate of return: "<< dotProduct << endl;
	
	double V = 0;
    for (unsigned int i = 0; i < n; i++)
        V += (r[i]+1) * (w[i]*S);
	
	file << std::fixed << std::setprecision(2);
	file << "# V:"<< V<< endl;
	std::cout << std::fixed << std::setprecision(2); 
	cout<< "V: "<< V<< endl;
    
	
	

    // Close File
    file.close();

    return true;
}

//converting string to array using the standard mathematical notation//
string ArrayToString(const unsigned int& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
