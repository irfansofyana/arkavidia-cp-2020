#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;

typedef long long LL;

const int MAX_N = 100000;
const int MAX_A = 100000;

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables 
        int N, ans;
        vector<int> arr;

        void InputFormat(){
            LINE(N);
            LINE(arr % SIZE(N));
        }

        void OutputFormat(){
            LINE(ans);
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(64);
        }

        void Constraints(){
            CONS(1 <= N && N <= MAX_N);
            CONS(eachElementBetween(arr, 1, MAX_A));
        }

    private:
        bool eachElementBetween(const vector<int>& X, int lo, int hi) {
            for (int x : X) {
                if (x < lo || x > hi) {
                    return false;
                }
            }
            return true;
        }
};


class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){
            for (int i = 0; i < 5; ++i){
                CASE(
                    N = rnd.nextInt(1, MAX_N/100),
                    randomArrayRange(N, arr, 1, 1*MAX_A/5)
                );
            }
            for (int i = 0; i < 5; ++i){
                CASE(
                    N = rnd.nextInt(1, MAX_N/10),
                    randomArrayRange(N, arr, 1, 1*MAX_A/5)
                );
            }
            for (int i = 0; i < 5; ++i){
                CASE(
                    N = rnd.nextInt(1, MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_A)
                );
            }
        }
    private: 
        void randomArrayRange(int N, vector<int> & a, int lo, int hi){
            a.clear();
            for (int i = 0; i < N; i++){
                a.push_back(rnd.nextInt(lo, hi));
            }
        }

};