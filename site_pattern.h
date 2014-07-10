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
    double calculate_pa(SitePattern & j)
    {
        double axpi = 0;
        double pa;
        int num_parts = 4;
        std::map<char, std::vector<int> > partition_to_compare = j.give_pattern_partition();
        // do a whole bunch of set comparisons, to see if any of the sets in the site pattern object are subsets of the
        // sets in the site pattern reference that is fed into the function. I use the "include" function to do this.
        // If the set is empty, then I move onto the next set.
        if (partition_map['A'].empty())
            num_parts -= 1;
        else
        {
//            std::cout << "Trying A..." << std::endl;
            if ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                && (!partition_to_compare['A'].empty() ))
            {
                axpi += 1;
//                std::cout << "A to A." << std::endl;
            }

            else if ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                     && (!partition_to_compare['C'].empty() ))
            {
                axpi += 1;
//                std::cout << "A to C." << std::endl;
            }

            else if ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                     && (!partition_to_compare['G'].empty() ))
            {
                axpi += 1;
//                std::cout << "A to G." << std::endl;
            }

            else if ((std::includes(partition_map['A'].begin(), partition_map['A'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end()))
                     && (!partition_to_compare['T'].empty() ))
            {
                axpi += 1;
//                std::cout << "A to T." << std::endl;
            }

        }
        if (partition_map['C'].empty())
            num_parts -= 1;
        else
        {
//            std::cout << "Trying C..." << std::endl;
            if ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                && (!partition_to_compare['A'].empty() ))
            {
                axpi += 1;
//                std::cout << "C to A." << std::endl;
            }

            else if ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                     && (!partition_to_compare['C'].empty() ))
            {
                axpi += 1;
//                std::cout << "C to C." << std::endl;
            }

            else if ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                     && (!partition_to_compare['G'].empty() ))
            {
                axpi += 1;
//                std::cout << "C to G." << std::endl;
            }

            else if ((std::includes(partition_map['C'].begin(), partition_map['C'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end()))
                     && (!partition_to_compare['T'].empty() ))
            {
                axpi += 1;
//                std::cout << "C to T." << std::endl;
            }

        }
        if (partition_map['G'].empty())
            num_parts -= 1;
        else
        {
//            std::cout << "Trying G..." << std::endl;
            if ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                 && (!partition_to_compare['A'].empty() ))
            {
                axpi += 1;
//                std::cout << "G to A." << std::endl;
            }

            else if ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                 && (!partition_to_compare['C'].empty() ))
            {
                axpi += 1;
//                std::cout << "G to C." << std::endl;
            }

            else if ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                 && (!partition_to_compare['G'].empty() ))
            {
                axpi += 1;
//                std::cout << "G to G." << std::endl;
            }

            else if ((std::includes(partition_map['G'].begin(), partition_map['G'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end()))
                && (!partition_to_compare['T'].empty() ))
            {
                axpi += 1;
//                std::cout << "G to T." << std::endl;
            }
        }
        if (partition_map['T'].empty())
            num_parts -= 1;
        else
        {
//            std::cout << "Trying T..." << std::endl;
            if ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['A'].begin(), partition_to_compare['A'].end()))
                && (!partition_to_compare['A'].empty() ))
            {
                axpi += 1;
//                std::cout << "T to A." << std::endl;
            }

            else if ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['C'].begin(), partition_to_compare['C'].end()))
                     && (!partition_to_compare['C'].empty() ))
            {
                axpi += 1;
//                std::cout << "T to C." << std::endl;
            }

            else if ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['G'].begin(), partition_to_compare['G'].end()))
                     && (!partition_to_compare['G'].empty() ))
            {
                axpi += 1;
//                std::cout << "T to G." << std::endl;
            }

            else if ((std::includes(partition_map['T'].begin(), partition_map['T'].end(), partition_to_compare['T'].begin(), partition_to_compare['T'].end()))
                     && (!partition_to_compare['T'].empty() ))
            {
                axpi += 1;
//                std::cout << "T to T." << std::endl;
            }

        }
//        std::cout << axpi << " " << num_parts << std::endl;
        pa = axpi/num_parts;
        return pa;
    }
};

#endif
