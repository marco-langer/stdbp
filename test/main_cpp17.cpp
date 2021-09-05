#include "../include/stdbp/cpp17/bit.hpp"
#include "../include/stdbp/cpp17/type_traits.hpp"
#include "../include/stdbp/cpp17/memory.hpp"
#include "../include/stdbp/cpp17/numbers.hpp"

int main() {
//  static_assert(stdbp::is_unbounded_array_v<int[]>);
  auto arr = stdbp::make_unique_for_overwrite<int[]>(20);

  [[maybe_unused]] const auto piAsIntegral = stdbp::bit_cast<std::size_t>(stdbp::numbers::pi);

//  [[maybe_unused]] const auto b = stdbp::is_bounded_array_v<int[5]>;

  return 0;
}
