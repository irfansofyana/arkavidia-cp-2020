#include <tcframe/spec.hpp>

using namespace tcframe;
using namespace std;

typedef long long LL;

const int MAX_N = 100000;
const int MAX_B = 100000;
const int MAX_Q = 100000;

class ProblemSpec : public BaseProblemSpec{
    protected:
        //list of variables 
        int N, Q;
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
            MemoryLimit(64);
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
                    N = rnd.nextInt(1*MAX_N, 1*MAX_N),
                    randomArrayRange(N, arr, 1*MAX_B/5, 1*MAX_B),
                    Q = rnd.nextInt(1*MAX_Q/2, 1*MAX_Q),
                    randomQuery(N,Q,L,R)
                );
            }
            for (int i = 0; i < 4; ++i){
                CASE(
                    N = rnd.nextInt(1*MAX_N, 1*MAX_N),
                    randomArrayRange(N, arr, 1*MAX_B/5, 1*MAX_B),
                    Q = rnd.nextInt(1*MAX_Q, 1*MAX_Q),
                    randomQuery(N,Q,L,R)
                );
            }
            CASE(
                N = rnd.nextInt(1*MAX_N, 1*MAX_N),
                randomArrayRangeGood(N, arr, 1, 1*MAX_B),
                Q = rnd.nextInt(1*MAX_Q, 1*MAX_Q),
                randomQueryGood(N,Q,L,R)
            );
        }
    private: 
        void randomArrayRange(int N, vector<int> & a, int lo, int hi){
            a.clear();
            for (int i = 0; i < N; i++){
                a.push_back(rnd.nextInt(lo, hi));
            }
        }
        void randomArrayRangeGood(int N, vector<int> & a, int lo, int hi){
            a.clear();
            int x = lo;
            for (int i = 0; i < N; i++){
                if (i < N/2) {
                    x = rnd.nextInt(x , hi);
                    a.push_back(x);
                } else {
                    x = rnd.nextInt(lo, hi);
                    a.push_back(x);
                }
            }
        }
        void randomQuery(int N,int Q,vector<int> & L, vector<int> & R){
            int l,r;
            L.clear();
            R.clear();
            for (int i = 0;i<Q;i++){
                l = rnd.nextInt(1,N);
                r = rnd.nextInt(l,N);
                L.push_back(l);
                R.push_back(r);
            }
        }
        void randomQueryGood(int N,int Q,vector<int> & L, vector<int> & R){
            int l,r;
            L.clear();
            R.clear();
            for (int i = 0;i<Q;i++){
                l = rnd.nextInt(1,N/100);
                r = rnd.nextInt(99*N/100,N);
                L.push_back(l);
                R.push_back(r);
            }
        }
};