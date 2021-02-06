//https://stackoverflow.com/questions/59106330/denominate-the-time_amount-with-the-minimum-number-of-myoperator-with-a-given-face-value
#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace  std;

std::vector<int> get_number_of_myoperator(const std::vector<int>& denominations, int time_amount) {
    std::vector<int> myoperator = denominations;
    std::vector<int> n_myoperator(myoperator.size(), 0);
    std::vector<int> n_myoperator_opt(myoperator.size(), 0);
    int n = myoperator.size();
    cout << "myoperator[0]:" << myoperator[0] << endl;
//    cout << "n_myoperator[0]:" << n_myoperator[0] << endl;
//    cout << "n_myoperator_opt[0]:" << n_myoperator_opt[0] << endl;
    std::sort(myoperator.begin(), myoperator.end(), std::greater<int>());
    cout << "myoperator[0]:" << myoperator[0] << endl;

    int sum = 0;    // current sum
    int i = 0;      // index of the coin being examined
    int n_min_myoperator = time_amount / myoperator[n - 1] + 1;
    cout << "n_min_myoperator:" << n_min_myoperator << endl;
    int n_total_myoperator = 0;
    bool up_down = true;

    cout << "Entering into loop" << endl;
    while (true) {          // UP
        cout << "" << endl;
        cout << "" << endl;
        if (up_down) {

            cout << "up_down:true" << endl;
            n_myoperator[i] = (time_amount - sum) / myoperator[i];     // max number of myoperator[i]
            cout << "i:" << i << " n_myoperator[i]:" << n_myoperator[i] << endl;
            sum += n_myoperator[i] * myoperator[i];
            n_total_myoperator += n_myoperator[i];
            cout << "sum:" << sum << " n_total_myoperator: " << n_total_myoperator << endl;
            if (sum == time_amount) {
                cout << "sum == time_amount" << endl;
                if (n_total_myoperator < n_min_myoperator) {
                    n_min_myoperator = n_total_myoperator;
                    n_myoperator_opt = n_myoperator;
                }
                up_down = false;
                sum -= n_myoperator[i] * myoperator[i];
                n_total_myoperator -= n_myoperator[i];
                n_myoperator[i] = 0;
                i--;
            }
            else {
                if (i == (n - 1) || (n_total_myoperator >= n_min_myoperator)) {   // premature abandon
                    cout << "premature abandon" << endl;
                    sum -= n_myoperator[i] * myoperator[i];
                    n_total_myoperator -= n_myoperator[i];
                    n_myoperator[i] = 0;
                    up_down = false;
                    i--;
                }
                else {
                    cout << "i++" << endl;
                    i++;
                }
            }

        }

        else {            // DOWN

            cout << "up_down:false" << endl;
            if (i < 0) break;
            if (n_myoperator[i] == 0) {
                if (i == 0) break;
                i--;
            }
            else {
                sum -= myoperator[i];
                n_myoperator[i] --;
                n_total_myoperator--;
                i++;
                up_down = true;
            }
        }
    }

    std::vector<int> ans;
    cout << (int)myoperator.size() << endl;
    for (int i = 0; i < (int)myoperator.size(); i++)
        for (int j = 0; j < n_myoperator_opt[i]; j++)
            ans.push_back(myoperator[i]);

    return ans;
}

int main() {
    //std::vector<int> myoperator = { 1, 5, 10, 25, 50, 75 };
    //std::vector<int> myoperator = { 1, 5, 10, 25 };
    //std::vector<int> myoperator = { 1, 2, 49, 89, 99, 499 };
    std::vector<int> myoperator = { 2,  499 };
    //std::vector<int> myoperator = {  26,2, 89, 99 };
    //std::vector<int> myoperator = {  5 };
    int time_amount = 500;
    auto n_myoperator = get_number_of_myoperator(myoperator, time_amount);

    for (int i = 0; i < (int)n_myoperator.size(); i++)
            std::cout << n_myoperator[i] << " ";

    std::cout << "\n";
    return 1;
}
