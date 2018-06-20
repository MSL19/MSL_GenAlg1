#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
#define CROSSOVER_RATE            0.7
#define MUTATION_RATE             0.001
#define POP_SIZE                  100			//must be an even number
#define CHROMO_LENGTH             300
#define GENE_LENGTH               4
#define MAX_ALLOWABLE_GENERATIONS	10000

//returns a float between 0 & 1
#define RANDOM_NUM		((float)rand()/(RAND_MAX+1))

struct chromo_type
{
	string bits;
	float fitness;
	chromo_typ() : bits(""), fitnes(0.0f) {};
	chromo_typ(string bts, float ftns) : bits(bts), fitness(ftns) {};
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
			++GenerationsRequiredToFindASolution;

			if (GenerationsRequiredToFindASolution > MAX_ALLOWABLE_GENERATIONS) {
				COUT << "no SOLUTIONS FOUND THIS RUN";
				bFound = true;
			}
		}

		cout << "\n\n\n";

	}
	return 0;

}


string GetRandomBits(int length) {
	string bits;

	for (int i = 0; i < length; i++) {
		if (RANDOM_NUM > 0.5f)bits += "1";
		else bits += "0";
	}
	return bits;
}

int BinToDec(string bits) {
	int val = 0;
	int value_to_add = 1;

	for (int i = bits.length(); i > 0; i--) {
		if (bits.at(i - 1) == '1') val += value_to_add;
		value_to_add *= 2;
	}
	return val;
}

int ParseBits(string bits, int*buffer) {

	int cBuff = 0;
	bool bOperator = true;

	int this_gene = 0;

	for (int i = 0; i < CHROMO_LENGTH; i += GENE_LENGTH) {

		this_gene = BinToDec(bits.substr(i, GENE_LENGTH));

		if (bOperator) {

			if ((this_gene < 10) || (this_gene > 13)) continue;

			else {
				bOperator = false;
				buffer[cBuff++] = this_gene;
				continue;
			}
		}

		else {
			if (this_gene > 9) continue;
			else {
				bOperator = true;
				buffer[cBuff++] = this_gene;
				continue;
			}
		}
	}

	for (int i = 0; i < cBuff; i++) {
		if ((buffer[i] == 13) && (buffer[i + 1]) == 0)) buffer[i] = 10;
		
	}
	return cBuff;
}

float AssuignFitness(string bits, int target_value) {

	int buffer[(int)(CHROMO_LENGTH / GENE_LENGTH)];
	int num_elements = ParseBits(bits, buffer);

	float result = 0.0f;
	for (int i = 0; i < num_elements - 1; i += 2) {

		switch (buffer[i]) {

		case 10:
			result += buffer[i + 1];
			break

		case 11:

			result -= buffer[i + 1];
			break;

		case 12: 
			result *= buffer[i + 1];

			break;

		case 13:
			result /= buffer[i + 1];
			break;
		}
	 }

	if (result == (float)target_value) return 999.0f;
	else return 1 / (float)fabs((double)(target_value - result));
}

void PrintChromo(string bits) {

	int buffer[(int)(CHROMO_LENGTH / GENE_LENGTH)];

	int num_elements = ParseBits(bits, buffer);

	for (int i = 0; i < num_elements, i++) {
		PrintGeneSymbol(buffer[i]);
	}
	return;
}

void PrintGeneSymbol(int val)
{
	if (val < 10)

		cout << val << " ";

	else
	{
		switch (val)
		{

		case 10:

			cout << "+";
			break;

		case 11:

			cout << "-";
			break;

		case 12:

			cout << "*";
			break;

		case 13:

			cout << "/";
			break;

		}//end switch

		cout << " ";
	}

	return;
}

void Mutate(string &bits) {
	for (int i = 0; i < bits.length(); i++) {
		if (RANDOM_NUM < MUTATION_RATE) {
			if (bits.at(i) == '1') bits.at(i) = '0';
			else bits.at(i) = '1';
		}
	}
	return;
}

void Crossover(string &offspring1, string &offspring2) {

	if (RANDOM_NUM < CROSSOVER_RATE) {
		int crossover = (int)(RANDOM_NUM*CHROMO_LENGTH);
		string t1 = offspring1.substr(0, crossover) + offspring2.substr(crossover, CHROMO_LENGTH);
		string t2 = offspring2.substr(0, crossover) + offspring1.substr(crossover, CHROMO_LENGTH);

		offspring1 = t1; offspring2 = t2;
	}
}

string roulette(int total_fitness, chromo_type*Population) {

	float Slive = (float)(RANDOM_NUM*total_fitness);
	float FitnessSoFar = 0.0f;

	for (int i = 0; i < POP_SIZE; i++) {
		FitnessSoFar += Population[i].fitness;

		if (FitnessSoFar >= Slice) return Population[i].bits;
	}
	return "";
}