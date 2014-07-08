#include <fstream>
#include <string>

class CFile : private std::ifstream
{
 private:
  std::streambuf*  pbuf;

  int              __last;

  int getchar_intern()
  {
    int    c = pbuf->sbumpc();
    return c;
  }

  void ungetchar_intern()
  {
    pbuf->sungetc();
  }

 public:
  void open(char *name)
  {
    std::ifstream::open(name);

    if ( !std::ifstream::good() )
      throw 1;
 
    pbuf = std::ifstream::rdbuf();
  }

  void close()
  {
    std::ifstream::close();
  }

  bool eof()
  {
    return __last == EOF;
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


  int getchar_special()
  {
    int c;

    c = getchar_intern();

    if (c == '\r')
    {
      c = getchar_intern();
      if ( c != '\n' )
      {
	ungetchar();    /* old mac format */
	                /* else dos format     */
      }
      c = '\n';
    }
    return (__last = c);  
  }

  int getchar()
  {
    return (__last = getchar_intern());
  }

  void getline(std::string& str, char delim='\n')
  {
    int     c = getchar();
    str="";
    while ( c != EOF && c != delim)
    {
      str.push_back((char)c);
      c = getchar(); 
    }
  }

  char lastchar()
  {
    return __last;
  }

};
