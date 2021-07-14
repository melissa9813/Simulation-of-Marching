# Simulation-of-Marching
#### HK PolyU COMP1011 Assignment 2 (2020/21 Semester 2)
#### Please watch the video (https://youtu.be/HExgC4qHsQI) to see the result

### Background
Marching is a part of military training that requires military troops to move forward in a
uniformed and steady manner. In this assignment, you are going to write a C++ program that
simulates the marching process.

### Initial Setting
There are totally 60 soldiers standing in 6 rows. The symbol ‘>’ represents a soldier. The soldiers have to march forward until all pass the finish line. The initial output of the program MUST look like below (Note the dimension of the map):
![image](https://user-images.githubusercontent.com/59997186/125657409-4a8d2a7c-fa3d-41df-ae0f-5ebd8d09c566.png)

### Stage 1
Prior to the training to new soldiers, the senior soldiers demonstrate how marching can properly be performed. Below are the rules of the simulation:
1. Each soldier can only move forward towards the finish line.
2. For each round, each soldier can move 1 step forward. An updated map should be displayed. The program then waits for a ‘y’ or ‘Y’ user input to proceed to the next round.
3. If a soldier has reached the “FINISH” line, the represented ‘>’ should disappear from the map.
4. If all soldiers have reached the “FINISH” line, the simulation is finished. “Finished” should be printed below the map and the program terminates.

Sample outputs:
![image](https://user-images.githubusercontent.com/59997186/125657500-3608232d-ed02-437b-a71e-4494a00c8678.png)


### Stage 2
All the new soldiers are novice in marching and cannot synchronize the marching rhythm of the whole unit. Each soldier moves forward in a number of steps randomly. Here are the rules of the simulation:
1. Each soldier can only move forward towards the finish line.
2. For each round, each soldier can move 1, 2 or 3 steps forward randomly. Those standing on the front-most move forward first, and then the second row move forward and so on.
3. If a soldier, say A, is going to move to a position in which there is another soldier, say B, or move beyond B, A is not able to so do and must stop and stand behind B.
4. If a soldier has reached or passed beyond the “FINISH” line, the represented ‘>’ should disappear from the screen.
5. If all soldiers have reached or passed beyond the “FINISH” line, the simulation is finished. “Finished” should be printed below the map and the program terminates.

Sample outputs:
![image](https://user-images.githubusercontent.com/59997186/125657750-cd8af439-394c-4754-8a8b-74b83c71cacf.png)


### Stage 3
After intensive training, the new soldiers are now able to synchronize the marching rhythm.
Besides, they are able to perform variations of marching based on the following commands:
1. A steady march (i.e., Stage 1) with the number of steps for each round specified.
2. A random march (i.e., Stage 2) with the maximum number of steps for each round specified.
3. A formation of either 6 rows, 10 rows or 15 rows. You should properly design the prompts for the inputs from user for the initialization of the map and subsequent processing for the simulation.

When the completed program starts, it first provides a menu and allows the user to select Stage 1, 2 or 3 for the simulation. For Stages 1 and 2, no parameters are needed from the user, while for Stage 3, it requires the user to input the type of march, the (maximum) number of steps and the number of rows for the formation._


