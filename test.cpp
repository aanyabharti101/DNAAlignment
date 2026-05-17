
// Copyright 2026 Aanya Bharti

#include <cassert>
#include <string>
#include "EDistance.hpp"

int main() {
    assert(EDistance::penalty('A', 'A') == 0);
    assert(EDistance::penalty('A', 'T') == 1);
    assert(EDistance::penalty('G', 'C') == 1);

    assert(EDistance::min3(3, 1, 2) == 1);
    assert(EDistance::min3(5, 5, 5) == 5);
    assert(EDistance::min3(2, 3, 4) == 2);

    EDistance ed1("AAC", "AAC");
    assert(ed1.optDistance() == 0);

    EDistance ed2("A", "T");
    assert(ed2.optDistance() == 1);

    EDistance ed3("A", "");
    assert(ed3.optDistance() == 2);

    EDistance ed4("", "A");
    assert(ed4.optDistance() == 2);

    EDistance ed5("AAA", "TTT");
    assert(ed5.optDistance() == 3);

    EDistance ed6("AGT", "AG");
    assert(ed6.optDistance() == 2);

    std::string align = ed2.alignment();
    assert(!align.empty());

    return 0;
}
