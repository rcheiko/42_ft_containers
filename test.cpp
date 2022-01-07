#include <iostream>
#include <vector>

int main()
{
	std::vector<char> f;
/*	for (int i = 0; i < 20; i++)
	{
		f.push_back(i);
	}*/

	std::cout << f.at(5) << std::endl;
	//f.reserve(96);
	//std::cout << "CAPACITY : " << f.capacity() << std::endl;
//	for (int i = 0; i < f.size(); i++)
//	{
//		std::cout << f[i] << std::endl;
//	}
	return (0);
}
