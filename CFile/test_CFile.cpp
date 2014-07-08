#include "CFile.h"
#include <iostream>

using namespace std;

void copy_by_char()
{
  CFile file;
  char  c;

  file.ffopen("dat.txt");

  c = file.getchar();
  while (!file.eof())
  {
    cout << c;
    c = file.getchar();
  }

  file.ffclose();
}


void copy_by_line()
{
  CFile file;
  char  str[200];

  file.ffopen("dat.txt");

  file.getline(str, 200);

  while (!file.eof())
  {
    cout << str << endl;
    file.getline(str, 200);
  }

  file.ffclose();
}


int main()
{

  copy_by_char();

}
