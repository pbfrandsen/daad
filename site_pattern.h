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

class SitePattern
{
    faststring pattern;
public:
    // Takes a faststring that conatins the site pattern
    SitePattern(faststring new_pattern)
    {
        pattern = new_pattern;
    }
    
    unsigned number_of_sites = pattern.length();
    vector<bitset<number_of_sites> > bitset_vector;
    
//    void calculate_pa(friend SitePattern j)
//    {
//        
//    }
    
    // print to the stream that the user chooses
    void print(std::ostream &os)
    {
        os << pattern;
    }
    
    // fill an array with 4 bitsets
    
    void gen_bitset_vector()
    {
        
    }
};

#endif
