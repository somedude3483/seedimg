import pathlib

header = """#[[ 
seedimg - module based image manipulation library written in modern C++ 
Copyright (C) 2020 telugu-boy 
 
This program is free software: you can redistribute it and/or modify 
it under the terms of the GNU Lesser General Public License as published by 
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version. 
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU Lesser General Public License for more details. 
 
You should have received a copy of the GNU Lesser General Public License 
along with this program.  If not, see <http://www.gnu.org/licenses/>. 
]]
set(TESTS_EXE tests)

add_executable(${TESTS_EXE} test-filters-core.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_libraries(tests seedimg-filters-core seedimg-filters-ocl seedimg-autodetect)
else()
    target_link_libraries(tests seedimg-filters-core seedimg-filters-ocl seedimg-autodetect stdc++fs)
endif()

target_include_directories(tests PRIVATE "${CMAKE_SOURCE_DIR}/seedimg-filters")
file(COPY test_image.png DESTINATION "${CMAKE_BINARY_DIR}/${TESTS_EXE}/")

include_directories(../)

"""

template = """add_test({}_test ${{TESTS_EXE}} {})
set_tests_properties({}_test PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")\n\n"""

tests = ["grayscale_lum", "grayscale_avg", "invert", "invert_alpha","invert_alpha_only", "crop", "blur", "h_blur", "v_blur", "kernel_convolution", "rotate_hue", "brightness", "brightness_alpha", "blend", "blend_alpha","rotate_cw", "rotate_180", "rotate_ccw", "v_mirror", "h_mirror", "saturation"]

enum_mapping = ["GRAYSCALE_LUM", "GRAYSCALE_AVG", "INVERT", "INVERT_A", "INVERT_AO", "CROP", "BLUR", "H_BLUR", "V_BLUR", "KERNEL_CONVOLUTION", "ROTATE_HUE", "BRIGHTNESS", "BRIGHTNESS_A", "BLEND", "BLEND_A", "ROTATE_CW", "ROTATE_180", "ROTATE_CCW", "V_MIRROR", "H_MIRROR", "SATURATION"]

tests_ocl = ["ROTATE_HUE_OCL", "GRAYSCALE_LUM_OCL", "GRAYSCALE_AVG_OCL"]

enum_mapping_ocl = ["rotate_hue_ocl", "grayscale_lum_ocl", "grayscale_avg_ocl"]

if __name__ == "__main__":
    dirname = str(pathlib.Path(__file__).parent.absolute()) + '/'
    with open(dirname + "CMakeLists.txt", "w") as f:
        f.write(header)
        for test in tests:
            f.write(template.format(test, test, test))
            
    #print enum to stdout
    print("enum class filter_functions {")
    for func in enum_mapping:
        print(f"  {func},")
    print("#ifdef SEEDIMG_OCL")
    for func in enum_mapping_ocl:
        print(f" {func},")
    print("#endif")
    print("};")
    
    print()
    
    #print map to stdout
    print("static const std::unordered_map<std::string, filter_functions> filter_mapping = {")
    for i in range(len(tests)):
        print(f"  {{\"{tests[i]}\", filter_functions::{enum_mapping[i]}}},")
    print("#ifdef SEEDIMG_OCL")
    for i in range(len(tests_ocl)):
        print(f"  {{\"{tests_ocl[i]}\", filter_functions::{enum_mapping_ocl[i]}}},")
    print("#endif")
    print("};")
