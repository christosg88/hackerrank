#include <iostream>
#include <queue>

int main() {
    int num_queries;
    std::cin >> num_queries;
    std::queue<int> q;

    for (int query = 0; query < num_queries; ++query) {
        int query_type;
        std::cin >> query_type;

        switch (query_type) {
            case 1:
                int val;
                std::cin >> val;
                q.push(val);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                std::cout << q.front() << "\n";
                break;
            default:
                std::cout << "wrong query type!\n";
        }
    }

    return 0;
}
