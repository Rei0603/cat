#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <sysexits.h>
#ifdef _WIN32
#include <io.h>
#endif

using namespace std;
void cat(istream &is);
int main(int argc, char *argv[])
{
	ios_base::openmode mode = ios_base::in;
#ifdef _WIN32
	if(! ::isatty(fileno(stdout)))
	{
		mode |= ios_base::binary;
		setmode( fileno( stdout ), O_BINARY );
	}
#endif
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
				return EX_NOINPUT;
			}
			cat(is);
		}
	}
	return EX_OK;
}
void cat(istream &is)
{
	char c;
	while (is.get(c))
	{
		cout << c;
	}
}
