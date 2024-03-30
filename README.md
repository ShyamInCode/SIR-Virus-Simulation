
# SIR Virus Simulation

**SIR Virus Simulation** is a C language project that models the spread of an infectious disease within a population. The model divides individuals into three categories:

1. **Susceptible (S)**: Individuals who are at risk of contracting the disease.
2. **Infectious (I)**: Individuals who are currently infected and can transmit the disease.
3. **Recovered (R)**: Individuals who have recovered from the disease and are no longer infectious.

## Overview

The simulation uses differential equations to describe how people transition between these categories over time. Key parameters include the infection rate, recovery rate, and initial conditions.

## Implementation Outline

To implement the SIR model in C, follow this outline:

1. **Define Person Structure**:
   - Create a structure to represent an individual. Include fields such as:
     - `id`: Unique identifier for each person.
     - `state`: Current state (S, I, or R).
     - `infection_time`: Time when the person was infected.
     - `recovery_time`: Time when the person recovered.

2. **Graph Representation**:
   - Define a structure to represent the population as a graph.
   - Fields for the graph structure:
     - `num_nodes`: Total number of individuals.
     - `num_edges`: Number of connections between individuals.
     - `adjacency_list`: Store connections between people (e.g., using a linked list).

3. **Initialize the Graph**:
   - Create a function to initialize the graph with random values:
     - Randomly set the number of nodes and edges.
     - Assign initial states (S, I, or R) to individuals.
     - Populate the adjacency list.

4. **Update Person States**:
   - Implement a function to update the state of each person based on the SIR model equations:
     - Calculate new infections and recoveries.
     - Use a priority queue to track infectious individuals sorted by recovery time.
     - Use a stack to store recovered individuals for later analysis.

5. **Simulate the Epidemic**:
   - Create a function to simulate the epidemic over a given timeframe:
     - Repeatedly call the update function.
     - Collect data (e.g., number of people in each state at each time step).
     - Identify the peak of the epidemic and final outcomes.

## Usage

Compile your C code and run the simulation. You can visualize the results through print statements or by plotting graphs.

