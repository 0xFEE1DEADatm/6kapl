#pragma once
#include"PrintEdition.h"

class Magazine : public PrintEdition
{
private:
	int num;
	int year;
	std::string webSite;
	std::string type;

public:
	Magazine();
	Magazine(std::string name, int pages, std::string publishingHouse, std::string type, int num, int year, std::string webSite);

	std::string get_type() const;
	int get_num() const;
	int get_year() const;
	std::string get_webSite() const;

	void set_type(std::string t);
	void set_num(int n);
	void set_year(int y);
	void set_webSite(int w);
	
	bool ifWebSite();

	//std::string toString() ;
	void print();
};


Magazine::Magazine()
	: PrintEdition(), num(0), year(0), webSite("") {}

Magazine::Magazine(std::string name, int pages, std::string publishingHouse, std::string type, int num, int year, std::string webSite)
	: PrintEdition(name, pages, publishingHouse, type), num(num), year(year), webSite(webSite) {}


std::string Magazine::get_type() const
{
	return type;
}
int Magazine::get_num() const
{
	return num;
}
int Magazine::get_year() const
{
	return year;
}
std::string Magazine::get_webSite() const
{
	return webSite;
}

void Magazine::set_type(std::string t)
{
	type = t;
}
void Magazine::set_num(int n)
{
	num = n;
}
void Magazine::set_year(int y)
{
	year = y;
}
void Magazine::set_webSite(int w)
{
	webSite = w;
}


bool Magazine::ifWebSite()
{
	if (webSite != "-")
		return true;
	else return false;
}

//std::string Magazine::toString() 
//{
//	return PrintEdition::toString() + type + '\n' + std::to_string(num) + '\n' + std::to_string(year) + '\n' + webSite;
//}

void Magazine::print()
{
	PrintEdition::print();
	std::cout << num << '\n' << year << '\n' << webSite << "\n..........\n";
}
