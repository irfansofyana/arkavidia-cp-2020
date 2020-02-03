#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

typedef long long LL;

const LL MAXL = 1e18;

class ProblemSpec : public BaseProblemSpec{
    protected:
        LL L, Q;
        vector<string> query;

        void InputFormat(){

        }

        void OutputFormat(){

        }

        void GradingConfig(){

        }

        void Constraints(){

        }

    private:

};

class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){
            
        }
    private:
};