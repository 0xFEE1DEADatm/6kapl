#include "Library.h"
#include "Magazine.h"
#include "Book.h"
#include <fstream>

void task(Library& library)
{
	auto ifWebSite = [](const PEPtr& ptr)
	{
		Magazine* tmp = dynamic_cast<Magazine*>(ptr.get());
		return tmp && tmp->get_webSite() == "-";
	};
	library.remove(ifWebSite);
}

int main()
{
	setlocale(0, "");

	Library library;

	std::ifstream file("input.txt");

	if (file)
	{
		std::string autor, genre, binding, name, publishingHouse, type, webSite;
		int num, year, pages;
		std::string divider;

		while (file >> type)
		{
			file >> name >> pages >> publishingHouse;

			if (type == "Book")
			{
				file >> autor >> genre >> binding >> divider;
				Book b(name, pages, publishingHouse, type, autor, genre, binding);
				library.insert(std::move(std::make_unique<Book>(b)));
			}
			else if (type == "Magazine")
			{
				file >> num >> year >> webSite >> divider;
				Magazine m(name, pages, publishingHouse, type, num, year, webSite);
				library.insert(std::move(std::make_unique<Magazine>(m)));
			}
		}
	}
	else std::cout << "Error!\n";

	library.print();
	std::cout << "_______________________________________\n";
	task(library);
	library.print();

	file.close();
	std::cin.get();
}
