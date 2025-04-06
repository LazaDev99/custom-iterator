#pragma once

#include <iostream>
#include <vector>
#include <chrono>

template<typename T, typename Derived, int Direction>
class IteratorBase 
{
protected:
	
	T* itPtr;

public:

	IteratorBase(T* ptr) : itPtr(ptr) {}

	T& operator* () const { return *itPtr; }

	Derived& operator++() 
	{
		itPtr += Direction;
		return static_cast<Derived&>(*this);
	}

	bool operator!=(const Derived& otherDerived) const {return itPtr != otherDerived.itPtr; }
};

template<typename T>
class Iterator : public IteratorBase<T, Iterator<T>, 1> 
{
	using IteratorBase<T, Iterator, 1>::IteratorBase;
};

template<typename T>
class ReverseIterator : public IteratorBase<T, ReverseIterator<T>, -1> 
{
	using IteratorBase<T, ReverseIterator, -1>::IteratorBase;
};

template<typename T>
class MyContainer 
{
public:

	std::vector<T> m_array;

	MyContainer() = default;

	MyContainer(std::initializer_list<T> listOfValues) 
	{
		for (const auto& val : listOfValues) 
		{
			m_array.emplace_back(val);
		}
	}

	void add(const T& val) { m_array.emplace_back(val); }

	using Iterator = Iterator<T>;
	using ReverseIterator = ReverseIterator<T>;

	Iterator begin() { return Iterator(m_array.data()); }
	Iterator end() { return Iterator(m_array.data() + m_array.size()); }

	ReverseIterator rbegin() { return ReverseIterator(m_array.data() + m_array.size() - 1); }
	ReverseIterator rend() { return ReverseIterator(m_array.data() - 1); }
};

template<typename Container>
void testIteratorPerformance(Container& container)
{
	auto start = std::chrono::high_resolution_clock::now();
	for (auto it = container.begin(); it != container.end(); ++it) 
	{
		(void)*it;
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Custom-made Iterator need: " << duration.count() << " milliseconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	for (auto it = container.m_array.begin(); it != container.m_array.end(); ++it) 
	{
		(void)*it;
	}
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "STL iterator need: " << duration.count() << " milliseconds." << std::endl;
}
