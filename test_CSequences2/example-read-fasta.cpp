#include "../CSequences2.h"
#include <iostream>
#include "CFile/CFile2_1.h"
#include "../faststring2.h"
#include "../fast-realloc-vector.h"

using namespace std;


int test_fasta(const char *fn)
{
  CFile file;

  cerr << "Reading fasta file: " << fn << endl;

  file.ffopen(fn);

  if (file.fail())
  {
    cerr << "Could not open specified file: " << fn << endl;
    exit(-1);

  }

  //  cerr << "Line:   " <<  file.line() << endl;
  // cerr << "Status: " <<  (int)file.status() << endl;

  CSequences2 seqs(CSequence_Mol::dna);

  CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);
  pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_toupper);
  pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_ambig2N);
  pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::gaps_to_ambig);

  cerr << "Processing flag is: " << pflag << endl;
  seqs.read_from_Fasta_File(file, pflag, 0, -1, true);
  file.ffclose();

  cerr << "Found this number of taxa:      " << seqs.GetTaxaNum()  << endl;
  cerr << "Found this number of positions: " << seqs.GetPosNum()  << endl;


  // Test: Export sequence by sequence:
  int i, n = seqs.GetTaxaNum();
  // Test output all sequences:
   for (i=0; i<n; ++i)
   {
     cout << "Taxon: " << i << ": " << seqs.get_seq(i)->getName() << endl;
     cout << seqs.get_seq(i)->getSeqStr() << endl;
   }

   // Test unique phylip names:
  vector<faststring> vofs;
  seqs.unique_phylip_names(vofs);

  cout << "Unique phylip names: " << endl;
  for (i=0; i< vofs.size(); ++i)
  {
    cout << i << ": " << vofs[i] << ":" << endl;
  }



  seqs.ExportSequences(cout, 'f', 10);
  seqs.ExportSequences(cout, 'p', 10);
  seqs.ExportSequences(cout, 'n', 10);

  seqs.reorder_move_seq_to_top("seq3");
    seqs.reorder_move_seq_to_top("seq1");

  seqs.ExportSequences(cout, 'f', 10);
  seqs.ExportSequences(cout, 'p', 10);
  seqs.ExportSequences(cout, 'n', 10);

//   fastvector<unsigned> fv;
//   seqs.get_vector_of_site_pattern_frequencies(fv);
//   for (i=0; i< fv.size(); ++i)
//   {
//     cout << i << " " << fv.get_unckecked(i) << endl;
//   }

//  cout << "Site pattern statistic: " << seqs.compute_site_pattern_stat() << endl;
}



int main(int argc, const char ** argv)
{
  if (argc != 2)
  {
    cerr << "Usage: a.out fasta-filename" << endl;
    exit(0);
  }

  faststring filename  = argv[1];

  test_fasta(filename.c_str());
}

