#include <unordered_map>
using namespace std;

class TwoSum {
private:
    unordered_map<int, int> frequency;

public:
    TwoSum() = default;

    void add(int number) {
        frequency[number]++;
    }

    bool find(int value) {
        for (const auto& [number, count] : frequency) {
            long long complement = static_cast<long long>(value) - number;

            if (complement < INT_MIN || complement > INT_MAX) {
                continue;
            }

            auto it = frequency.find(static_cast<int>(complement));
            if (it == frequency.end()) {
                continue;
            }

            if (complement == number) {
                if (count >= 2) {
                    return true;
                }
            } else {
                return true;
            }
        }

        return false;
    }
};