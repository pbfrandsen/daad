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
#include <map>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <numeric>
#include "../kmeans.h"

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

/* This main function is for when using bitsets */
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
        unsigned alignment_length = sequences.GetPosNum();
        
        vector<faststring> seq_patterns;
        vector<SitePattern> all_patterns;
        
        seq_patterns.reserve(alignment_length);
        all_patterns.reserve(alignment_length);
        // TODO: Use reference for this rather than making a copy
        seq_patterns = sequences.get_pattern_vec();
        
        SitePattern temp(seq_patterns[0]);
        // TODO: Use reference here as well
        vector <CSplit> site_partition = temp.gen_pattern_bitsets();
        
        int i;
        int j;
        
        for (i = 0; i < alignment_length; ++i)
        {
            temp.reset_pattern(seq_patterns[i]);
            site_partition = temp.gen_pattern_bitsets();
            all_patterns[i] = (temp);
        }

        
        double pa_sum;
        vector<double> site_rates(alignment_length);
        for (i = 0; i < alignment_length; ++i)
        {
            pa_sum = 0;
            for (j = 0; j < alignment_length; ++j)
            {
                if (i == j)
                    continue;
                else
                    pa_sum += all_patterns[i].calculate_pa_2(all_patterns[j]);
            }
            site_rates[i] = (pa_sum/(alignment_length - 1));
        }
        copy(site_rates.begin(), site_rates.end(), ostream_iterator<double>(cout, "\n"));
        cout << endl;
        vector <int> cluster_assigns;
        cluster_assigns = kmeans(site_rates, 2);
        copy(cluster_assigns.begin(), cluster_assigns.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
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


/* This whole function is for when we use the map instead of the bitsets. I should probably modularize the code so that the map or vector is just passed to one function, I just haven't yet...*/

// int main(int argc, const char ** argv)
// {
//
//     cout << sizeof(unsigned) << endl;
//     cout << sizeof(unsigned long) << endl;
//     // open the file (in this case, fasta, we can add an option for phylip if we wish...
//     if (argc != 3)
//     {
//         cerr << "Usage: " << argv[0] << " data-type fasta-filename" << endl;
//         cerr << "Data type must be either dna or protein" << endl;
//         exit(0);
//     }
//
//
//     faststring filename = argv[2];
//     faststring data_type = argv[1];
//
//     if (data_type == "dna")
//     {
//         CSequences2 sequences = read_fasta_file(1, filename.c_str());
//         unsigned alignment_length = sequences.GetPosNum();
//
//         vector<faststring> seq_patterns;
//         vector<SitePattern> all_patterns;
//
//         seq_patterns = sequences.get_pattern_vec();
//
//         SitePattern temp(seq_patterns[0]);
// //        temp.print(cout);
// //        cout << endl;
// //
// //        temp.reset_pattern(seq_patterns[1]);
// //        temp.print(cout);
// //        cout << endl;
// //
// //        temp.reset_pattern(seq_patterns[2]);
// //        temp.print(cout);
// //        cout << endl;
//
//         map <char, vector <int> > site_partition = temp.gen_pattern_partition();
//
//         int i;
//         int j;
//
//         for (i = 0; i < alignment_length; ++i)
//         {
//             temp.reset_pattern(seq_patterns[i]);
// //            cout << "Site pattern:" << endl;
// //            temp.print(cout);
// //            cout << endl;
//             temp.gen_pattern_partition();
//
//
//             all_patterns.push_back(temp);
//
// //            if (i < 10)
// //            {
// //                cout << "On item number: " << i << endl;
// //                cout << "Here are your A's:" << endl;
// //                copy(site_partition['A'].begin(), site_partition['A'].end(), ostream_iterator<int>(cout, " "));
// //                cout << endl;
// //
//                cout << "Here are your C's:" << endl;
//                copy(site_partition['C'].begin(), site_partition['C'].end(), ostream_iterator<int>(cout, " "));
//                cout << endl;
//
//                cout << "Here are your G's:" << endl;
//                copy(site_partition['G'].begin(), site_partition['G'].end(), ostream_iterator<int>(cout, " "));
//                cout << endl;
//
//                cout << "Here are your T's:" << endl;
//                copy(site_partition['T'].begin(), site_partition['T'].end(), ostream_iterator<int>(cout, " "));
// //                cout << endl << endl;
// //            }
//         }
//
// //        cout << "End of site patterns..." << endl << endl;
//
// //        for (int f=0; f< alignment_length; ++f)
// //        {
// //            all_patterns[f].print(cout);
// //            cout << endl;
// //        }
//
//         double pa_sum;
//         vector<double> site_rates;
//         for (i = 0; i < alignment_length; ++i)
//         {
//             pa_sum = 0;
//             for (j = 0; j < alignment_length; ++j)
//             {
//                 if (i == j)
//                     continue;
//                 else
//                 {
//                     pa_sum += all_patterns[i].calculate_pa(all_patterns[j]);
// //                    cout << "pa for these: ";
// //                    all_patterns[i].print(cout);
// //                    cout << ", ";
// //                    all_patterns[j].print(cout);
// //                    cout << " is " << all_patterns[i].calculate_pa(all_patterns[j]) << endl;
//                 }
//             }
//             site_rates.push_back(pa_sum/(alignment_length - 1));
//         }
//         copy(site_rates.begin(), site_rates.end(), ostream_iterator<double>(cout, "\n"));
//         cout << endl;
//
//     }
//     else if (data_type == "protein")
//         CSequences2 sequences = read_fasta_file(2, filename.c_str());
//     else
//     {
//         cerr << "Unknown data type: " << data_type << ". Please enter either dna or protein." << endl;
//         return 0;
//     }
//
//
//
//     return 0;
// }