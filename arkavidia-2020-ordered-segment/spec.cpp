#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;

typedef long long LL;

const MAX_N = 100000;
const MAX_B = 100000;
const MAX_Q = 2000;

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables 
        int N, K;
        vector<int> arr;
        vector<int> L,R;
        vector<string> ans;

        void InputFormat(){
            LINE(N);
            LINE(arr % SIZE(N));
            LINE(Q);
            LINES(L,R) % SIZE(Q);
        }

        void OutputFormat(){
            LINES(ans) % SIZE(Q);
        }

        void GradingConfig(){
            TimeLimit(1);
            MemoryLimit(256);
        }

        void Constraints(){
            CONS(1 <= N && N <= MAX_N);
            CONS(1 <= Q && Q <= MAX_Q);
            CONS(eachElementBetween(arr, 1, MAX_B));
            CONS(eachElementBetween(L, 1, N));
            CONS(eachElementBetweenLAndN(R, L, N));
        }

    private:
        bool eachElementBetween(const vector<int> &X, int lo, int hi){
            for (int i = 0; i < X.size(); i++){
                if (X[i] < lo || X[i] > hi) return false;
            }
            return true;
        }
        bool eachElementBetweenLAndN(const vector<int> &R, const vector<int> &L,int N){
            for (int i = 0;i < R.size(); i++){
                if (R[i] < L[i] || R[i] > N) return false;
            }
            return true;
        }
};


class TestSpec : public BaseTestSpec<ProblemSpec>{
    protected:
        void TestCases(){
            for (int i = 0; i < 2; ++i){
                CASE(
                    N = rnd.nextInt(1, 1*MAX_N/100),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N/100, 1*MAX_N/10),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N/100, 1*MAX_N/10),
                    randomArrayRange(N, arr, 1*MAX_B/5, 1*MAX_B),
                    Q = rnd.nextInt(1*MAX_Q/5, 1*MAX_Q),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N/10, 1*MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q/5),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N/10, 1*MAX_N),
                    randomArrayRange(N, arr, 1, 1*MAX_B/5),
                    Q = rnd.nextInt(1, 1*MAX_Q),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N/10, 1*MAX_N),
                    randomArrayRange(N, arr, 1*MAX_B/5, 1*MAX_B),
                    Q = rnd.nextInt(1*MAX_Q/5, 1*MAX_Q),
                    randomQuery(N,Q,L,R)
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
        void randomQuery(int N,int Q,vector<int> & L, vector<int> & R){
            L.clear();
            R.clear();
            for (int i = 0;i<Q;i++){
                L.push_back(rnd.nextInt(1,N));
                R.push_back(rnd.nextInt(L,N));
            }
        }
};