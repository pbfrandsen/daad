#include <stdio.h>
#include <string>

#include <stdlib.h>        /* required for malloc (otherwise compiler error on 64 bit machines) */
#include <ctype.h>         /* required if compiled with g++ instead of gcc */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

class CFile
{
 private:
  int       fileid;
  char      buffer[1000000];
  char*     buffer_end;
  char*     buffer_pos;
  
  char      __last;
  bool      __eof;


  void fill_buffer()
  {
    int n = read(fileid, (void *)buffer, 1000000);

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
  void ffopen(char *name)
  {
    fileid = open(name, O_RDONLY);

    //    if ( fileid == -1 )
    //      throw 1;
 
    buffer_end = buffer;
    buffer_pos = buffer;
    __eof      = false;
  }

  void ffclose()
  {
    close(fileid);
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

    while ( !__eof && i < n-1, c != delim)
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
