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
    std::map<char, std::vector<int> > partition_map;
public:
    // Takes a faststring that conatins the site pattern
    SitePattern(faststring new_pattern)
    {
        pattern = new_pattern;
    }
    SitePattern()
    {
        pattern = "";
    }
    void reset_pattern(faststring new_pattern)
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
    std::map<char, std::vector<int> > give_pattern_partition()
    {
        return partition_map;
    }
    
    // Now we need to have a function that can calculate and return the a(x, P(i))
    // between this site pattern and another
    double calculate_axpi(SitePattern & j)
    {
        double axpi = 0;
        int num_parts = 4;
        std::map<char, std::vector<int> > partition_to_compare = j.give_pattern_partition();
        if (partition_map['A'].empty())
            num_parts -= 1;
        else
            if (((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                && (!partition_to_compare['A'].empty() )) ||
                ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                && (!partition_to_compare['C'].empty() )) ||
                ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                && (!partition_to_compare['G'].empty() )) ||
                (((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end())))
                && (!partition_to_compare['T'].empty() )))
                axpi += 1;
        if (partition_map['C'].empty())
            num_parts -= 1;
        else
            if (((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                 && (!partition_to_compare['A'].empty() )) ||
                ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                 && (!partition_to_compare['C'].empty() )) ||
                ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                 && (!partition_to_compare['G'].empty() )) ||
                (((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end())))
                && (!partition_to_compare['T'].empty() )))
                axpi += 1;
        if (partition_map['G'].empty())
            num_parts -= 1;
        else
            if (((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                 && (!partition_to_compare['A'].empty() )) ||
                ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                 && (!partition_to_compare['C'].empty() )) ||
                ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                 && (!partition_to_compare['G'].empty() )) ||
                (((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end())))
                && (!partition_to_compare['T'].empty() )))
                axpi += 1;
        if (partition_map['T'].empty())
            num_parts -= 1;
        else
            if (((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                 && (!partition_to_compare['A'].empty() )) ||
                ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                 && (!partition_to_compare['C'].empty() )) ||
                ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                 && (!partition_to_compare['G'].empty() )) ||
                (((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end())))
                && (!partition_to_compare['T'].empty() )))
                axpi += 1;
        std::cout << axpi << " " << num_parts << std::endl;
        axpi /= num_parts;
        return axpi;
    }
};

#endif
