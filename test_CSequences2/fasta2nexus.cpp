#include "../CSequences2.h"
#include <iostream>
#include "CFile/CFile2_1.h"
#include "../faststring2.h"
#include "../fast-realloc-vector.h"

using namespace std;


int fasta2nexus(int type, const char *fn)
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

  CSequences2 *seqs;

  if (type == 1)
    seqs = new CSequences2(CSequence_Mol::dna);
  else
    seqs = new CSequences2(CSequence_Mol::protein);

  CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);
  seqs->read_from_Fasta_File(file, pflag, 0, -1, true);
  file.ffclose();

  cerr << "Found this number of taxa:      " << seqs->GetTaxaNum()  << endl;
  cerr << "Found this number of positions: " << seqs->GetPosNum()  << endl;


  seqs->ExportSequences(cout, 'n', 1000000000);
  delete seqs;
}



int main(int argc, const char ** argv)
{
  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " data-type <dna|protein> fasta-filename" << endl;
    cerr << "Data type must be either dna or protein" << endl;
    exit(0);
  }

  faststring filename  = argv[2];
  faststring datatype = argv[1];

  if (datatype == "dna")
    fasta2nexus(1, filename.c_str());
  else if  (datatype == "protein")
    fasta2nexus(2, filename.c_str());
  else
  {
    cerr << "Unknown datatype: " << datatype << ". Allowed parameters are \"dna\" or \"protein\"." << endl;
  }
}

