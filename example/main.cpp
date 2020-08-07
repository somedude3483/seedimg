#include <filesystem>
#include <iostream>

#include <seedimg-autodetect/seedimg-autodetect.hpp>
#include <seedimg-filters-core/seedimg-filters-core.hpp>

int main() {
  std::cout << "Current path is " << std::filesystem::current_path()
            << std::endl;
  {
    auto a = seedimg_autodetect_from("violeur.png");
    if (a != std::nullopt) {
      // seedimg::filters::grayscale(*a, true);
      // seedimg::filters::invert(*a);
      bool b = seedimg_autodetect_to("boileur.jpg", *a);
    }
    std::cout << "done" << std::endl;
  }
}
