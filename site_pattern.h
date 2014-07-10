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
#includ <map>

class SitePattern
{
    faststring pattern;
public:
    // Takes a faststring that conatins the site pattern
    SitePattern(faststring new_pattern)
    {
        pattern = new_pattern;
    }
    // Store the length of the pattern (number of taxa)
    unsigned length = pattern.length();
    
    //Initiate a map to hold the partition splits
    std::map<char, <vector> > partition_map;
    partition_map['A'];
    partition_map['C'];
    partition_map['G'];
    partition_map['T'];
    
    
//    unsigned number_of_sites = pattern.length();
//    std::vector<std::bitset<number_of_sites> > bitset_vector;
    // NOTE: having a problem here of getting the vector to store the bitsets intitialized...
    
//    void calculate_pa(friend SitePattern j)
//    {
//        
//    }
    
    // print to the stream that the user chooses
    void print(std::ostream &os)
    {
        os << pattern;
    }
    
    // fill an vector with 4 bitsets
    
    std::map gen_pattern_partition()
    {
        
        for (int i = 0; i < length; ++i)
        {
            if (pattern[i] == 'A')
                partition_map['A'].push_back(i);
            else if (pattern[i] == 'C');
                paritition_map['C'].push_back(i);
            else if (pattern[i] == 'G');
                partition_map['G'].push_back(i);
            else if (pattern[i] == 'T');
                partition_map['T'].push_back(i);
        }
        return partition_map;
    }
};

#endif
