#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <array>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename C>
void print(const C& c)
{
	for(auto& i :c)
	{
		std::cout << i <<' ';
	}
	std::cout << std::endl;
}

template<typename C>
void inc(C& c, int n)
{
	for(auto& i : c)
	{
		i+=n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p=f1; p!=e1; p++)
	{
		*f2++ =*p;
		//f2++;
	}

	return f2;
}

int main()
{
	try
	{
		constexpr int size = 10;
		int arr[size];
		for(int i =0; i < size; i++) arr[i] = i;
		
		std::array<int, size> ai;
		std::copy(arr, arr+size,ai.begin());
		 
		std::vector <int> vi(size);
		std::copy(arr, arr+size, vi.begin());
		
		std::list<int> li(size);
		std::copy(arr, arr+size, li.begin());
		
		std::array<int, size> ai2 = ai;
		std::vector<int> vi2 = vi;
		std::list<int> li2 = li;
		
		
	print(ai2);
	print(vi2);
	print(li2);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print(ai2);
	print(vi2);
	print(li2);
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(vi2);
	print(li2);
	
	std::vector<int>::iterator vit;  //iterator egy inteket tartalmazó vektor elemeire mutat
	vit = std::find(vi2.begin(), vi2.end(), 3);
	//std::distance
	if( vit != vi2.end())
	{
		std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
	
	auto lit = std::find(li2.begin(), li2.end(), 27);
	if( lit != li2.end())
	{
		std::cout << "Found at: " << std::distance(li2.begin(), lit) << std::endl;
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
		
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		std::cerr << "error\n";
		return 2;	
	}
}
