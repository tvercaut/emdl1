#include <iomanip>
#include <iostream>
#include <vector>

#include <CLI/CLI.hpp>
#include "utils.hpp"
#include "../emdL1.h"

int main(int argc, char** argv) {
  CLI::App app{"emdl1 CLI sandbox tool"};

  std::size_t dim = 10;
  unsigned int seed1 = 42;
  unsigned int seed2 = 1337;
  int max_iter = 500000;
  bool verbose = false;

  app.add_option("-d,--dim", dim,
                 "Grid extent along each 3D axis (default: 10)");
  app.add_option("--seed1", seed1,
                 "Random seed for first histogram (default: 42)");
  app.add_option("--seed2", seed2,
                 "Random seed for second histogram (default: 1337)");
  app.add_option("--max-iter", max_iter,
                 "Maximum network-simplex iterations for EMD-L1 "
                 "(default: 500000)");
  app.add_flag("-v,--verbose", verbose, "Enable verbose logging");

  CLI11_PARSE(app, argc, argv);

  const std::size_t n_bins = dim * dim * dim;

  std::cout << "Grid shape: " << dim << 'x' << dim << 'x' << dim << " ("
            << n_bins << " bins)\n";

  std::vector<double> h1_data =
      emdgrid::generate_random_histogram<double>(n_bins, seed1);
  std::vector<double> h2_data =
      emdgrid::generate_random_histogram<double>(n_bins, seed2);

  std::cout << std::fixed << std::setprecision(6);

  EmdL1 em;
  em.SetMaxIteration(max_iter);

  const emdgrid::Timer timer;
  const double dist = em.EmdDist(h1_data.data(), h2_data.data(),
                                 static_cast<int>(dim), static_cast<int>(dim), static_cast<int>(dim));
  const double elapsed_ms = timer.elapsed_milliseconds();

  std::cout << "\n--- Exact EMD-L1 ---\n";
  std::cout << "Distance: " << dist << '\n';
  std::cout << "Computation time: " << elapsed_ms << " ms\n";

  if (verbose) {
    std::cout << "Histogram seed 1: " << seed1 << ", seed 2: " << seed2 << '\n';
  }

  return 0;
}
