#include <iostream>
using namespace std;




class herbivore {
protected:
	int weight;
	bool life;
public:
	herbivore(int w, bool l) : weight(w), life(l) {

	}
	void eatgrass(){
		weight += 10;
	}
	int getweight() {
		return weight;
	}

};

class wildebeest :public herbivore {
public:
	wildebeest(int w, bool l): herbivore(w,l) {}
};

class bison :public herbivore {
public:
	bison(int w, bool l) : herbivore(w, l) {}
};

class carnivore {
protected:
	int strenght;
	bool life;
public:
	carnivore(int s, bool l): strenght(s), life(l){}
	virtual void eat(herbivore& obj) {
		if (strenght >= obj.getweight()) {
			strenght += 10;
		}
		else {
			strenght -= 10;
		}
	}
	virtual void eat() {
		strenght += 10;
	}
};

class lion :public carnivore {
public:
	lion(int s, bool l): carnivore(s,l){}
};

class wolf :public carnivore {
public:
	wolf(int s, bool l) : carnivore(s, l) {}
};

class animalworld {
public:
	void mealsherbivores(herbivore** begin, herbivore** end) {
		for (herbivore** start = begin; start != end; start++)
		{
			(*start)->eatgrass();
		}
	}
	void nutritioncarnivores(carnivore** begin, carnivore** end) {
		for (carnivore** start = begin; start != end; start++)
		{
			(*start)->eat();
		}
	}
};
class continent {
protected:
	herbivore** harr;
	carnivore** carr;
public:
	continent(herbivore** h, carnivore** c) : harr(h), carr(c){}
};

class africa :public continent {
public:

	africa(herbivore** h, carnivore** c) : continent(h,c){}
};

class euroasia :public continent {
public:
	euroasia(herbivore** h, carnivore** c) : continent(h, c) {}
};

class southamerica :public continent {
public:

	southamerica(herbivore** h, carnivore** c) : continent(h, c) {}
};

int main() {
	herbivore* arr[2];
	arr[0] = new wildebeest(50, true);
	arr[1] = new bison(60, true);
	carnivore* arr1[2];
	arr1[0] = new lion(60, true);
	arr1[1] = new wolf(40, true);
	euroasia storage(arr, arr1);
	animalworld a;
	a.mealsherbivores(arr, arr+2);
	a.nutritioncarnivores(arr1, arr1 + 2);
}