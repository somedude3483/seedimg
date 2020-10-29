/**********************************************************************
    seedimg - module based image manipulation library written in modern C++
            Copyright(C) 2020 telugu-boy, tripulse

    This program is free software : you can redistribute it and /
    or modify it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation,
    either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
************************************************************************/
#include <iostream>
#include <fstream>

#include <seedimg.hpp>
#include <seedimg-autodetect.hpp>

#include <seedimg-filters/seedimg-filters-core.hpp>

using namespace seedimg;
using namespace seedimg::modules;
using namespace seedimg::filters;

int main() {
    simg img = seedimg::load("jat.ff");

    // will result in a blue-white image.
    sepia_i(img);
    invert_i(img);

    seedimg::save("chamar.ff", img);
}
