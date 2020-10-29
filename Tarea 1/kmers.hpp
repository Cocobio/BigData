#ifndef KMERS
#define KMERS

static const int k_mers_Sigma_table[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3};

class k_mers {
private:
	size_t k;
	unsigned int* k_mers_building;

public:
	k_mers(size_t k) {
		this->k = k;

		k_mers_building = new unsigned int[k];
	}

	~k_mers() {
		delete[] k_mers_building;
	}

	void update(char nucleotide) {
		for (int i=0; i<k; i++)
			k_mers_building[i] = k_mers_building*4 + k_mers_Sigma_table[nucleotide];
	}

	unsigned int pop() {
		
	}
};

#endif