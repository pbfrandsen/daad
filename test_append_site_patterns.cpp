#include <iostream>
#include "faststring2.h"
#include "CSequences2.h"
#include <vector>

using namespace std;

int main()
{
  vector<faststring> names;

  names.push_back("S1");
  names.push_back("S2");
  names.push_back("S3");
  names.push_back("S4");

  CSequences2 seqs(CSequence_Mol::dna, names, 1000);

  seqs.append_to_sequences("AAAA");
  seqs.append_to_sequences("CCCC");
  seqs.append_to_sequences("AAGG");
  seqs.append_to_sequences("TGGT");
  //  seqs.append_to_sequences("ACGTA");

  seqs.ExportSequences(cout, 'f', -1u);

}
