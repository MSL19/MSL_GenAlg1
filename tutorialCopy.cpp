#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
#define CROSSOVER_RATE            0.7
#define MUTATION_RATE             0.001
#defin POP_SIZE                  100			//must be an even number
#define CHROMO_LENGTH             300
#define GENE_LENGTH               4
#define MAX_ALLOWABLE_GENERATIONS	10000

//returns a float between 0 & 1
#define RANDOM_NUM		((float)rand()/(RAND_MAX+1))

struct chromo_type
{
	string bits;
	float fitness;
	chromo_type() : bits(""), fitnes(0.0f) {};
	chromo_type(string bts, float ftns): bits(bts), fitness(ftns){]}
};

void PrintGeneSymbol(int val);
string GetRandomBits(int length);
int BinToDEc(string bits);
float AssignFitness(string bits, int target_value);
void PrintChromo(string bits);
void PrintGeneSymbol(int val);
int ParseBits(string bits, int* buffer);
string Roulette(int total_fitness, chomo_typ* Population);
void Mutate(string &bits);
void Crossover(string &offspring1, string &offspring2);

int main() {

	srand((int)time(NULL));
	while (true) {
		chomo_typ Population[POP_SIZE];
		float Target;
		cout << "\nInput a target number you dummy: ";
		cin >> Target;
		cout << endl << endl;
		
		for (int i = 0; i < POP_SIZE; i++) {
			Population[i].bits = GetRandomBits(CHOMO_LENGTH);
			Population[i].fitness = 0.0f;
		}
		int GenerationsRequiredToFindASolution = 0;

		bool bFound = false;

		while (!bFound) {
			float TotalFitness = 0.0f;

			for (int i = 0; i < POP_SIZE; i++) {
				Population[i].fitness = AssignFitness(Population[i].bits, Target);
				TotalFitness += Population[i].fitness;
			}

			for (int i = 0; i < POP_SIZE; i++) {
				if (Population[i].fitness == 999.0f) {
					cout << "\nSolution found in " << GernationsRequiredToFindASolution << "adsadsadasdasdasdasdsad" << endl << endl;;
					PrintChomo(Population[i].bits);
					bFound = true;
					break;
				}
			}

			chromo_tyo temp[POP_SIZE];
			int cPop = 0;
			while (cPop < POP_SIZE) {
				string offspring1 = Roulette(TotalFitness, Population);
				string offspring2 = Roulette(TotalFitness, Population);

				Crossover(offspring1, offspring2);

				Mutate(offspring1);
				Mutate(offspring2);

				temp[cPop++] = chromo_typ(offspring1, 0.0f);
				temp[cPop++] = chromo_typ(offspring2, 0.0f);

			}

			for (int i = 0; i < POPS = _SIZE; i++) {
				Population[i] = temp[i];
			}//i'm tired
		}
	}
}