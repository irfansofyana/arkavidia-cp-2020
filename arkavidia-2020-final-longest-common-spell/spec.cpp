#include <tcframe/spec.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace tcframe;

const int MAXQ = 1e5;

class ProblemSpec: public BaseProblemSpec{
    protected:
        int q;
        vector<int> op;
        vector<string> query_string;

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
        void BeforeTestCase(){

        }

        void TestCases(){

        }

    private:
};