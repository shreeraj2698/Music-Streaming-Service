

#include "utils/Random.hpp"

namespace Random {

RandGenerator& getRandGenerator()
{
	static thread_local std::random_device rd;
	static thread_local RandGenerator randGenerator(rd());

	return randGenerator;
}

RandGenerator createSeededGenerator(uint_fast32_t seed)
{
	return RandGenerator {seed};
}

} // Random

