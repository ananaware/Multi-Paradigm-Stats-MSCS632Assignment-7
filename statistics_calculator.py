from collections import Counter
from typing import List


class StatisticsCalculator:
    """
    Object-oriented implementation of basic statistics on a list of integers.
    Encapsulates the data and the methods to compute mean, median, and mode(s).
    """

    def __init__(self, data: List[int]) -> None:
        if not data:
            raise ValueError("Data list cannot be empty.")
        self.data = data

    def mean(self) -> float:
        return sum(self.data) / len(self.data)

    def median(self) -> float:
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 1:
            return float(sorted_data[mid])
        else:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2.0

    def mode(self) -> List[int]:
        counts = Counter(self.data)
        max_count = max(counts.values())
        # Return all values that have the maximum count
        return [value for value, count in counts.items() if count == max_count]


def main() -> None:
    data = [5, 3, 9, 3, 8, 3, 1, 9]

    calculator = StatisticsCalculator(data)

    print(f"Data: {data}")
    print(f"Mean: {calculator.mean():.3f}")
    print(f"Median: {calculator.median():.3f}")
    print(f"Mode(s): {calculator.mode()}")


if __name__ == "__main__":
    main()
