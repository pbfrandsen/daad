#include "../CSequences2.h"
#include <iostream>
#include "CFile/CFile2_1.h"
#include "../faststring2.h"
#include "../fast-realloc-vector.h"

using namespace std;

void print_dist(short i, short j, double d)
{
  cout << "d(" << i << "," << j << ")=" << d << endl;
}



int test_fasta(const char *fn, int flag)
{
  CFile file;

  cerr << "Reading fasta file: " << fn << endl;

  file.ffopen(fn);

  if (file.fail())
  {
    cerr << "Could not open specified file: " << fn << endl;
    exit(-1);

  }

  CSequences2 seqs(CSequence_Mol::dna);

  CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);

  pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_toupper);
  pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_ambig2N);

  cerr << "Processing flag is: " << pflag << endl;

  seqs.read_from_Fasta_File(file, pflag, 0, -1, true);

  file.ffclose();

  cerr << "Found this number of taxa:      " << seqs.GetTaxaNum()  << endl;
  cerr << "Found this number of positions: " << seqs.GetPosNum()   << endl;

  int i, n = seqs.GetPosNum();

  int windowsize = 120;

  for (i=0; i<n-windowsize; ++i)
  {
    cout << " Range: " << i << " " << i+windowsize << endl;
    seqs.get_sequences_distances(i,   i+windowsize, print_dist, 1);
  }




}




int main(int argc, const char ** argv)
{
  if (argc != 2)
  {
    cerr << "Usage: a.out fasta-filename" << endl;
    exit(0);
  }

  faststring filename = argv[1];

  test_fasta(filename.c_str(), 0);





}

