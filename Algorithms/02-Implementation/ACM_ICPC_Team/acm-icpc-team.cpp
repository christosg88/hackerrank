#include <iostream>
#include <vector>

int main() {
  int num_people = 0;
  int num_topics = 0;
  std::cin >> num_people >> num_topics;

  std::vector<std::string> topics(num_people);
  for (std::string &s : topics) {
    std::cin >> s;
  }

  int max_topics = 0;
  int teams_with_max_topics = 0;
  for (auto it1 = topics.begin(); it1 != topics.end(); ++it1) {
    for (auto it2 = std::next(it1, 1); it2 != topics.end(); ++it2) {
      // count the combined topics known
      int topics = 0;
      for (int t = 0; t < num_topics; ++t) {
        if ((*it1)[t] == '1' || (*it2)[t] == '1') {
          ++topics;
        }
      }

      if (topics > max_topics) {
        max_topics = topics;
        teams_with_max_topics = 1;
      } else if (topics == max_topics) {
        ++teams_with_max_topics;
      }
    }
  }

  std::cout << max_topics << "\n";
  std::cout << teams_with_max_topics << "\n";

  return 0;
}

