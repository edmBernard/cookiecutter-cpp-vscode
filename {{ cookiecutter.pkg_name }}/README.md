# {{ cookiecutter.project_name }}

- Github : [{{ cookiecutter.github_url }}]({{ cookiecutter.github_url }})

## Dependencies

We use [vcpkg](https://github.com/Microsoft/vcpkg) to manage dependencies

This project depends on:
- [cxxopts](https://github.com/jarro2783/cxxopts): Command line argument parsing
- [fmt](https://fmt.dev/latest/index.html): A modern formatting library
- [spdlog](https://github.com/gabime/spdlog): Very fast, header-only/compiled, C++ logging library


```
./vcpkg install spdlog cxxopts fmt
```

### Compilation

```bash
mkdir build
cd build
# configure make with vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
# on Windows : cmake .. -DCMAKE_TOOLCHAIN_FILE=${env:VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
cmake.exe --build . --config Release
```

the server executable is named `{{ cookiecutter.pkg_name }}`

## Disclaimer

It's a toy project. So if you spot error, improvement comments are welcome.