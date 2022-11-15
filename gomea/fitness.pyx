from cpython cimport PyObject

include "gomea/EmbeddedFitness.pxi"

cdef class YourFitnessFunctionDiscrete(FitnessFunction):
    def __cinit__(self, 
        number_of_variables : int,
        value_to_reach : double = 0.0
    ):
        self.c_inst_discrete = new yourFitnessFunctionDiscrete(number_of_variables,value_to_reach)

cdef class YourFitnessFunctionRealValued(FitnessFunction):
    def __cinit__(self, 
        number_of_variables : int,
        value_to_reach : double = 0.0
    ):
        self.c_inst_realvalued = new yourFitnessFunctionRealValued(number_of_variables,value_to_reach)

cdef class PythonFitnessFunction(FitnessFunction):
    cpdef number_of_subfunctions( self ):
        return -1
    
    cpdef inputs_to_subfunction( self, int subfunction_index ):
        return np.ndarray()
    
    cpdef subfunction( self, int subfunction_index, np.ndarray variables ):
        return 1e308

cdef class PythonFitnessFunctionDiscrete(PythonFitnessFunction):
    def __cinit__(self, 
        number_of_variables : int
    ):
        self.number_of_variables = number_of_variables
        self.c_inst_discrete = new pyFitnessFunction_t[char](number_of_variables,<PyObject*>self)

cdef class PythonFitnessFunctionRealValued(PythonFitnessFunction):
    def __cinit__(self, 
        number_of_variables : int,
        value_to_reach : double = 0.0
    ):
        self.number_of_variables = number_of_variables
        self.c_inst_realvalued = new pyFitnessFunction_t[double](number_of_variables,value_to_reach,<PyObject*>self)

cdef class SphereFunction(FitnessFunction):
    def __cinit__(self, 
        number_of_variables : int,
        value_to_reach : double = 0.0
    ):
        self.c_inst_realvalued = new sphereFunction_t(number_of_variables,value_to_reach)

cdef class RosenbrockFunction(FitnessFunction):
    def __cinit__(self, 
        number_of_variables : int,
        value_to_reach : double = 0.0
    ):
        self.c_inst_realvalued = new rosenbrockFunction_t(number_of_variables,value_to_reach)

cdef class OneMaxFunction(FitnessFunction):
    def __cinit__(self, 
        number_of_variables : int
    ):
        self.c_inst_discrete = new oneMax_t(number_of_variables)
