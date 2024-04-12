#include <bits/stdc++.h>
using namespace std;

// Single simulation of the Monty Hall problem
pair<bool, bool> montyHallSimulation(int numDoors, int numOpenedByHost)
{
    vector<bool> doors(numDoors, false); // initially all doors are closed (true = open, false = closed)

    // Randomly place the prize behind one of the doors
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(0, numDoors - 1);
    int prizeDoor = dist(gen);

    // Contestant randomly chooses a door
    int initialChoice = dist(gen);

    // Host opens numOpenedByHost doors that don't contain the prize and weren't initially chosen by the contestant
    vector<int> doorsToOpen;
    for (int i = 0; i < numDoors; ++i)
    {
        if (i != prizeDoor && i != initialChoice)
        {
            doorsToOpen.push_back(i);
        }
    }
    shuffle(doorsToOpen.begin(), doorsToOpen.end(), gen);
    for (int i = 0; i < numOpenedByHost && i < doorsToOpen.size(); ++i)
    {
        doors[doorsToOpen[i]] = true; // Open door
    }

    // Contestant makes final choice
    int finalChoice = -1;
    for (int i = 0; i < numDoors; ++i)
    {
        if (i != initialChoice && !doors[i])
        {
            finalChoice = i;
            break;
        }
    }

    // Determine if the contestant wins by sticking with the initial choice and by switching doors
    bool winStick = initialChoice == prizeDoor;
    bool winSwitch = finalChoice == prizeDoor;

    return make_pair(winStick, winSwitch);
}

int main(int argc, char *argv[])
{
    // Parse command line arguments
    if (argc != 7)
    {
        cerr << "Usage: " << argv[0] << " --num_doors <num_doors> --num_doors_opened_by_host <num_doors_opened_by_host> --num_simulations <num_simulations>" << endl;
        return 1;
    }

    int numDoors, numDoorsOpenedByHost, numSimulations;
    for (int i = 1; i < argc; i += 2)
    {
        string arg = argv[i];
        if (arg == "--num_doors")
        {
            numDoors = stoi(argv[i + 1]);
        }
        else if (arg == "--num_doors_opened_by_host")
        {
            numDoorsOpenedByHost = stoi(argv[i + 1]);
        }
        else if (arg == "--num_simulations")
        {
            numSimulations = stoi(argv[i + 1]);
        }
        else
        {
            cerr << "Invalid argument: " << arg << endl;
            return 1;
        }
    }

    // Run simulations
    int totalWinsStick = 0;
    int totalWinsSwitch = 0;
    for (int i = 0; i < numSimulations; ++i)
    {
        auto results = montyHallSimulation(numDoors, numDoorsOpenedByHost);
        totalWinsStick += results.first;
        totalWinsSwitch += results.second;
    }

    // Calculate win percentages
    double winPercentStick = static_cast<double>(totalWinsStick) / numSimulations * 100;
    double winPercentSwitch = static_cast<double>(totalWinsSwitch) / numSimulations * 100;
    cout << "Win percentage by sticking with initial choice: " << winPercentStick << "%" << endl;
    cout << "Win percentage by switching doors: " << winPercentSwitch << "%" << endl;

    return 0;
}