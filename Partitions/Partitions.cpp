// PARTITIONS
// C++ Language
// Author: Michal Dudziak

#include <conio.h>
#include "PartitionNumbers.h"

int main()
{
    char button;

    while(true)
    {
        Partition partition;

        int l, iteration = 0;
        int n, k;

        vector<int> ns;
        vector<int> ks;

        cout << "The program called partitions.\n";
        cout << "Please type amount of single divisions: \n";

        cin >> l;

        cout << "List " << l << " partitions in format : n and k (eg. 7 3)\n";
        cout << "n - number to decompose\n";
        cout << "k - prime number at which to begin the split\n\n";

        while (iteration < l)
        {
            cin >> n >> k;

            if (n > 0 && k > 0)
            {
                ns.push_back(n);
                ks.push_back(k);
            }
            iteration++;
        }

        iteration = 0;

        while (iteration != l)
        {
            if (iteration > l)
                return 0;

            n = ns[iteration];

            k = ks[iteration];

            if (n > 1 && k > 1)
            {
                partition.findPrimes(k);

                partition.mainAlgorithm(n, k);

                partition.clearContainers();
            }

            iteration++;
        }

        cout << endl << endl;

        cout << "Press ENTER to make new partitions." << endl;
        cout << "If you want leave the program, please enter q." << endl;

        do
        {
            button = _getch();

        }while (button != 13 && button != 'q');

        if (button == 'q')
        {
            return 0;
        }
    }
}