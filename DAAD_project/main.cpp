//
//  main.cpp
//  DAAD_project
//
//  Created by Paul Frandsen on 7/3/14.
//  Copyright (c) 2014 Paul Frandsen. All rights reserved.
//

#include <iostream>
#include "../CSequences2.h"
#include "../faststring2.h"
#include "../site_pattern.h"
#include "../Cfile/CFile2_1.h"

using namespace std;

CSequences2 read_fasta_file(int type, const char *fn )
{
    CFile file;
    
    cerr << "Reading fasta file:" << fn << endl;
    
    file.ffopen(fn);
    
    if (file.fail())
    {
        cerr << "Could not open specified file: " << fn << endl;
        exit(-1);
    }
    
    CSequences2 *seqs;
    if (type == 1)
        seqs = new CSequences2(CSequence_Mol::dna);
    else
        seqs = new CSequences2(CSequence_Mol::protein);
    
    CSequence_Mol::processing_flag pflag = CSequence_Mol::processing_flag(0);
    seqs->read_from_Fasta_File(file, pflag, 0, -1, true);
    file.ffclose();
    
    cerr << "Found " << seqs->GetTaxaNum() << " taxa." << endl;
    cerr << "Found " << seqs->GetPosNum() << " positions." << endl;
    
    return *seqs;
}


int main(int argc, const char ** argv)
{

    // open the file (in this case, fasta, we can add an option for phylip if we wish...
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " data-type fasta-filename" << endl;
        cerr << "Data type must be either dna or protein" << endl;
        exit(0);
    }
    
    
    faststring filename = argv[2];
    faststring data_type = argv[1];
    
    if (data_type == "dna")
    {
        CSequences2 sequences = read_fasta_file(1, filename.c_str());
        vector<faststring> seq_patterns;
        vector<SitePattern> all_patterns;

        seq_patterns = sequences.get_pattern_vec();
        
        SitePattern first(seq_patterns[0]);
        first.print(cout);
        cout << endl;
        
//        int i;
//        for (i = 0; i < 50; ++i)
//        {
//            cout << seq_patterns[i] << endl;
//        }
    }
    else if (data_type == "protein")
        CSequences2 sequences = read_fasta_file(2, filename.c_str());
    else
    {
        cerr << "Unknown data type: " << data_type << ". Please enter either dna or protein." << endl;
        return 0;
    }
    
    

    return 0;
}