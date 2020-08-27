#include "secret_handshake.h"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace secret_handshake {
std::map<int, std::string> GESTURES = {
    {1, "wink"},
    {2, "double blink"},
    {4, "close your eyes"},
    {8, "jump"},
};

std::vector<std::string> commands(int input) {
  std::vector<std::string> gestures;
  std::map<int, std::string>::iterator it;

  for (it = GESTURES.begin(); it != GESTURES.end(); it++) {
    if ((it->first & input) == it->first) {
      gestures.push_back(it->second);
    }
  }

  if ((input & 16) == 16) {
    std::reverse(gestures.begin(), gestures.end());
  }

  return gestures;
}
} // namespace secret_handshake
