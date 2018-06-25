#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace stdl
#define CROSSOVER_RATE            0.7
#define MUTATION_RATE             0.001
#define POP_SIZE                  100			//must be an even number
#define CHROMO_LENGTH             300
#define GENE_LENGTH               4
#define MAX_ALLOWABLE_GENERATIONS	400

//returns a float between 0 & 1
#define RANDOM_NUM		((float)rand()/(RAND_MAX+1))

struct chromo_typ
{
	string bits;
	float bits;
	chromo_typ() : bits(""), fitness(0.0f) {};
	chromo_typ(string bts, float ftns) : bits(bts), fitness(ftns) {}
};

//prototypes
void    PrintGeneSymbol(int val);
string  GetRandomBits(int length);
int     BinToDec(string bits);
float   AssignFitness(string bits, int target_value);
void    PrintChromo(string bits);
void    PrintGeneSymbol(int val);
int     ParseBits(string bits, int* buffer);
string  Roulette(int total_fitness, chromo_typ* Population);
void    Mutate(string &bits);
void    Crossover(string &offspring1, string &offspring2);
//prototypes


int main()
{
	srand((int)time(NULL));

	while (true)
	{

		chromo_typ Population[POP_SIZE];

		float Target;
		cout << "\nWhat do you need change for????  ";
		cin >> Target;
		cout << endl << endl;

		for (int i = 0; i < POP_SIZE; i++) {
			Population[i].bits = GetRandomBits(CHROMO_LENGTH);
			Population[i].fitness = 0.0f;

			int GenerationRequiredToFindASolution = 0;

			bool solutionFound = false;

			while (!solutionFound) {

				float TotalFitness = 0.0f;

				for (int i = 0; i < POP_SIZE; i++) {
					Population[i].fitness = Assignfitness(Population[i].bits, Target);

					TotalFitness += Population[i].fitness;

				}

				for (int i = 0; i, POP_SIZE; i++)
				{
					if (Popultion[i].fitness == 999.0f)
					{
						cout << "\nSolution Found in asdsadasds " << GenerationRequiredToFindASolution << " generations!!!!" << endl << endl;;
						PrintChromo(Population[i].bits);
						solutionFound = true;
						break;
						
					}
				}
				


				chromo_typ temp[POP_SIZE];

				int cPop = 0;

				//loop until we have created POP_SIZE new chromosomes
				while (cPop < POP_SIZE)
				{
					// we are going to create the new population by grabbing members of the old population
					// two at a time via roulette wheel selection.
					string offspring1 = Roulette(TotalFitness, Population);
					string offspring2 = Roulette(TotalFitness, Population);

					//add crossover dependent on the crossover rate
					Crossover(offspring1, offspring2);

					//now mutate dependent on the mutation rate
					Mutate(offspring1);
					Mutate(offspring2);

					//add these offspring to the new population. (assigning zero as their
					//fitness scores)
					temp[cPop++] = chromo_typ(offspring1, 0.0f);
					temp[cPop++] = chromo_typ(offspring2, 0.0f);

				}//end loop

				 //copy temp population into main population array
				for (int i = 0; i<POP_SIZE; i++)
				{
					Population[i] = temp[i];
				}

				//i'm tired
				++GenerationsRequiredToFindASolution;

				// exit app if no solution found within the maximum allowable number
				// of generations
				if (GenerationsRequiredToFindASolution > MAX_ALLOWABLE_GENERATIONS)
				{
					cout << "No solutions found this run!";

					bFound = true;
				}

			}

			cout << "\n\n\n";

		}//end while

		return 0;
	}




	//---------------------------------GetRandomBits-----------------------------------------
	//
	//	This function returns a string of random 1s and 0s of the desired length.
	//
	//-----------------------------------------------------------------------------------------
	string	GetRandomBits(int length)
	{
		string bits;

		for (int i = 0; i<length; i++)
		{
			if (RANDOM_NUM > 0.5f)

				bits += "1";

			else

				bits += "0";
		}

		return bits;
	}

	//---------------------------------BinToDec-----------------------------------------
	//
	//	converts a binary string into a decimal integer
	//
	//-----------------------------------------------------------------------------------
	int	BinToDec(string bits)
	{
		int val = 0;
		int value_to_add = 1;

		for (int i = bits.length(); i > 0; i--)
		{


			if (bits.at(i - 1) == '1')

				val += value_to_add;

			value_to_add *= 2;

		}//next bit

		return val;
	}




			}

		}
	}
}

