#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXN = 1000000;
const int MAXM = 2000;

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables
        int N, Q;
        vector<int> L, R;
        vector<int> ql, qr;
        vector<int> ans;

    void InputFormat(){
        LINE(N);
        LINES(L, R) % SIZE(N);
        LINE(Q);
        LINES(ql, qr) % SIZE(Q);
    }

    void OutputFormat(){
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig(){
        TimeLimit(1);
        MemoryLimit(32);
    }

    void Constraints(){
        CONS(1 <= N && N <= )
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){

        }
    private:
};