daad
====
This software will calculate the TIGER site rates (http://dx.doi.org/10.1093/sysbio/syr064) for a multiple sequence alignment.

The software has only been tested and compiled on a MAC using the clang++ compiler. It is recommended that you use clang++ to ensure that the software compiles successfully. The easiest way to do this is by downloading XCODE.

To compile, download this repo and navigate to the "DAAD_project" directory and compile the program by typing the command "clang++ -o rates_calculator main.cpp". After this, you should have a new binary called "rates_calculator" in your directory.

The program works with phylip alignments. For an alignment called "alignment.phy", type the command "./rates_calculator dna alignment.phy" to run the program. The program will output a file called "alignment.phy_r8s.txt" that contains the rates for each site separated by line breaks.

