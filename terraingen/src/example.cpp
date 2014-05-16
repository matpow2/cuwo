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
	int coords = (argc - 2);
    if (coords < 0 || coords % 2 != 0) {
        std::cout << "Usage: gen.exe seed x1 y1 x2 y2 ..." << std::endl;
        return 0;
    }
	int pairs = coords / 2;

    tgen_set_seed(to_int(argv[1]));

    tgen_set_path("../data/");
    tgen_init();
    std::cout << "Generator setup" << std::endl;
	for (int i = 0; i < pairs; i++) {
		int x = to_int(argv[2 + i*2]);
		int y = to_int(argv[3 + i*2]);
		std::cout << "Generating (" << x << ", " << y << ")" << std::endl;
		ChunkData * c = tgen_generate_chunk(x, y);
        std::cout << "Generated." << std::endl;
	}

    std::cout << "Done." << std::endl;

    return 0;
}
