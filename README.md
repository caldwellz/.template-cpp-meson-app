# template-cpp-meson-app
This is a template for MPL2-licensed C/C++ application projects using the Meson build system.
At a bare minimum, you should change or fill in:
* The project name (the empty string at the top of the main meson.build).
* The list of additional source code files (app_srcs in src/meson.build).
* Any library dependencies (app_deps in src/meson.build).
  * A fake "libfoo" dependency is configured there and in subprojects/foo.wrap as an example.
* This ReadMe file (README.md).
