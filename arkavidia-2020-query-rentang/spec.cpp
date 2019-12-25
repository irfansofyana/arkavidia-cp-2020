#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables

    void InputFormat(){

    }

    void OutputFormat(){

    }

    void GradingConfig(){

    }

    void Constraints(){
        
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){

        }
    private:
};