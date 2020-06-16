#include <time.h>

class Timer {
public:
	Timer ();
	~Timer ();

	double start() {
		start = clock();
	}

	double stop() {
		end = clock();
		result = (double)(end - start);

		return result;
	}

private:
	clock_t start, end;
	double result;
};

Timer ::Timer ()
{
}

Timer ::~Timer ()
{
}