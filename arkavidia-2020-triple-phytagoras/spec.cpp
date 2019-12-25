#include <tcframe/spec.hpp>
#include <algorithm>
using namespace tcframe;

typedef long long ll;

const ll MAXN = 1e18;
const ll LIM = 2e6;

class ProblemSpec : public BaseProblemSpec {
protected:
    ll N, ANS;

    void InputFormat() {
        LINE(N);
    }

    void OutputFormat() {
        LINE(ANS);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(isOdd(N));
    }

private:
    bool isOdd(ll x) {
        return (x & 1);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    vector<int> primes;
    int sz_prime;
    vector<bool> isPrime;
    map<int, vector<ll>> bigPrimes; // primes with digit >= 7

    void SampleTestCase1() {
        Input({
            "3"
        });
        Output({
            "1"
        });
    }

    void SampleTestCase2() {
        Input({
            "1"
        });
        Output({
            "0"
        });
    }

    void BeforeTestCase() {
		isPrime.assign(LIM + 1, true);
		isPrime[0] = isPrime[1] = false;
		for (ll i = 2; i <= LIM; i++) {
			if (isPrime[i]) {
				primes.push_back(i);
				for (ll j = i * i; j <= LIM; j += i) {
					isPrime[j] = false;			
                }
			}
		}
        sz_prime = primes.size();

        // bigprimes.org
        bigPrimes[7] = {
            6171719,
            3721489,
            8370673,
            5995783,
            4511359
        };
        bigPrimes[8] = {
            89482979,
            99627313,
            43006319,
            89421169,
            90922369
        };
        bigPrimes[9] = {
            375817009,
            451422523,
            583261711,
            258863287,
            877582847
        };
        bigPrimes[17] = {
            17070066725738647
        };
        // will add more primes later

        for (auto it: bigPrimes) sort(it.second.begin(), it.second.end());
    }

    void TestCases() {
        // generate
        for (int i = 0; i < 5; i++) {
            CASE(N = randomOdd(1, 100));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = randomOdd(101, 1000));
        }
        
        // large nums   
        for (int i = 0; i < 10; i++) {
            CASE(N = randomOdd(1001, MAXN));
        }

        // primes (1 <= p <= 1e6)
        for (int i = 0; i < 5; i++) {
            CASE(N = randomPrime(1, LIM));
        }

        // large primes
        for (int i = 0; i < 3; i++) {
            CASE(N = randomBigPrime(7));
        }
        CASE(N = randomBigPrime(17));

        // mult
        for (int i = 0; i < 3; i++) {
            CASE(N = randomBigPrime(7) * randomBigPrime(8));
        }
        for (int i = 0; i < 3; i++) {
            CASE(N = randomBigPrime(8) * randomBigPrime(8));
        }
        // will add more later

        // max
        CASE(N = MAXN - 1);
    }

private:
    ll getLimit(ll x) {
        return ((x - 2) / 2);
    }

    int randomID(vector<ll> a) {
        return rnd.nextInt(0, a.size() - 1);
    }

    ll randomOdd(ll lo, ll hi) {
        ll num = rnd.nextLongLong(lo, getLimit(hi));
        return (2*num + 1);
    }

    ll randomPrime(ll lo, ll hi) {
        int st = lower_bound(primes.begin(), primes.end(), lo) - primes.begin();
        int en = (upper_bound(primes.begin(), primes.end(), hi) - primes.begin()) - 1;
        int id = 1;
        if (st >= 1 && en < sz_prime) {
            id = rnd.nextInt(st, en);
        }
        return primes[id];
    }

    ll randomBigPrime(int digit) {
        return bigPrimes[digit][randomID(bigPrimes[digit])];
    }
};