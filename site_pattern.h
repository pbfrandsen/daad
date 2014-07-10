//
//  site_pattern.h
//  
//
//  Created by Paul Frandsen on 7/8/14.
//
//

#ifndef _site_pattern_h
#define _site_pattern_h

#include <vector>
#include "faststring2.h"
#include "CSplit2.h"
#include <map>

class SitePattern
{
    faststring pattern;
public:
    // Takes a faststring that conatins the site pattern
    SitePattern(faststring new_pattern)
    {
        pattern = new_pattern;
    }
    
    // print to the stream that the user chooses
    void print(std::ostream &os)
    {
        os << pattern;
    }
    
    // create a map containing the nucleotide states as keys with a vector of ints
    std::map<char, std::vector<int> > gen_pattern_partition()
    {
        // Initiate a map to hold the partition splits
        // character state as keys and taxon numbers as values
        std::map<char, std::vector<int> > partition_map;
        std::vector<int> a;
        std::vector<int> c;
        std::vector<int> g;
        std::vector<int> t;
        partition_map['A'] = a;
        partition_map['C'] = c;
        partition_map['G'] = g;
        partition_map['T'] = t;
        
        // figure out the length of the site pattern
        unsigned long length = pattern.length();

        // loop through the pattern and assign partitions to map
        for (int i = 0; i < length; ++i)
        {
            if (pattern[i] == 'A')
                partition_map['A'].push_back(i);
            else if (pattern[i] == 'C')
                partition_map['C'].push_back(i);
            else if (pattern[i] == 'G')
                partition_map['G'].push_back(i);
            else if (pattern[i] == 'T')
                partition_map['T'].push_back(i);
        }
        return partition_map;
    }
    
//    double calculate_pa(friend SitePattern j)
//    {
//        
//    }
};

#endif
