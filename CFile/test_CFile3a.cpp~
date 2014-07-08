#include "CFile2_1.h"
#include <iostream>

using namespace std;

void test_read_file_to_string()
{
  CFile file;

  file.ffopen("dat2_linux.txt");

  faststring fstr;

  file.readFileIntoString(fstr);

  cout << endl;
  cout << endl;
  cout << endl;
  cout << "The content of dat2_linux.txt" << endl;
  cout << fstr << endl;

  
}

void write_linux_file()
{
  ofstream os("dat_linux.txt");

  os << "12345\n\n\n\n\n\n\n\n\n\n\n\n67890\nlin";
  os.close();
}

void write_dos_file()
{
  ofstream os("dat_dos.txt");

  os << "12345\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n67890\r\ndos";
  os.close();
}

void write_mac_file()
{
  ofstream os("dat_mac.txt");

  os << "12345\r\r\r\r\r\r\r\r\r\r\r\r67890\rmac";
  os.close();
}


void copy_by_char()
{
  CFile file;
  char  c;

  //  file.ffopen("dat.txt");
  //  file.ffopen("dat_mac.txt");
  file.ffopen("dat_dos.txt");
  // file.ffopen("dat_linux.txt");
  
  ofstream os("dat_out.txt");

  c = file.getchar();
  //  cerr << (int)file.status();
  while (!file.eof())
  {
    os << c;
    c = file.getchar();
    //    cerr << (int)file.status() << endl;
    //    cerr << file.line() << endl;
  }

  file.ffclose();
  os.close();
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
  write_mac_file();
  write_linux_file();

  // copy_by_line();
  // copy_by_char_unget();
  copy_by_char();

  test_read_file_to_string();
}
