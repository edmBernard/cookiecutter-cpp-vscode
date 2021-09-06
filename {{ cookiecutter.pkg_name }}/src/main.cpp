#include <cxxopts.hpp>
#include <fmt/core.h>
#include <fmt/color.h>
#include <spdlog/spdlog.h>
#include <spdlog/cfg/env.h>


int main(int argc, char *argv[]) try {

  spdlog::cfg::load_env_levels();

  // =================================================================================================
  // CLI
  cxxopts::Options options(argv[0], "Description");
  options.positional_help("[optional args]").show_positional_help();

  // clang-format off
  options.add_options()
    ("h,help", "Print help")
    ;
  // clang-format on
  options.parse_positional({"nruns"});
  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    return EXIT_SUCCESS;
  }

  // =================================================================================================
  // Code
  fmt::print("Hello World!");

  return EXIT_SUCCESS;

} catch (const cxxopts::OptionException &e) {
  spdlog::error("Parsing options : {}", e.what());
  return EXIT_FAILURE;

} catch (const std::exception &e) {
  spdlog::error("{}", e.what());
  return EXIT_FAILURE;

}
