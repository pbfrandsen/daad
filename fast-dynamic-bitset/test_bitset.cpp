#include "fast-dynamic-bitset.h"
#include <map>

using namespace std;


void test_non_any(fast_dynamic_bitset &a)
{
  if ( a.none() )
  {
    cout << "none is true" << endl;
  }
  else
  {
    cout << "none is false" << endl;
  }
  if ( a.any() )
  {
    cout << "any is true" << endl;
  }
  else
  {
    cout << "any is flase" << endl;
  }
}


void test_set(fast_dynamic_bitset &a, unsigned long i)
{
  cout << "Test setting bit " << i << endl;
  a.set(i);
  cout << a << endl;
  cout << "Number of bits sets: " << a.count() << endl;
  test_non_any(a);
  a.flip();
  cout << a << endl;
  cout << "Number of bits sets: " << a.count() << endl;
  test_non_any(a);
  a.flip();
  cout << endl;
}




void test_basic()
{
  cout << "Test constructor with 40 bits:" << endl;
   fast_dynamic_bitset g(40);
   cout << g << endl;
   test_non_any(g);
   cout << endl;

   unsigned i;
   for (i=0; i<40; ++i)
     test_set(g,i);

   cout << "Clear test:" << endl;
   g.clear();
   cout << g << endl;
   test_non_any(g);
   cout << endl;

   g.set();
   cout << g << endl;
   test_non_any(g);
   cout << endl;

   g.clear();
   g.set(1);
   g.set(3);
   g.set(5);
   cout << g << endl;
   test_non_any(g);
   cout << endl;
   
   g.reset(3);
   cout << g << endl;
   test_non_any(g);
   cout << endl;

   fast_dynamic_bitset h(40);
   g.set(30);
   g.set(31);
   g.set(32);

   h.set(32);
   h.set(33);
   h.set(34);

   fast_dynamic_bitset Rand, Ror, Rxor;

   Rand = g & h;
   Ror  = g | h;
   Rxor = g ^ h;

   cout << "g: " << g    << endl;
   cout << "h: " << h    << endl;

   cout << "&: " << Rand << endl;
   cout << "|: " << Ror  << endl; 
   cout << "^: " << Rxor << endl; 
   




//   cout << "testing count :";
//   cout << g.count() << endl;

//   cout << "flip:" << endl;
//   g.flip();
//   cout << g << endl;
//   cout << g.count() << endl;

//   cout << "flip:" << endl;
//   g.flip();
//   cout << g << endl;
//   cout << g.count() << endl;

//   cout << "test set and count" << endl;
//   g.set();
//   cout << g << endl;
//   cout << g.count() << endl;

//   cout << "test reset and count" << endl;
//   g.reset();
//   cout << g << endl;
//   cout << g.count() << endl;

//   g.set();
//   cout << g << endl;

//   g.set(34,0);
//   cout << g << endl;

//   g.set(3,0);
//   cout << g << endl;

//   g.reset(32);
//   cout << g << endl;

//   g.flip(38);
//   cout << g << endl;

//   g.flip(3);
//   cout << g << endl;

//   fast_dynamic_bitset h(g);

//   cout << "h:" << endl << h << endl;


//   g.reset();
//   cout << g << endl;

//   unsigned k;

//   for (k=0; k<40; ++k)
//   {
//     g.flip(k);
//     cout << g << endl;
//   }

//   for (k=0; k<40; ++k)
//   {
//     g.flip(k);
//     cout << g << endl;
//   }


//   //-------------------------------
//   cout << endl << endl;
//   //-------------------------------

//   fast_dynamic_bitset x = h;

//   g.set(3);  g.set(13);  g.set(23);  g.set(33); g.set(34);

//   cout << "x" << endl << x << endl;
//   cout << "h" << endl << h << endl;
//   cout << "g" << endl << g << endl;

//   cout << (x & g) << endl;

//   cout << (x | g) << endl;

//   cout << (x ^ g) << endl;


//   fast_dynamic_bitset a(40);
//   fast_dynamic_bitset b(40);
//   fast_dynamic_bitset c(40);
//   fast_dynamic_bitset d(40);

//   a.reset();
//   b.reset();
//   c.reset();
//   d.reset();



//   cout << "-------------------------------------------" << endl;
//   cout << "Test <, >, <=, >=, ==, !=:" << endl;
//   a.reset();
//   b.reset();
//   a.set(3);
//   b.set(4);
//   cout << "a" << endl << a << endl;
//   cout << "b" << endl << b << endl;

//   cout << (a < b ? "a < b: true" : "a < b: false") << endl;
//   cout << (a > b ? "a > b: true" : "a > b: false") << endl;
//   cout << (a <= b ? "a <= b: true" : "a <= b: false") << endl;
//   cout << (a >= b ? "a >= b: true" : "a >= b: false") << endl;
//   cout << (a == b ? "a == b: true" : "a == b: false") << endl;
//   cout << (a != b ? "a != b: true" : "a != b: false") << endl;

//   cout << "-------------------------------------------" << endl;
//   cout << "Test <, >, <=, >=, ==, !=:" << endl;
//   a.reset();
//   b.reset();
//   a.set(4);
//   b.set(4);
//   cout << "a" << endl << a << endl;
//   cout << "b" << endl << b << endl;

//   cout << (a < b ? "a < b: true" : "a < b: false") << endl;
//   cout << (a > b ? "a > b: true" : "a > b: false") << endl;
//   cout << (a <= b ? "a <= b: true" : "a <= b: false") << endl;
//   cout << (a >= b ? "a >= b: true" : "a >= b: false") << endl;
//   cout << (a == b ? "a == b: true" : "a == b: false") << endl;
//   cout << (a != b ? "a != b: true" : "a != b: false") << endl;

//   cout << "-------------------------------------------" << endl;
//   cout << "Test <, >, <=, >=, ==, !=:" << endl;
//   a.reset();
//   b.reset();
//   a.set(33);
//   b.set(32);
//   cout << "a" << endl << a << endl;
//   cout << "b" << endl << b << endl;

//   cout << (a < b ? "a < b: true" : "a < b: false") << endl;
//   cout << (a > b ? "a > b: true" : "a > b: false") << endl;
//   cout << (a <= b ? "a <= b: true" : "a <= b: false") << endl;
//   cout << (a >= b ? "a >= b: true" : "a >= b: false") << endl;
//   cout << (a == b ? "a == b: true" : "a == b: false") << endl;
//   cout << (a != b ? "a != b: true" : "a != b: false") << endl;

//   cout << "-------------------------------------------" << endl;
//   cout << "Test <, >, <=, >=, ==, !=:" << endl;
//   a.reset();
//   b.reset();
//   a.set(33);
//   b.set(34);
//   cout << "a" << endl << a << endl;
//   cout << "b" << endl << b << endl;

//   cout << (a < b ? "a < b: true" : "a < b: false") << endl;
//   cout << (a > b ? "a > b: true" : "a > b: false") << endl;
//   cout << (a <= b ? "a <= b: true" : "a <= b: false") << endl;
//   cout << (a >= b ? "a >= b: true" : "a >= b: false") << endl;
//   cout << (a == b ? "a == b: true" : "a == b: false") << endl;
//   cout << (a != b ? "a != b: true" : "a != b: false") << endl;


//   map<fast_dynamic_bitset, unsigned> testmap;


//   {
//     fast_dynamic_bitset a(4);
//     fast_dynamic_bitset b(4);
//     fast_dynamic_bitset c(4);

//     testmap[a] = 1;
//     testmap[b] = 2;
//     testmap[c] = 3;
//   }   
}


int main()
{
  test_basic();




}

