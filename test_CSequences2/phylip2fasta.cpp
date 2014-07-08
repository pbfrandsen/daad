#include "../CSequences2.h"
#include <iostream>
#include "CFile/CFile2_1.h"
#include "../faststring2.h"
#include "../fast-realloc-vector.h"

using namespace std;

void usage(const char * progname)
{
    cerr << "Usage: " << progname << " data-type [strict] phylip-filename" << endl;
    cerr << "Data type must be either \"dna\" or \"protein\". Use the optional parameter \"strict\" to enforce reading the strict phylip format. Otherwise, the relatexed phylip format is assumed." << endl;
}

// phylip_format: 0 strict phylip standard. Sequence names are exactly 10 characters long.
//                1 relaxed sequence name length. Sequence names end with first space and can have anly length.
//                Spaces are not allowed in sequence names.

int convert_phylip_to_fasta(int type, const char *fn, unsigned phylip_format)
{
  CFile file;

  cerr << "Reading phylip file: " << fn << endl;

  file.ffopen(fn);

  if (file.fail())
  {
    cerr << "Could not open specified file: " << fn << endl;
    exit(-1);
  }


  //  cerr << "Line:   " <<  file.line() << endl;
  // cerr << "Status: " <<  (int)file.status() << endl;

//   CSequences2 seqs(CSequence_Mol::protein);
//   seqs.read_from_Phylip_File(file, 1);
//   file.ffclose();

  CSequences2 *seqs;

  if (type == 1)
    seqs = new CSequences2(CSequence_Mol::dna);
  else
    seqs = new CSequences2(CSequence_Mol::protein);

  CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);
  seqs->read_from_Phylip_File(file, phylip_format);
  file.ffclose();

  cerr << "Found this number of taxa:      " << seqs->GetTaxaNum()  << endl;
  cerr << "Found this number of positions: " << seqs->GetPosNum()  << endl;

  //  seqs->ExportSequences(cout, 'n', 1000000000);
  seqs->ExportSequences(cout, 'f', -1u);
  delete seqs;
}


int main(int argc, const char ** argv)
{
  faststring filename;
  faststring datatype;
  faststring mode;
  unsigned   phylip_format = 1;

  if (argc == 3)
  {
    filename  = argv[2];
    datatype  = argv[1];
    phylip_format = 1;
  }
  else
  if (argc == 4)
  {
    filename  = argv[3];
    datatype  = argv[1];
    mode      = argv[2];
    if (mode != "strict")
    {
      cerr << "Unknown option: " << mode << endl;
      usage(argv[0]);
      exit(0);
    }
    phylip_format = 0;
  }
  else
  {
    usage(argv[0]);
    exit(0);
  }


  if (datatype == "dna")
    convert_phylip_to_fasta( 1, filename.c_str(), phylip_format);
  else if  (datatype == "protein")
    convert_phylip_to_fasta( 2, filename.c_str(), phylip_format);
  else
  {
    cerr << "Unknown datatype: " << datatype << ". Allowed parameters are \"dna\" or \"protein\"." << endl;
  }

}

