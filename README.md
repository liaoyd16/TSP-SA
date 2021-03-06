TSP-SA
-----------
TSP-SA is a program, written in C++, which (tries to) solve the Travelling Salesman Problem, aka TSP.

TSP is regarded as 'The Holy Grail of Computer Science'. The problem consists of a certain number of cities and the task is the find the shortest Hamiltonian Cycle, connecting all the cities.

The algorithm used here is Simulated Annealing, aka SA. SA is a randomized algorithm and hence may not give the same output for the same input at successive executions. This is an anytime algorithm and hence it would find better and better solutions the more time it keeps running.

Executing the program
--------------------------------
The program has been tested successfully for an input of at most 500 cities. The user may terminate the algorithm any time he/she desires.

To generate the executable, type 'make' at the terminal. An executable 'tsp-sa' gets created.

To run the executable, type 'executable-name < input-file-name'.
For example, './tsp-sa < reuc_250'.

Some sample input files are available in the folder 'sample-input-files'. The input files have been created from TSPLIB (http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/).

This was developed as part of my assignment in course CS6380 - Artificial Intelligence, IIT Madras under the guidance of Prof. Deepak Khemani.
