#include <iostream>
#include <vector>

// method 1:
// runtime: 181ms at best run (its kinda slow but uses less memory)

class Range
{
public:
	Range(int _start, int _end) : start(_start), end(_end) {}
	inline bool interfere(int st, int e)
	{
		return (st >= start && st < end) || (e > start && e <= end) || (st <= start && e > start);
	}

private:
	int start;
	int end;
};

class MyCalendar
{
public:
	typedef std::pair<int, int> pair;

	MyCalendar()
	{
	}

	// method 2 using pair instead of using Range class
	// runtime: 113ms faster than using the Range class
	// but still is slow, memory usage is so low
	inline bool book(int start, int end)
	{
		for (const auto p : books)
		{
			if (interfere(p, std::make_pair(start, end)))
				return false;
		}

		books.emplace_back(start, end);
		return true;
	}

	inline bool interfere(const pair &self, const pair &other) const
	{
		const auto st = other.first;
		const auto e = other.second;
		const auto start = self.first;
		const auto end = self.second;
		// first approach
		// return (st >= start && st < end) || (e > start && e <= end) || (st <= start && e > start);

		// alternative approach:
		return std::max(st, start) < std::min(e, end);
	}

	// Uncomment bellow for the method 1:

	// inline bool book1(int start, int end)
	// {
	// 	for (const auto b : books)
	// 	{
	// 		if (b->interfere(start, end))
	// 			return false;
	// 	}

	// 	books.emplace_back(new Range(start, end));
	// 	return true;
	// }

private:
	// std::vector<Range *> books;
	std::vector<pair> books;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main()
{
	MyCalendar mc;
	std::cout << mc.book(10, 20) << std::endl;
	std::cout << mc.book(15, 25) << std::endl;
	std::cout << mc.book(20, 30) << std::endl;
	return 0;
}
