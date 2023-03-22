#include "PartitionNumbers.h"
#include <iostream>

using namespace std;


void Partition::write()
/*
 * Writes found combinations on standard terminal output.
 */
{
    for (int i = 0; i < combination.size(); i++)
    {
        cout << combination[i];

        if (i != combination.size() - 1)
        {
            cout << "+";
        }
    }
    cout << endl;
}

bool Partition::isFirst(int k)
/*
 * Check if the passed argument is prime number.
 *
 * Arguments:
 *    k: number to check
 */
{
    if (k < 2)
        return false;

    for (int i = 2; i < k; i++)
    {
        if (k % i == 0)
        {
            if (i == k)
                return true;
            else
                return false;
        }
    }
    return true;
}

void Partition::findPrimes(int number)
/*
 * Finds all prime numbers to passed argument
 *
 * Arguments:
 *     number: Number to find the prime numbers
 */
{
    for (int i = 0; i <= number; i++)
    {
        if (isFirst(i))
        {
            primes.push_back(i);
        }
    }
}

int Partition::checkSum() // check sum of combination
/*
 * Checks sum of the combination. The sum can not be greater than the largest number in the division.
 */
{
    int sum = 0;

    for (int i : combination)
    {
        sum += i;
    }
    return sum;
}

int Partition::checkMin()
/*
 * Finds min index in combination container
 */
{
    int min = combination[0], idx = 0;

    for (int i = 0; i < combination.size(); i++)
    {
        if (min > combination[i])
        {
            min = combination[i];
            idx = i;
        }
    }
    return idx;
}

void Partition::end(int choose) // changing numbers to 2 from given index
/*
 * Checks edge case and changes all the words in combination to '2'.
 */
{

    for (int i = choose; i < combination.size(); i++)
    {

        combination[i] = primes[0];
    }
}

void Partition::addTwo(int n)
/*
 * Adding '2' to container untill sum + 2 <= n
 *
 * Arguments:
 *     n: Parameter to which sum is calculating
 */
{
    if (checkSum() + 2 <= n)
    {
        while (checkSum() < n && checkSum() + 1 <= n)
        {
            combination.push_back(primes[0]);
        }
    }
    else
        return;
}

void Partition::add(int n, int k)
/*
 * Add new numbers to the next words of the current partition.
 *
 * Arguments:
 *     n: number to divide
 *     k: first prime number in partition
 */
{
    int number = 0;

    if (combination[combination.size() - 1] < k)
    {
        for (int i = 0; i < primes.size(); i++) // assign higher prime number to first min number
        {
            if (primes[i] == combination[checkMin()])
            {
                number = primes[i + 1];
            }
        }

        combination[checkMin()] = number;

        if (combination.size() != 1 && combination[combination.size() - 1] != number)
        {
            end(checkMin());
        }

        if (checkSum() < n)
        {
            addTwo(n);
        }
    }
    else
    {
        return;
    }
}

void Partition::checkCombination(int n, int k)
/*
 * Checks combination of partition if it is correct. If correct writes on standard output, if not skip.
 */
{
    if (checkSum() > n && combination[combination.size() - 1] > n - k)
        return;

    if (checkSum() > n)
    {
        combination.pop_back();
        if (checkSum() == n)
            write();
        add(n, k);
        if (checkSum() > n && combination[combination.size() - 1] == primes[primes.size() - 1])
            return;
    }

    if (combination[combination.size() - 1] == primes[primes.size() - 1])
    {
        if (checkSum() == n)
        {
            write();
        }
        return;
    }

    if (checkSum() == n)
    {
        write();
        add(n, k);
    }
}

void Partition::mainAlgorithm(int n, int k)
/*
 * Main method in partitions. Checks many edge cases. Calculates next words in the partition.
 *
 * Arguments:
 *     n: number to divide
 *     k: max prime number in partitions
 */
{
    if (!isFirst(k)) // check if k is prime number
    {
        return;
    }

    combination.push_back(k);

    if (n == k)
    {
        write();
        return;
    }

    addTwo(n);

    if (checkSum() == n)
    {
        write();
        add(n, k);
        if (primes[primes.size() - 1] == 2)
            return;
    }

    while (combination.size() != 1)
    {
        if (checkSum() > n && combination[1] >= k && combination.size() < 3 ||
            checkSum() > n && combination[1] > n - k)
            return;

        if (checkSum() == n)
        {
            checkCombination(n, k);
        }

        if (combination.size() == 1)
        {
            checkCombination(n, k);
            return;
        }
        if (checkSum() > n)
        {
            checkCombination(n, k);
            if (checkSum() > n && checkMin() == 0)
                return;
            if (checkSum() > n && combination[checkMin() - 1] >= k && combination[checkMin()] > 3 && combination[
                                                                                                             checkMin() - 1] != k)
                return;
        }

        if (checkSum() < n)
        {
            add(n, k);

            checkCombination(n, k);
        }
        if (combination[combination.size() - 1] == k)
            return;
    }
}

void Partition::clearContainers()
{
    combination.clear();
    primes.clear();
}
