#pragma once
#include "PrintEdition.h"
#include "Magazine.h"
#include "Book.h"
#include <vector>
#include <list>
#include <functional>

using PEPtr = std::unique_ptr<PrintEdition>;

class Library
{
private:
	std::string libName;
	std::list<PEPtr> list_of_PE;

public:
	Library();
	Library(std::string name);
	~Library();

	std::string get_name() const;
	void set_name(std::string n);

	void insert(PEPtr ptr);
	void remove(std::function<bool(const PEPtr&)> _Pred);
	void sort();

	//std::string toString();
	void print();
};

Library::Library() : libName("") {}

Library::Library(std::string name) : libName(name) {}

Library::~Library()
{
	libName.clear();
}

std::string Library::get_name() const
{
	return libName;
}

void Library::set_name(std::string n)
{
	libName = n;
}

void Library::insert(PEPtr ptr)
{
	std::list<PEPtr>::iterator beg = list_of_PE.begin();
	while (beg != list_of_PE.end() && (*beg)->compare(*ptr) == -1)
		++beg;
	list_of_PE.insert(beg, move(ptr));
}

void Library::remove(std::function<bool(const PEPtr&)> _Pred)
{
	list_of_PE.remove_if(_Pred);
}

void Library::sort()
{
	list_of_PE.sort([](const PEPtr& ptrFirst, const PEPtr& ptrSecond)
		{
			return ptrFirst->compare(*ptrSecond) == -1;
		});
}

void Library::print()
{
	for (const PEPtr& ptr : list_of_PE)
		ptr->print();
}
