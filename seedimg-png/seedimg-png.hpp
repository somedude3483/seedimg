#ifndef SEEDIMG_PNG_H
#define SEEDIMG_PNG_H

#include <seedimg/seedimg.hpp>

namespace seedimg::modules {
namespace png {
bool check(const std::string &filename) noexcept;
bool to(const std::string &filename, seedimg::img &inp_img);
std::optional<seedimg::img> from(const std::string &filename);
} // namespace png
} // namespace seedimg::modules

#endif
