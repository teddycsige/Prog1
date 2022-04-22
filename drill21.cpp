#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

template<typename K, typename V>
void print(const std::map<K,V>& m)
{
	 //for(auto& i : m)
	 for(std::pair<K,V> i : m)
	 {
	 	std::cout<< i.first << '\t' << i.second << std::endl;
	 }
}

void read_map(std::map<std::string, int>& m)
{
	std::string s;
	int i=0;
	while(m.size()<10)
	{
		std::cin >> s >> i;
		m[s]=i;				//ha szeretnénk hogy felülíródjon
		//m.insert(std::make_pair(s,i));	//ha nem
	}
}

int main()
{
	try
	{
		std::map<std::string, int > msi;
		msi["a"] = 2;
		msi["b"] = 3;
		msi["abc"] = 4;
		msi["cd"] = 5;
		msi["qwert"]= 2;
		msi["top"] = 32;
		msi["mid"] = 4;
		msi["bot"] = 91;
		msi["jg"] = 20;
		msi["adc"] = 84;
		
		print(msi);
		
		msi.erase("a");
		std::cout<<std::endl << "Egy elem törlése után" << std::endl;
		print(msi);
		
		msi.erase(msi.begin(), msi.end());
		std::cout<<std::endl<<"Teljes törlés után" << std::endl;
		print(msi);
		
		std::cout << "Adj meg 10 kulcsértékpárt" << std::endl;
		read_map(msi);
		print(msi);
		
		/*int t = std::accumulate(msi.begin(), msi.end(), 0, [](int sum, const std::pair<std::string, int>& p)
		{return sum+=p.second;}
		};*/
		
		int t2 = 0;
		for(std::pair<std::string, int> a : msi)
		{
			t2 += a.second;
		}
		std::cout<< "Sum of ints: " << t2 << std::endl;
		
		std::map<int, std::string> mis;
		for(std::pair<std::string, int> a : msi)
		{
			mis[a.second] = a.first;
		}
		std::cout<< "mis map: " << std::endl;
		print(mis);
		
		
	}
	catch(std::exception& e)
	{
		std::cerr << "Excpetion: " << e.what() << std::endl;
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown exception: " << std::endl;
		return 2;
	}
}
