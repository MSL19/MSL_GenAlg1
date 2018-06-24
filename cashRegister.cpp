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
					if()
				}
				
			}

		}
	}
}

