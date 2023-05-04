#ifndef PROJECTS_PARTITIONS_H
#define PROJECTS_PARTITIONS_H
#include <vector>
#include <iostream>

using namespace std;

class PartitionAlgorithm
{
private:
    vector<int> primes;
    vector<int> combination;


public:
    void write();

    bool isFirst(int k);

    void findPrimes(int number);

    int checkSum();

    int checkMin();

    void end(int choose);

    void addTwo(int n);

    void add(int n, int k);

    void checkCombination(int n, int k);

    void mainAlgorithm(int n, int k);

    void clearContainers();
};

#endif
