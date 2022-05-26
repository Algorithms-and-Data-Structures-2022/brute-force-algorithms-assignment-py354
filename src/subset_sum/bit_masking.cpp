#include "assignment/subset_sum/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set, mask2indices

namespace assignment {

  std::vector<std::vector<int>> SubsetSumBitMasking::search(const std::vector<int>& set, int target_sum) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    // выделяем память
    auto indices = std::vector<std::vector<int>>();

    // 1. Внешний цикл: пробегаемся по всем битовым маскам от 0..00 до 1..11
    // 2. Внутренний цикл: проверка разрядов битовой маски и генерация подмножества, ассоциирующегося с этой маской
    // 3. Подсчет суммы текущего подмножества, сохранение индексов подмножества с целевой суммой в результат
    // Tips: можно пропустить итерацию, если сумма текущего подмножества стала больше целевой суммы
    for (int i = 0; i < num_subsets; i++) {
      auto subset = std::vector<int>();
      int sum = 0;
      for (int j = 0; j < num_elems; j++) {
        if (is_bit_set(i,j)) {
          subset.push_back(j);
          sum += set[j];
        }
      }
      if (sum == target_sum) {
        indices.push_back(subset);
      }
    }

    return indices;


  }

}  // namespace assignment