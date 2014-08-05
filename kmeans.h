//
//  kmeans.h
//  DAAD_project
//
//  Created by Paul Frandsen on 8/5/14.
//  Copyright (c) 2014 Paul Frandsen. All rights reserved.
//

#ifndef DAAD_project_kmeans_h
#define DAAD_project_kmeans_h

#include <map>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <numeric>

// This function will look at two vectors of doubles and see if they contain any pair
// that differs by more than 0.00001
bool close_enough(std::vector<double> first, std::vector<double> second)
{
    int length = first.size();
    int i;
    double difference;
    for (i = 0; i < length; ++i)
    {
        difference = fabs(first[i] - second[i]);
        if (fabs(first[i] - second[i]) > 0.00001)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> kmeans(std::vector<double> site_rates, int num_k)
{
    int site;
    int k;
    double random_number;
    int num_iterations = 0;
    std::vector<double> ks;
    std::map <int, std::vector<double> > centroid_map;
    std::vector<double> new_ks;
    double current_best = 1.0;
    double distance;
    int best_k = 1;
    
    std::vector<int> k_assigns;
    
    double sum;
    double mean;
    for (k = 0; k < num_k; ++k)
    {
        random_number = (std::rand()/(RAND_MAX + 1.0));
        if (random_number > 0.001)
        {
            new_ks.push_back(random_number);
            ks.push_back(1.0);
//            std::cout << "Here is your random number: " << random_number << std::endl;
            centroid_map[k];
        }
        else
            --k;
    }
    // Run this loop until centroids don't change, or until there is some maximum number of iterations
    while ((!close_enough(ks, new_ks)) && (num_iterations < 35))
    {
        // If the centroids do change, set the ks to the new_ks
        ks = new_ks;
        new_ks.clear();
        k_assigns.clear();
        for (site = 0; site < site_rates.size(); ++site)
        {
            for (k = 0; k < num_k; ++k)
            {
                distance = fabs(double(site_rates[site]) - ks[k]);
                if (distance < current_best)
                {
                    current_best = distance;
                    best_k = k;
                }
            }
            centroid_map[best_k].push_back(site_rates[site]);
            k_assigns.push_back(best_k);
            current_best = 1;
        }
        for (k = 0; k < num_k; ++k)
        {
            sum = std::accumulate(centroid_map[k].begin(),centroid_map[k].end(),0.0);
            mean = sum / centroid_map[k].size();
            new_ks.push_back(mean);
        }
        ++num_iterations;
        centroid_map.clear();
        for (k = 0; k < new_ks.size(); ++k)
        {
            std::cout << "Centroid " << (k + 1) << " is " << new_ks[k] << std::endl;
        }
    }
    for (k = 0; k < ks.size(); ++k)
    {
        std::cout << "Centroid " << (k + 1) << " is " << ks[k] << std::endl;
    }
    return k_assigns;
}


#endif
