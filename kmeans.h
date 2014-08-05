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
            ks.push_back(random_number);
            std::cout << "Here is your random number: " << random_number << std::endl;
            centroid_map[k];
        }
        else
            --k;
    }
    while ((!(ks == new_ks)) && (num_iterations < 5))
    {
        ks = new_ks;
        k_assigns.clear();
        for (site = 0; site < site_rates.size(); ++site)
        {
            std::cout << "On site number " << site << std::endl;
            for (k = 0; k < num_k; ++k)
            {
                std::cout << "Calculating distance..." << std::endl;
                distance = abs(site_rates[site] - ks[k]);
                if (distance < current_best)
                {
                    current_best = distance;
                    best_k = k;
                }
            }
            std::cout << "Best k is: " << best_k << std::endl;
            centroid_map[best_k].push_back(site_rates[site]);
            k_assigns.push_back(best_k);
        }
        std::cout << "Calculating new centroids..." << std::endl;
        for (k = 0; k < num_k; ++k)
        {
            sum = std::accumulate(centroid_map[k].begin(),centroid_map[k].end(),0.0);
            mean = sum / centroid_map[k].size();
            new_ks.push_back(mean);
            std::cout << "New centroid numba " << k << ": " << mean << std::endl;
        }
        std::cout << "Finished iteration: " << num_iterations << std::endl;
        ++num_iterations;
        centroid_map.clear();
        std::cout << "Current cluster assignments..." << std::endl;
        copy(k_assigns.begin(), k_assigns.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << std::endl;
    }
    return k_assigns;
}


#endif
