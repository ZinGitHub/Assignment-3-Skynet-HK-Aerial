#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
	// Changes the color of the background black and the text color green.
	system("color 0A");
	// Chnages the name of the program to Skynet HK-Aerial.
	system("title Skynet HK-Aerial");
	cout << "Generate Random enemy location on 8x8 grid..." << endl;
	srand(time(0));
	// Declares that 64 is the largest number in the grid. (in the beginning of the program.)
	int searchGridHighNumber = 64;
	// Declares that 1 is the smallest number in the grid. (in the beginning of the program.)
	int searchGridLowNumber = 1;
	// Randomizing the enemy location for simulation purposes.
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;
	cout << "The enemy is located at location a " << enemyLocation << " On 8x8 grid with 1-64 sectors." << endl;

	// This block of code displays the initialization of the program.
	cout << "Skynet HK-Aerial Initializing software....." << endl;
	int targetLocationPredictionCounter = 0;
	bool targetFound = false;

	// A while statement running until the target is found.
	while (targetFound == false)
	{
		// Algorithm code used to find our target through binary search.
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		targetLocationPredictionCounter++;
		// Dividing ping, location, and searchGridHighNumber statements.
		cout << "=============================================================" << endl;
		// Stating that a ping is being sent out.
		cout << "Skynet HK-Aerial Radar sending out ping #" << targetLocationPredictionCounter << endl;

		// A if statement for when the number of location predicted is greater than the number that corresponds to the enemy location.
		if (targetLocationPrediction > enemyLocation)
		{
			// Replaces the previous searchGridHighNumber with a newer searchGridHighNumber. (any number greater than or equal to the previous seearchGridHighNumber are locations that the target is not found.)
			searchGridHighNumber = targetLocationPrediction - 1;
			// Displays the result of the number of location predicted being greater than the number correlating to the enemy location.
			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual enemy location of " << enemyLocation << "." << endl;
			// Displays the newer searchGridHighNumber.
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;
		}
		// A else if statement for when the number corresponding to the enemy location is greater than the number of the location predicted.
		else if (targetLocationPrediction < enemyLocation)
		{
			// State's the location of the enemy.
			cout << "Enemy was hiding in location a " << enemyLocation << endl;
			// State's the location of the target. (If this cout statement is displayed then TARGET IS NO LONGER A THREAT.)
			cout << "Target was found at location a " << enemyLocation << endl;
			// Informs the user how many ping predictions it took to locate enemy/target.
			cout << "Skynet HK-Aerial Software took " << targetLocationPredictionCounter << " predictions to find the enemy location on a grid zise of 8x8 (64)." << endl;
			targetFound = true;
		}
		else
		{
			// Notifies the user that the drone has an error and should return back to base for inspection.
			cout << "Drone malfunction!" << endl;
			cout << "Send drone for Software Diagnostics!" << endl;
			targetFound = true;
		}
		system("pause");
	}
}