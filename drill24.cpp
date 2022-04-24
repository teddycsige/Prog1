#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
{
	try
	{
		cout << "size of: " << endl;
		cout << "char \t" << sizeof(char) << endl;
		cout << "short \t" << sizeof(short) << endl;
		cout << "int \t" << sizeof(int) << endl;
		cout << "long \t" << sizeof(long) << endl;
		cout << "float \t" << sizeof(float) << endl;
		cout << "double \t" << sizeof(double) << endl;
		cout << "int* \t" << sizeof(int*) << endl;
		cout << "double* \t" << sizeof(double*) << endl;
		
		
		cout << "Matrix sizes: " << endl;
		Matrix<int> a(10);
		Matrix<int> b(100);
		Matrix<double> c(10);
		Matrix<int, 2> d(10,10);
		Matrix<int, 3> e(10,10,10);
		
		cout << "1D int, 10 elem \r\r" << sizeof(a) << endl;
		cout << "1D int, 100 elem\t\t" << sizeof(b) << endl;
		cout << "1D double, 10 elem \t\t" << sizeof(c) << endl;
		cout << "2D int, 10x10\t\t" << sizeof(d) << endl;
		cout << "3D int, 10x10x10\t\t"<<sizeof(e) << endl;
		
		cout << "Number of elements: " << endl;
		cout << "a:\t" << a.size() << endl;
		cout << "b:\t" << b.size() << endl;
		cout << "c:\t" << c.size() << endl;
		cout << "d:\t" << d.size() << endl;
		cout << "e:\t" << e.size() << endl;
		
		cout << endl;
		cout <<"Please give a value (for quit press a charachter)" << endl;
		int x;
		while(cin>>x)
		{
			double y = sqrt(x);
			if(x<=0)
			{
				cout << "no square root" << endl;
			}
			else
			{
				cout << "The result of the square:" << endl;
				cout << "sqrt: " << x << " = " << y << endl;
			}
		}
		
		/*while(cin>>x)  //órai
		{
			errno = 0;
			double d = sqrt(x);
			if(errno==EDOM)
			{
				cout << "no square root" << endl;
			}
			else
			{
				cout << "sqrt: " << x << " = " << d << endl;
			}
		}*/
		
		
		cin.clear(); //hibakódok törlése
		cin.ignore(); //hibakaraktereket kihagyja
		
		cout << "Enter 10 floats: " << endl; 
		Matrix<double> m2(10);
		double d2;
		for(int i=0; i <m2.size(); i++)
		{
			cin >> d2;
			if(!cin) throw runtime_error("Problem reading from cin");
			m2[i]=d2;
		}
		cout << endl;
		cout << "Matrix:\n" << m2 << endl;
		
		cout<<endl;
		cout << "Please enter 2 values:" << endl;
		int n;
		int m3;
		cin >> n;
		cin >> m3;
		
		Matrix<int,2> y(n, m3);
		
		for(Index i=0; i < y.dim1(); i++)
		{
			for(Index j = 0; j < y.dim2(); j++)
			{
				y(i,j) = (i+1)*(j+1);
				cout << setw(5) << y(i,j);
			}
		}
		
		Matrix<complex<double>>h(10);
		cout<<endl;
		cout << "Enter 10 complex numbers (Re, Im): " ;
		complex<double> comp;
		for(int i=0; i<10; i++)
		{
			cin >> comp;
			if(!cin) throw runtime_error("Problem");
			h[i]=comp;
		}
		complex <double> sum;
		for(Index i=0; i <h.size(); i++)
		{
			sum += h[i];
		}
		cout << "sum:" << sum << endl;
		
		int p;
		cout << endl;
		cout << "Please enter 6 values" << endl;
		
		Matrix<int,2>m4(2,3);
		
		for(Index i=0; i < m4.dim1(); i++)
		{
			for(Index j = 0; j < m4.dim2(); j++)
			{
				cin >> p;
				m4[i][j]=p;
			}
		}
		cout << "Matrix:\n" << m4 << endl;
		
	}
	catch(exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	catch(...)
	{
		cerr << "Exception" << endl;
	}
}
