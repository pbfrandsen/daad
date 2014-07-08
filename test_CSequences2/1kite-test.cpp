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

  CSequences2 seqs(CSequence_Mol::protein);

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
     cerr << "Taxon: " << i << ": " << seqs.get_seq(i)->getName() << endl;
     cerr << seqs.get_seq(i)->getSeqStr() << endl;
   }

   // Test unique phylip names:
  vector<faststring> vofs;
  seqs.unique_phylip_names(vofs);

  cerr << "Unique phylip names: " << endl;
  for (i=0; i< vofs.size(); ++i)
  {
    cerr << i << ": " << vofs[i] << ":" << endl;
  }



  seqs.ExportSequences(cout, 'f', 100);

  //  seqs.reorder_move_seq_to_top("seq3");
  //  seqs.reorder_move_seq_to_top("seq1");

  seqs.move_1kite_core_taxa_sorted_to_top();

  cout << endl << endl;

  seqs.ExportSequences(cout, 'f', 100);

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
  if (argc == 2 )
  {
    faststring filename1  = argv[1];

    test_fasta(filename1.c_str());
  }
  else if (argc == 3)
  {

    faststring filename1  = argv[1];
    faststring filename2  = argv[2];

    CSequences2 seqs1(CSequence_Mol::protein);
    CSequences2 seqs2(CSequence_Mol::protein);
    
    CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);
    pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_toupper);
    pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::convert_ambig2N);
    pflag = CSequence_Mol::processing_flag(pflag | CSequence_Mol::gaps_to_ambig);

    CFile file1;
    cerr << "Reading fasta file: " << filename1 << endl;
    file1.ffopen(filename1.c_str());
    if (file1.fail())
    {
      cerr << "Could not open specified file: " << filename1 << endl;
      exit(-1);
    }

    cerr << "Processing flag is: " << pflag << endl;
    seqs1.read_from_Fasta_File(file1, pflag, 0, -1, true);
    file1.ffclose();
    cerr << "Finished." << endl;
    
    CFile file2;
    cerr << "Reading fasta file: " << filename2 << endl;
    file2.ffopen(filename2.c_str());
    if ( file2.fail() )
    {
      cerr << "Could not open specified file: " << filename2 << endl;
      exit(-1);
    }
    
    cerr << "Processing flag is: " << pflag << endl;
    seqs2.read_from_Fasta_File(file2, pflag, 0, -1, true);
    file2.ffclose();
    cerr << "Finished." << endl;

    seqs1.move_1kite_core_taxa_sorted_to_top();
    seqs1.move_1kite_core_of_other_seqs_to_top(seqs2);

    seqs1.ExportSequences(cout, 'f', 100);
  }
  else
  {
    cerr << "Usage: a.out fasta-filename fasta-filename" << endl;
    exit(0);
  }
}

