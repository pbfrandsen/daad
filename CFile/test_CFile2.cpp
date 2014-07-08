#include "CFile2.h"
#include <iostream>

using namespace std;


void write_dos_file()
{
  ofstream os("dat.txt");

  os << "12345\r\n67890\r\n1";
  os.close();
}

void write_mac_file()
{
  ofstream os("dat.txt");

  os << "12345\r67890\r1";
  os.close();
}


void copy_by_char()
{
  CFile file;
  char  c;

  file.ffopen("dat.txt");

  c = file.getchar();
  //  cerr << (int)file.status();
  while (!file.eof())
  {
    cout << c;
    c = file.getchar();
    //    cerr << (int)file.status() << endl;
    //    cerr << file.line() << endl;
  }

  file.ffclose();
}


void copy_by_char_unget()
{
  CFile file;
  char  c;

  file.ffopen("dat.txt");

  c = file.getchar();
  while (!file.eof())
  {
    cout << c;
    if (c == '6')
    {
      file.ungetchar();
      //      file.ungetchar();
      //      cerr << (int)file.status();
      cout << "unget 6" << endl;
      break;
    }
    c = file.getchar();
  }

  c = file.getchar();
  while (!file.eof())
  {
    cout << c;
    c = file.getchar();
  }

  file.ffclose();
}


void copy_by_char_tee()
{
  CFile file;
  char  c, d;

  file.ffopen("dat.txt");

  d = file.peekchar();

  c = file.getchar();
  //  cerr << (int)file.status();
  while (!file.eof())
  {
    cout << c;
    cerr << d;

    d = file.peekchar();
    if (file.fail())
      break;
    c = file.getchar();
    //    cerr << (int)file.status() << endl;
    //    cerr << file.line() << endl;
  }

  file.ffclose();
}


void copy_by_line()
{
  CFile file;
  char  str[200];

  file.ffopen("dat.txt");

  cerr << "Line:   " <<  file.line() << endl;
  cerr << "Status: " <<  (int)file.status() << endl;
  file.getline(str, 200);

  while (!file.fail())
  {
    cout << str << endl;

    cerr << "Line: " <<  file.line() << endl;
    cerr << "Status: " <<  (int)file.status() << endl;

    file.getline(str, 200);
  }

  cerr << "Line: " <<  file.line() << endl;
  cerr << "Status: " <<  (int)file.status() << endl;


  file.ffclose();
}


int main()
{
  write_dos_file();
  // write_mac_file();

  // copy_by_line();
  copy_by_char_unget();
  // copy_by_char();

}
