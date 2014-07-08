#include "../CSequences2.h"
#include <iostream>
#include "CFile/CFile2_1.h"
#include "../faststring2.h"
#include "../fast-realloc-vector.h"

using namespace std;


int test_phylip(const char *fn)
{
  CFile file;

  cout << "Reading phylip file: " << fn << endl;

  file.ffopen(fn);

  if (file.fail())
  {
    cerr << "Could not open specified file: " << fn << endl;
    exit(-1);
  }


  //  cerr << "Line:   " <<  file.line() << endl;
  // cerr << "Status: " <<  (int)file.status() << endl;

  CSequences2 seqs(CSequence_Mol::protein);

  seqs.read_from_Phylip_File(file, 1);

  file.ffclose();

  cerr << "Found this number of taxa:      " << seqs.GetTaxaNum()  << endl;
  cerr << "Found this number of positions: " << seqs.GetPosNum()  << endl;

  seqs.ExportSequences(cout, 'n', 1000000000);
  seqs.ExportSequences(cout, 'f', 1000000000);
}


int main(int argc, const char ** argv)
{
  if (argc != 2)
  {
    cerr << "Usage: a.out phylip-filename" << endl;
    exit(0);
  }

  faststring filename = argv[1];

  test_phylip(filename.c_str());





}

