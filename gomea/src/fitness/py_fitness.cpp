#include "gomea/src/fitness/py_fitness.hpp"

namespace gomea{
namespace fitness{

template<class T>
pyFitnessFunction_t<T>::pyFitnessFunction_t( int number_of_parameters, PyObject *obj ) : customFitnessFunction_t<T>(number_of_parameters)
{
	this->name = "Your own fitness function (Python)";
	this->py_class = obj;
	this->initialize();
}

template<class T>
pyFitnessFunction_t<T>::pyFitnessFunction_t( int number_of_parameters, double vtr, PyObject *obj ) : customFitnessFunction_t<T>(number_of_parameters,vtr)
{
	this->name = "Your own fitness function (Python)";
	this->py_class = obj;
	this->initialize();
}

template<class T>
int pyFitnessFunction_t<T>::getNumberOfSubfunctions()
{
	int number_of_subfunctions = gomea_pyfitness_numberOfSubfunctions(py_class);
	if( number_of_subfunctions == -1 )
		throw std::runtime_error("FitnessFunction does not implement number_of_subfunctions().");
	return number_of_subfunctions;
}

template<class T>
vec_t<int> pyFitnessFunction_t<T>::inputsToSubfunction( int subfunction_index )
{
	vec_t<int> dependencies = gomea_pyfitness_inputsToSubfunction(py_class,subfunction_index);
	if( dependencies.size() == 0 )
		throw std::runtime_error("FitnessFunction does not implement inputsToSubfunction(int).");
	return dependencies;
}

template<>	
double pyFitnessFunction_t<double>::subfunction( int subfunction_index, vec_t<double> &variables )
{
	double subf = gomea_pyfitness_subfunction_realvalued(py_class,subfunction_index,variables);
	if( subf == 1e308 )
		throw std::runtime_error("FitnessFunction does not implement subfunction(int,vector[double]).");
	return subf;
}

template<>	
double pyFitnessFunction_t<char>::subfunction( int subfunction_index, vec_t<char> &variables )
{
	double subf = gomea_pyfitness_subfunction_discrete(py_class,subfunction_index,variables);
	if( subf == 1e308 )
		throw std::runtime_error("FitnessFunction does not implement subfunction(int,vector[char]).");
	return subf;
}

template<class T>
double pyFitnessFunction_t<T>::mappingFunction( int objective_index, vec_t<double> &fitness_buffers )
{
	double result = gomea_pyfitness_mapping_function(py_class,objective_index,fitness_buffers);
	return result;
}

template<class T>
double pyFitnessFunction_t<T>::mappingFunctionConstraintValue( int objective_index, vec_t<double> &fitness_buffers )
{
	double result = gomea_pyfitness_mapping_function_constraint_value(py_class,fitness_buffers);
	return result;
}

template<class T>
double pyFitnessFunction_t<T>::getLowerRangeBound( int dimension )
{
	assert(0);
	return( -1 );
}

template<class T>	
double pyFitnessFunction_t<T>::getUpperRangeBound( int dimension )
{
	assert(0);
	return( -1 );
}

template<>
double pyFitnessFunction_t<double>::getLowerRangeBound( int dimension )
{
	return( -1e308 );
}

template<>	
double pyFitnessFunction_t<double>::getUpperRangeBound( int dimension )
{
	return( 1e308 );
}

}}