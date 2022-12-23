#pragma once

#include <chrono>
#include <exception>
#include "gomea/src/common/gomea_defs.hpp"

namespace gomea{
	namespace utils{

		class customException : public std::exception
		{
			private:
				std::string message;

			public:
				customException(std::string message_) : message(message_) {}
				const char *what() const throw()
				{
					return message.c_str();
				}
		};

	double **matrixMatrixMultiplication( double **matrix0, double **matrix1, int n0, int n1, int n2 );
	double *matrixVectorMultiplication( double **matrix, double *vector, int n0, int n1 );
	double vectorDotProduct( double *vector0, double *vector1, int n0 );

	vec_t<int> getSortedOrder( vec_t<int> &data );

	bool isPowerOfK(int n, int k);

	vec_t<int> randomPermutation( int size );
	double randomRealUniform01();
	int randomInt( int max );

	void initializeRandomNumberGenerator();
	void initializeRandomNumberGenerator( long long seed );

	extern std::mt19937 rng;
	extern long long random_seed;

	}
}

