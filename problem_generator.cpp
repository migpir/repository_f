//============================================================================
// Name        : problem_generator.cpp
// Author      : Miguel H. Peralta
// Version     :
// Copyright   : GNU license
// Description : Generates a binary multiplicatin problem
//             : from the range 1..12
//============================================================================

// mersenne_twister_engine::seed example
#include <iostream>
#include <chrono>
#include <random>

using namespace std;


int  random_problem(int &fact1, int &fact2,unsigned &seed);

int random_problem(int &fact1, int &fact2,unsigned &seed)
{



    mt19937_64 generator (seed);   // mt19937 is a standard mersenne_twister_engine

    fact1 = generator()%12 + 1;
    fact2 = generator()%12 + 1;

    return 0;
}


int main ()
{

    auto t0 = chrono::steady_clock::now();
    auto t1 = chrono::steady_clock::now();
    auto delta_t= t1 - t0;

	int i,factor_1=0;
	int factor_2=0;
	unsigned seed;

    cout << "Press ENTER key to start ";
	while (cin.get() != '\n')
	  {
  	   // Wait for ENTER key to be pressed.
	   // while you're waiting, calculate a random delta_t value.
	   // We'll use this value as a random seed below.
       delta_t = t1 - t0;
	  }
	//
	// Open a file to write  data to
	//

    //
	// Do ten problems
    //
	for(i=1;i<10;i++){

		// Use delta_t as a seed for the mersenne engine

	    seed = chrono::duration <double, milli> (delta_t).count();

	(random_problem(factor_1,factor_2,seed));


    //*************************************************
    //
	// Set t0 to current clock time.
    //
    //*************************************************
    //
    t0 = chrono::steady_clock::now();
    //
    // Display math problem
    //
    cout <<factor_1<<" x "<<factor_2<<" = "<< endl;

    //*************************************************
    //
	// Ask the student to start by pressing ENTER key
    //
    //*************************************************
    cout << "Press the ENTER key after entering your answer.";
    //
    // Wait for the ENTER key only.
    //
	while (cin.get() != '\n')
	  {
  	   // t1 is incrementing since chrono::steady_clock is a linear clock(i.e monotonic)
	  }

	  // If we are here,  then the while loop condition failed to be
	  // satisfied (i.e. ENTER key was pressed).
	  // Time to calculate delta_t = t1 - t0
      //
 	  delta_t = chrono::steady_clock::now() - t0;

	  cout << "*************************************************************"<< endl;
      //  cout << chrono::duration <double, nano> (delta_t).count() << " ns"     << endl;
	  cout << chrono::duration <double, milli> (delta_t).count()/1000 << " seconds"<< endl;
	  cout << "*************************************************************"<< endl;

	  // Store data in csv file with values separated with commas:
	  // multiplicand,multiplier,product,delta
	}

	// Close csv data file
	return 0;
}
