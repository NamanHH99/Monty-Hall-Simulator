# Monty Hall Problem Simulator

This is a C++ program that simulates the Monty Hall Problem. It allows for the simulation of scenarios with a variable number of doors and doors opened by the host.

## Prerequisites

- C++ compiler (supporting C++11 or later)
- Git (optional, for cloning the repository)

## How to Run

1. Clone the repository:

    ```bash
    git clone https://github.com/NamanHH99/Monty-Hall-Simulator.git
    ```

    Alternatively, you can download the source code as a ZIP archive and extract it.

2. Navigate to the repository directory:

    ```bash
    cd monty-hall-simulator
    ```

3. Compile the program using a C++ compiler. For example, using g++:

    ```bash
    g++ -std=c++11 montyhall.cpp -o montyhall
    ```

4. Run the program with the desired command-line arguments:

    ```bash
    ./montyhall --num_doors <num_doors> --num_doors_opened_by_host <num_doors_opened_by_host> --num_simulations <num_simulations>
    ```

    Replace `<num_doors>`, `<num_doors_opened_by_host>`, and `<num_simulations>` with appropriate values.

    Example:

    ```bash
    ./montyhall --num_doors 3 --num_doors_opened_by_host 1 --num_simulations 10000
    ```

    This would simulate the Monty Hall problem with 3 doors, where the host opens 1 door, and perform 10,000 simulations.

## Command-Line Arguments

- `--num_doors`: Specifies the total number of doors in the simulation.
- `--num_doors_opened_by_host`: Spec
