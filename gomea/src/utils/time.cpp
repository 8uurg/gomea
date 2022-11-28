#include "gomea/src/utils/time.hpp"

namespace gomea{
namespace utils{

time_t getTimestamp()
{
	return std::chrono::high_resolution_clock::now();
}

long long getElapsedTimeMilliseconds(time_t startTimestamp)
{
    auto timestamp_now = getTimestamp();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timestamp_now - startTimestamp);
	return( diff.count() );
}

double getElapsedTimeSeconds(time_t startTimestamp)
{
	return( getElapsedTimeMilliseconds(startTimestamp) / 1000.0 );
}

}}

