#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string
tournamentWinner(const std::vector<std::vector<std::string>>& competitions,
                 const std::vector<int>& results) {
  std::uint8_t aIndex{};
  std::multimap<std::string, int> aTeamPoints{};
  std::vector<std::string> aTeams{};

  for (const std::vector<std::string>& face : competitions) {
    std::string aHomeTeam = face.at(0);
    std::string aAwayTeam = face.at(1);
    std::uint8_t aFaceResult = results.at(aIndex);

    if (aFaceResult == 1) {
      aTeamPoints.insert({aHomeTeam, 3});
    } else {
      aTeamPoints.insert({aAwayTeam, 3});
    }
    aIndex++;
  }

  for (const std::pair<std::string, int>& aTeamPoint : aTeamPoints) {
    aTeams.push_back(aTeamPoint.first);
  }

  std::size_t aTeamsSize{aTeams.size()};
  std::uint8_t maxcount{};
  std::string aWinnerTeam{};
  for (std::uint8_t i = 0; i < aTeamsSize; ++i) {
    std::uint8_t count{};
    for (std::uint8_t j = 0; j < aTeamsSize; j++) {
      if (aTeams.at(i) == aTeams.at(j))
        count++;
    }
    if (count > maxcount) {
      maxcount = count;
      aWinnerTeam = aTeams.at(i);
    }
  }

  return aWinnerTeam;
}

int main() {
  std::vector<std::vector<std::string>> aCompetitions{
      {"HTML", "Java"}, {"Java", "Python"}, {"Python", "HTML"}};
  std::vector<int> aResults{0, 1, 1};
  auto aResult = tournamentWinner(aCompetitions, aResults);
  std::cout << aResult << std::endl;

  return 0;
}