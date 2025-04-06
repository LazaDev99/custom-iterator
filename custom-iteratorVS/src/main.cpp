#include "../Include/Iterator.hpp"

int main() 
{
	const int numElements = 1000000;
	
	MyContainer<int> nums;
	for (int i = 0; i < numElements; ++i) 
	{
		nums.add(i);
	}

	MyContainer<int> numbers{ 2,3,4,5,6 };

	for (MyContainer<int>::Iterator it = numbers.begin(); it != numbers.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (MyContainer<int>::ReverseIterator it = numbers.rbegin(); it != numbers.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	testIteratorPerformance(nums);

	return 0;
}
