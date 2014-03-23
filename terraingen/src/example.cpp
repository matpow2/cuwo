/*
    Copyright (c) Mathias Kaerlev 2013-2014.

    This file is part of cuwo.

    cuwo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cuwo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cuwo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "terraingen.h"
#include <iostream>
#include <sstream>

inline int to_int(const char * in)
{
    int v;
    std::istringstream ss(in);
    ss >> v;
    return v;
}

int main(int argc, const char ** argv)
{
    if (argc != 5) {
        std::cout << "Usage: gen.exe seed x y file" << std::endl;
        return 0;
    }

    tgen_set_seed(to_int(argv[1]));
    int x = to_int(argv[2]);
    int y = to_int(argv[3]);
    const char * file = argv[4];

    tgen_set_path("../data/");
    tgen_init();
    std::cout << "Generator setup" << std::endl;
    ChunkData * c = tgen_generate_chunk(x, y);
    std::cout << "Generated chunk" << std::endl;
    return 0;
}
