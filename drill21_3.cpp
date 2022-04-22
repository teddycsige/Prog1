#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

struct Item
{
	string name;
	int iid;
	double value;

};

void print(const vector<Item>& v)
{
	for(const auto& i : v)
	{
		cout << i.name << ' ' << i.iid << ' ' << i.value << endl;
	}
}

void printl(const list<Item>& l)
{
	for(const auto& i : l)
	{
		cout << i.name << ' ' << i.iid << ' ' << i.value << endl;
	}
}

struct byname
{
	bool operator()(const Item& a, const Item& b) const
	{
		return a.name < b.name;
	}
};

struct byid
{
	bool operator()(const Item& a, const Item& b) const
	{
		return a.iid < b.iid;
	}
};

struct byval
{
	bool operator()(const Item& a, const Item& b) const
	{
		return a.value > b.value;
	}
};


int main()
{
	try
	{
		vector<Item> vi(10);
		const string iname {"fajl1.txt"};
		ifstream ifs{iname};
		if(!ifs) throw runtime_error("Cannot read file: "+ iname);
		
		for(auto& i : vi)
		{
			ifs >> i.name >> i.iid >> i.value;
		}
		ifs.close();
		print(vi);
		
		list<Item>li(vi.size());
		copy(vi.begin(), vi.end(), li.begin());
		
		cout << endl;
		cout << "By name: " << endl;
		sort(vi.begin(), vi.end(), byname());
		print(vi);
		
		cout << endl;
		cout << "By name(list) " << endl;
		li.sort([](const Item& a, const Item& b) {return a.name < b.name;});
		printl(li);
		
		cout << endl;
		cout << "By id: " << endl;
		sort(vi.begin(), vi.end(), byid());
		print(vi);
		
		cout << endl;
		cout << "By id(list): " << endl;
		li.sort([](const Item& a, const Item& b) {return a.iid < b.iid;});
		printl(li);
		
		cout << endl;
		cout << "By value: " << endl;
		sort(vi.begin(), vi.end(), byval());
		print(vi);
		
		cout << endl;
		cout << "By value(list): " << endl;
		li.sort([](const Item& a, const Item& b) {return a.value < b.value;});
		printl(li);
		
		cout<<endl;
		cout<<"After insert: " << endl;
		vi.push_back(Item{"horse shoe", 99, 12.34});
		vi.push_back(Item{"Canon s400", 9988, 499.95});
		print(vi);
		
		cout << endl;
		cout<<"After insert(list): " << endl;
		li.push_back(Item{"horse shoe", 99, 12.34});
		li.push_back(Item{"Canon s400", 9988, 499.95});
		printl(li);
		
		cout << endl;
		cout << "After erase 2 name: " << endl;
		vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "mustar";}));
		vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "kaposzta";}));
		print(vi);
		
		cout << endl;
		cout << "After erase 2 name(list): " << endl;
		li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name == "mustar";}));
		li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name == "kaposzta";}));
		printl(li);
		
		cout << endl;
		cout << "After erase 2 id: " << endl;
		vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 3;}));
		vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 7;}));
		print(vi);
		
		cout << endl;
		cout << "After erase 2 id(list): " << endl;
		li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid == 3;}));
		li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid == 7;}));
		printl(li);
		
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
