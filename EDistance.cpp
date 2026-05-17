
// Copyright 2026 Aanya Bharti

#include "EDistance.hpp"

#include <algorithm>
#include <sstream>
#include <vector>

EDistance::EDistance(const std::string& x, const std::string& y)
    : _x(x), _y(y) {
    _opt.resize(_x.size() + 1, std::vector<int>(_y.size() + 1, 0));
}

int EDistance::penalty(char a, char b) {
    return (a == b) ? 0 : 1;
}

int EDistance::min3(int a, int b, int c) {
    return std::min({a, b, c});
}

int EDistance::optDistance() {
    int M = _x.size();
    int N = _y.size();

    _opt.assign(M + 1, std::vector<int>(N + 1, 0));

    for (int i = 0; i <= M; i++) {
        _opt[i][0] = 2 * i;
    }
    for (int j = 0; j <= N; j++) {
        _opt[0][j] = 2 * j;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int cost_diag = _opt[i - 1][j - 1] + penalty(_x[i - 1], _y[j - 1]);
            int cost_up = _opt[i - 1][j] + 2;
            int cost_left = _opt[i][j - 1] + 2;

            _opt[i][j] = std::min(cost_diag,
                          std::min(cost_up, cost_left));
        }
    }

    return _opt[M][N];
}

std::string EDistance::alignment() {
    std::ostringstream out;

    int i = _x.size();
    int j = _y.size();

    while (i > 0 || j > 0) {
        int cost = _opt[i][j];

        if (i > 0 && j > 0 &&
            cost == _opt[i - 1][j - 1] + penalty(_x[i - 1], _y[j - 1])) {
            out << _x[i - 1] << " " << _y[j - 1] << " "
                << penalty(_x[i - 1], _y[j - 1]) << "\n";
            i--;
            j--;
        } else if (i > 0 &&
                   cost == _opt[i - 1][j] + 2) {
            out << _x[i - 1] << " - 2\n";
            i--;
        } else {
            out << "- " << _y[j - 1] << " 2\n";
            j--;
        }
    }

    std::string result = out.str();

    std::istringstream iss(result);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(iss, line)) {
        lines.push_back(line);
    }

    std::reverse(lines.begin(), lines.end());

    std::ostringstream final_out;
    for (const auto& l : lines) {
        final_out << l << "\n";
    }

    return final_out.str();
}
