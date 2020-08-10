#ifndef SEEDIMG_WEBP_H
#define SEEDIMG_WEBP_H

#include <memory>
#include <optional>
#include <seedimg/seedimg.hpp>

namespace seedimg::modules {
namespace webp {
bool check(const std::string &filename) noexcept;
bool to(const std::string &filename, seedimg::img &inp_img,
        float quality = 100.0);
std::optional<seedimg::img> from(const std::string &filename);
} // namespace webp
} // namespace seedimg::modules

#endif
