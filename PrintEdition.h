#pragma once
#include <iostream>
#include <string>

class PrintEdition
{
	std::string name;
	int pages;
	std::string publishingHouse;
	std::string type;

public:
	PrintEdition();
	PrintEdition(std::string name, int pages, std::string publishingHouse, std::string type);

	std::string get_name() const;
	int get_pages() const;
	std::string get_publishingHouse() const;

	void set_name(std::string n);
	void set_pages(int p);
	void set_publishingHouse(std::string ph);
	
	int compare(const PrintEdition& obj) const;

	//std::string toString();
	virtual void print();
};

PrintEdition::PrintEdition() : name(""), pages(0), publishingHouse(""), type("") {}

PrintEdition::PrintEdition(std::string name, int pages, std::string publishingHouse, std::string type) : name(name), pages(pages), publishingHouse(publishingHouse), type(type) {}

void PrintEdition::set_name(std::string n)
{
	name = n;
}
void PrintEdition::set_pages(int p)
{
	pages = p;
}
void PrintEdition::set_publishingHouse(std::string ph)
{
	publishingHouse = ph;
}

std::string PrintEdition::get_name() const
{
	return name;
}
int PrintEdition::get_pages() const
{
	return pages;
}
std::string PrintEdition::get_publishingHouse() const
{
	return publishingHouse;
}

int PrintEdition::compare(const PrintEdition& obj) const/////
{
	int res = 0;
	if (obj.name >= name)
		res = -1;
	return res;
}

//std::string PrintEdition::toString() 
//{
//	return name + '\n' + std::to_string(pages) + '\n' + publishingHouse;
//}

void PrintEdition::print()
{
	std::cout << type << '\n' << name << '\n' << pages << '\n' << publishingHouse << '\n';
}
