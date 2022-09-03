# template-cpp-meson-app
This is a template for MPL2-licensed C/C++ application projects using the Meson build system.

The minimum items you need to change or fill in to build your project are:
* The project name (the empty string at the top of the main meson.build) - used in the output filename and in the product info in the executable itself.
* Any additional source code files (by listing them in app_srcs in src/meson.build).
* Any library dependencies (in app_deps in src/meson.build).
  * A fake "libfoo" dependency is configured there and in subprojects/foo.wrap as an example; change or remove it as needed.

It is optional, but recommended, to also change / fill in:
* This ReadMe file (README.md).
* The publisher name and product description in meson_options.txt
* The product version (as needed) in the top-level meson.build
* Application icon file(s) in src/res/*
