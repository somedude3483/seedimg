#ifndef SEEDIMG_FILTERS_CORE_H
#define SEEDIMG_FILTERS_CORE_H

#include <seedimg/seedimg.hpp>

namespace seedimg::filters {
void grayscale(std::unique_ptr<seedimg::img> &inp_img,
               bool luminosity = true) noexcept;
void invert(std::unique_ptr<seedimg::img> &inp_img) noexcept;
void invert_a(std::unique_ptr<seedimg::img> &inp_img,
              bool invert_alpha_only = false) noexcept;
bool crop(std::unique_ptr<seedimg::img> &inp_img, seedimg::point p1,
          seedimg::point p2) noexcept;
void blur(std::unique_ptr<seedimg::img> &inp_img,
          std::uint8_t blur_level) noexcept;
} // namespace seedimg::filters

#endif
