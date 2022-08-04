from libcpp.string cimport string
from libcpp cimport bool

cdef extern from "discrete_gomea/Config.hpp":
    cdef cppclass Config:
        Config() except +

        int problemIndex, numberOfVariables, maximumNumberOfGOMEAs, IMSsubgenerationFactor, basePopulationSize, maxArchiveSize, maximumNumberOfEvaluations, maximumNumberOfGenerations
        double maximumNumberOfSeconds
        string folder, problemInstancePath

cdef extern from "discrete_gomea/gomeaIMS.hpp":
    cdef cppclass gomeaIMS:
        gomeaIMS() except +
        gomeaIMS(Config*) except +
        
        void run()
        void runGeneration()
        bool checkTermination()
        double getProgressUntilTermination()
