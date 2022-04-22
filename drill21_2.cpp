#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

template<typename C>
void print(C& c, char sep= '\n')
{
	std::cout << "Container elements: " << std::endl;
	
	for(const auto elem: c)
	{
		std::cout << elem << sep;
	}
	std::cout << std::endl;
}

int main()
{
	try
	{	
		const std::string iname {"input.txt"};
		std::ifstream ifs{iname};
		if(!ifs) throw std::runtime_error("Cannot read file: "+ iname);
		
		std::vector<double> vd;
		for(double d; ifs >> d;)
		{
			vd.push_back(d);
		}
		print(vd);
		
		std::vector<int> vi;
		for(auto& i : vd)
		{
			vi.push_back(i);
		}
		//atd::copy(vd.begin(), vd.end(), vi.begin());
		print(vi);
		
		for(int i=0; i<vd.size(); i++)
		{
			std::cout << vd[i] << '\t' << vi[i] << std::endl;
		}
		
		std::cout.precision(10);  //látszódjanak a tizedespont után is a számok
		
		double sum = 0;
		for(int i=0; i<vd.size(); i++)
		{
			sum += vd[i];
		}
		std::cout << "Sum of the vd vector: " << sum << std::endl;
		
		double sum2 = 0;
		for(int i=0; i<vd.size(); i++)
		{
			sum2 += vi[i];
		}
		std::cout << "Sum of the vi vector: " << sum2 << std::endl;
		
		double diff = sum - sum2;
		std::cout << "The difference of the vectors: " << diff << std::endl;
		
		std::reverse(vd.begin(), vd.end());
		print(vd);
		
		double vd_mean = sum / vd.size();
		std::cout << "Mean value of vd is: " << vd_mean << std::endl;
		
		std::vector<double> vd2;			//debugolniiiii
		for(auto& i : vd)
		{
			if(i < vd_mean)
			{
				vd2.push_back(i);
			}
		}
		print(vd2);
		
		std::sort(vd.begin(), vd.end());
		print(vd);
		
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch(...)
	{
		std::cerr<<"Unknown exception!" << std::endl;
		return 2;
	}

}
