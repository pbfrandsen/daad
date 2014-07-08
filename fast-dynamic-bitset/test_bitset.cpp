#include "fast-dynamic-bitset.h"
#include <map>

using namespace std;


void test_set(fast_dynamic_bitset &a, unsigned long i)
{
  cout << "Test setting bit " << i << endl;
  a.set(i);
  cout << a << endl;
}


int main()
{


//   cout << "Test constructor with 40 bits:" << endl;
//   fast_dynamic_bitset g(40);
//   cout << g << endl;

//   test_set(g,0);
//   test_set(g,2);
//   test_set(g,5);
//   test_set(g,7);

//   cout << "set 13, 31 32, 39, reset 2" << endl;
//   g.set(13,1);
//   g.set(31,1);
//   g.set(32,1);
//   g.set(39,1);
//   g.set(2,0);
//   cout << g << endl;

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


  map<fast_dynamic_bitset, unsigned> testmap;


  {
    fast_dynamic_bitset a(4);
    fast_dynamic_bitset b(4);
    fast_dynamic_bitset c(4);

    testmap[a] = 1;
    testmap[b] = 2;
    testmap[c] = 3;
  }


}

