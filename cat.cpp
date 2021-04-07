#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
using namespace std;
void cat(istream &is);
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cat(cin);
		return 0;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			ifstream is;
			is.open(argv[i]);
			if (!is)
			{
				cerr << ::strerror(errno) << ":" << argv[i] << endl;
				return 1;
			}
			cat(is);
		}
	}
	return 0;
}
void cat(istream &is)
{
	char c;
	while (is.get(c))
	{
		cout << c;
	}
}