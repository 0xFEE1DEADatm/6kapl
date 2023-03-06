#pragma once
#include"PrintEdition.h"

class Book : public PrintEdition
{
	std::string autor;
	std::string genre;
	std::string binding;
	std::string type;

public:
	Book();
	Book(std::string name, int pages, std::string publishingHouse, std::string type, std::string autor, std::string genre, std::string binding);

	std::string get_autor() const;
	std::string get_genre() const;
	std::string get_binding() const;
	std::string get_type() const;

	void set_autor(std::string a);
	void set_genre(std::string g);
	void set_binding(std::string b);
	void set_type(std::string t);

	//std::string toString();
	void print();
};

Book::Book()
	: PrintEdition(), autor(""), genre(""), binding("") {}

Book::Book(std::string name, int pages, std::string publishingHouse, std::string type, std::string autor, std::string genre, std::string binding)
	: PrintEdition(name, pages, publishingHouse, type), autor(autor), genre(genre), binding(binding) {}

std::string Book::get_type() const
{
	return type;
}
std::string Book::get_autor() const
{
	return autor;
}
std::string Book::get_genre() const
{
	return genre;
}
std::string Book::get_binding() const
{
	return binding;
}

void Book::set_type(std::string t)
{
	type = t;
}
void Book::set_autor(std::string a)
{
	autor = a;
}
void Book::set_genre(std::string g)
{
	genre = g;
}
void Book::set_binding(std::string b)
{
	binding = b;
}

void Book::print()
{
	PrintEdition::print();
	std::cout << autor << '\n' << genre << '\n' << binding << "\n..........\n";
}
