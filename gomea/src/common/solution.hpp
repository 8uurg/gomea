#pragma once

#include "gomea/src/common/gomea_defs.hpp"
#include "gomea/src/common/partial_solution.hpp"

namespace gomea{

template<class T>
class solution_t
{
	public:
		solution_t( int number_of_variables );
		solution_t( vec_t<T> &variables );
		
		vec_t<T> variables;
	
		int getNumberOfVariables() const;
		int getNumberOfObjectives() const;
		double getObjectiveValue() const;
		double getObjectiveValue( int objective_value_index ) const;
		vec_t<double> getObjectiveValues() const;
		double getPartialObjectiveValue( int subfunction_index ) const;
		double getConstraintValue() const;
		double getPartialConstraintValue( int subfunction_index ) const;

		void setObjectiveValue( double v );
		void setObjectiveValue( int objective_value_index, double v );
		void setObjectiveValues( vec_t<double> v );
		void setConstraintValue( double v );
		void setPartialObjectiveValue( int subfunction_index, double v );
		void setPartialConstraintValue( int subfunction_index, double v );

		vec_t<T> createPartialBackup(vec_t<int> variable_indices);
		void insertVariables(vec_t<T> vars_to_insert, vec_t<int> indices_to_insert);
		void insertPartialSolution( partial_solution_t<T> *solution );

		void print();

	private:
		vec_t<double> objective_values;
		vec_t<double> partial_objective_values;
		double constraint_value;
		vec_t<double> partial_constraint_values;
};

template class solution_t<char>;
template class solution_t<int>;
template class solution_t<float>;
template class solution_t<double>;

}
