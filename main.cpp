#include <iostream>
#include <sstream>
#include "printercalc.cpp"
using namespace std;

template <class T>
void printArray(T array[], size_t begin, size_t end)
{
  for (; begin <= end; ++begin) cout << array[begin] << ' ';
  cout << endl;
}

int getArgs(int argc, char* argv[])
{
  unsigned int pages = 0;
  if (argc > 1)
    {
      stringstream ss(argv[1]);
      if (!(ss >> pages))
	pages = 0;
    }
  return pages;
}

int main(int argc, char* argv[])
{
  int n_pages = getArgs(argc, argv);
  if (n_pages < 4 || n_pages % 4 != 0)
    return -1;
  else
    {
      int pages[n_pages];
      printercalc(pages, n_pages);
      printArray(pages, 0, n_pages/2 - 1);
      printArray(pages, n_pages/2, n_pages - 1);
    }
  return 0;
}
