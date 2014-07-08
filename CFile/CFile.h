#ifndef CFILE_H
#define CFILE_H

#include <fstream>
#include <string>

#define BUFFERSIZE 1000000

// Idee: ios::   set Buffer size

// TODO: Old mac format not supported.
//       This requires to allow two successive calls to the internal ungetchar command.


class CFile : private std::ifstream
{
 private:
  char      buffer[BUFFERSIZE];
  char*     buffer_end;
  char*     buffer_pos;
  
  char      __last;
  bool      __eof;
  bool      __openFailed;


  void fill_buffer()
  {
    std::streamsize n;

    std::ifstream::read(buffer, BUFFERSIZE);
    n = std::ifstream::gcount();

    if ( n == 0 )
      __eof = true;

    buffer_pos = buffer;
    buffer_end = buffer + n;
  }

  char getchar_intern()
  {
    if ( buffer_pos == buffer_end )
      fill_buffer();
    return *buffer_pos++;
  }

  void ungetchar_intern()
  {
    if (buffer_pos != buffer)
      --buffer_pos;
    else
      throw 1;
  }

 public:
  void ffopen(const char *name)
  {
    std::ifstream::open(name);

    if ( std::ifstream::fail() )
    {
      __openFailed = true;
      return;
    }
 
    buffer_end    = buffer;
    buffer_pos    = buffer;
    __openFailed  = false;
    __eof         = false;
  }

  void ffclose()
  {
    std::ifstream::close();
  }

  bool exists()
  {
    return !__openFailed;
  }

  bool eof()
  {
    return __eof;
  }

  void ungetchar()
  {
    ungetchar_intern();
  }


  char peekchar()
  {
    char c = getchar();
    ungetchar();
    return c;
  }


  char getchar()
  {
    register char c;

    c = getchar_intern();

    if (!__eof && c == '\r')
    {
      c = getchar_intern();
      if ( !__eof && c != '\n' )
      {
	// 	std::cerr << "Old mac file format currently not supported." << std::endl;
	throw 2;        // not supported
	ungetchar();    /* old mac format */
	                /* else dos format     */
      }
      c = '\n';
    }
    return c;  
  }


 char getrawchar()
  {
    return getchar_intern();
  }


  void getline(std::string& str, char delim='\n')
  {
    char c = getchar();
    str="";
    while ( !__eof && c != delim)
    {
      str.push_back(c);
      c = getchar();
    }
    if (__eof && str.size() > 0)
      __eof = false;
  }

  void getline(char* cstr, unsigned n, char delim='\n')
  {
    char     c = getchar();
    unsigned i = 0;

    while ( !__eof && i < n-1 &&  c != delim)
    {
      cstr[i] = c;
      ++i;
      c = getchar(); 
    }
    if (__eof && i > 0)
      __eof = false;
    cstr[i] = '\0';
  }



  char lastchar()
  {
    char c;

    if ( buffer_pos != buffer_end )
      c = *(buffer_pos-1);
    else
      throw 1;

    /* It could be a '\r' in mac format */
    if (c == '\r')
      c = '\n';

    return c;
  }

  char lastrawchar()
  {
    char c;

    if ( buffer_pos != buffer_end )
      c = *(buffer_pos-1);
    else
      throw 1;

    return c;
  }


};


#endif
