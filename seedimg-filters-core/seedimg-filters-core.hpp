/***********************************************************************
seedimg - module based image manipulation library written in modern C++
Copyright (C) 2020 telugu-boy
>>>>>>> 0e78ee85b04d91851ed1bbfb63e529a1f89099f5

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
#ifndef SEEDIMG_FILTERS_CORE_H
#define SEEDIMG_FILTERS_CORE_H

#include <seedimg/seedimg.hpp>

namespace seedimg::filters {
void grayscale(std::unique_ptr<seedimg::img> &inp_img, bool luminosity = true);
void invert(std::unique_ptr<seedimg::img> &inp_img);
void invert_a(std::unique_ptr<seedimg::img> &inp_img,
              bool invert_alpha_only = false);
bool crop(std::unique_ptr<seedimg::img> &inp_img, seedimg::point p1,
          seedimg::point p2) noexcept;

/** Apply a square kernel convolution to an image.
 * NOTE: if weren't a square kernel, the image stays intact.
 * NOTE: alpha is passed-as it is, it's not convoluted.
 */
void blur(std::unique_ptr<seedimg::img> &inp_img, unsigned int blur_level,
          std::uint8_t it = 3);
void h_blur(std::unique_ptr<seedimg::img> &inp_img, unsigned int blur_level,
            std::uint8_t it = 3);
void v_blur(std::unique_ptr<seedimg::img> &inp_img, unsigned int blur_level,
            std::uint8_t it = 3);
void convolution(std::unique_ptr<seedimg::img> &input,
                 std::vector<std::vector<float>> kernel);
} // namespace seedimg::filters

#endif
