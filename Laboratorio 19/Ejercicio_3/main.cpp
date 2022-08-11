#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 gen(seed);
std::uniform_int_distribution<int>dis(1,100);

class Elemento{
public:
	Elemento()
	{
		this->a = dis(gen);
		this->b = dis(gen);
	}
	int a;
	int b;
};


class Sort{
public:
	bool operator()(Elemento obj1, Elemento obj2){
		return (obj1.a) < (obj2.b);
	}
};

void mostrar(vector<Elemento> lista){
	for(auto i = lista.begin(); i<lista.end(); i++){
		std::cout << '(' << i->a << ", " << i->b << ") ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<Elemento> vec;
	for(auto i{0}; i < 20; i++){
		Elemento x;
		vec.push_back(x);
	}
	std::cout << "Vector Inicial\n";
	mostrar(vec);
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end(), Sort());
	std::cout << "Vector Ordenado\n";
	mostrar(vec);
	return 0;
}
