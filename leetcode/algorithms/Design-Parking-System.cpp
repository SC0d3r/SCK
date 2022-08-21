#include <iostream>
#include <vector>

const int BIG = 1;
const int MED = 2;
const int SM = 3;

class ParkingSystem
{
public:
	ParkingSystem(int big, int medium, int small) : b(big), m(medium), s(small)
	{
	}

	inline bool addCar(int carType)
	{
		if (carType == BIG && b > 0)
		{
			b--;
			return true;
		}

		if (carType == MED && m > 0)
		{
			m--;
			return true;
		}

		if (carType == SM && s > 0)
		{
			s--;
			return true;
		}

		return false;
	}

private:
	int s;
	int m;
	int b;
};

int main()
{
	ParkingSystem *obj = new ParkingSystem(1, 1, 1);
	bool param_1 = obj->addCar(1);
	return 0;
}