// Class to keep track of tour so far
class Tour {
public:
	// Used to initialize new tours. 
	Tour() : mileage(0) { 
		cities.push_back(0); 
	}

	// Used to initialize best tour. Set to a high
	// cost so that the first complete tour will become
	// the new "best."
	Tour(unsigned int cost) : mileage(cost) { }

	//Reset tour
	auto clear() {
		cities.clear();
		cities.push_back(0);
		mileage = 0;
	}

	auto get_num_cities() { 
		return cities.size(); 
	}

	// Returns True if City c is in the tour
	auto is_present(unsigned int c) {
		return (find(cities.begin(), cities.end(), c) != cities.end());
	}

	// Returns True if this tour is better than Tour t
	auto better_than(const Tour& t) { 
		return (mileage < t.mileage); 
	}

	// Compute change in mileage if City c is added to the list
	auto mileage_delta(unsigned int c) {
		unsigned int last = cities.back(); // current last city
		unsigned int test_mileage = mileage_table[last][c];

		// If this would be our last city, add the mileage
		// to return home
		if (cities.size() + 1 == num_cities) {
			test_mileage += mileage_table[c][0];
		}
		return test_mileage;
	}


	// Add city unconditionally (without checking anything) 
	auto add_city(unsigned int c) {
		mileage += mileage_delta(c);
		cities.push_back(c);
	}

	// Add city conditionally
	// Check to make sure that (a) it is not already present
	// and (b) it would not lead to a tour that is worse
	// than the best tour so far
	// Return True if city was added
	auto add_city(unsigned int c, const Tour& best_so_far) {
		// If city is already in the list, return false
		if (is_present(c)) {
			return false;
		}
		// If this would be worse than our best completed tour,
		// return false
		if (mileage + mileage_delta(c) > best_so_far.mileage) {
			return false;
		}
		add_city(c);
		return true;
	}

	// Delete the last city
	auto remove_last() {
		unsigned int c = cities.back();
		cities.pop_back();

		// Subtract the mileage that c added to the cost
		mileage -= mileage_delta(c);
	}

	// Output operator: print cost and list of names
	friend auto& operator << (ostream &outs, Tour t) {
		cout << "\nCost = " << t.mileage << endl;
		for (vector<unsigned int>::iterator it = t.cities.begin();
			it != t.cities.end(); it++) {
			cout << city_names[*it] << endl;
		}
		cout << endl;
		return outs;
	}

private:
	vector<unsigned int> cities;  // Visited cities, in order
	unsigned int mileage; // Total mileage
};