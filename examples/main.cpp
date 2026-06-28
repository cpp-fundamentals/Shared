#include "../inc/Shared.hpp"
#include <string>
#include <cassert>

int main()
{
    Shared<int> p1(new int(23));
    assert(*p1 == 23);
    assert(p1.use_count() == 1);
    return 0;
}